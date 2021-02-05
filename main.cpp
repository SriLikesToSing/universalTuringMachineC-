#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include <bits/stdc++.h>
using namespace std;

/*
memory buffer : turing number : tape description
design of program:
  - divide the tape into 3 sections enstead of using 3 separate tapes (prob saves memory and increases efficiecy especially during 5 state busy beaver)
        - wrong????? (1/30/2021)
  - Create a universal turing mahine class????
  - have a simulate function
    - the tape should be a vector<string>
        - give some dedicated amount of space to the buffer at the start
            - the buffer will store the state it is currently in
        - for the 3 tape design (vector<string> or a set):
            - tape for the buffer
            - tape for the machine description (array inside of array?)
            - tape for the tape description (where m's computation is performed)
    - create a universalTuringMachine Class
      - given some input simulate and give an output
           - class variables (strings or long longs)
                - states (array)
                - Initial state
                - Terminating State
                - Blank Symbol
                - tuple of permissable symbols
                - array inside of array of each rule
                - hard code the three permissable actions {L, N, R}
            - init function
                - the input tape
                and class variables
            - functions
                - halt()
                    - return tape
                - nextState()
                    - change tape of memory buffer
                    - change contents of the tape
                - should you also impliment the functions in the paper? *dunno
       - simulate() function outputs the resulting tape after computation (output)
            -
*/

class universalTuringMachine{
    vector<string> states;
    string initialState;
    string terminatingState;
    string blankSymbol;
    vector<string> permissableSymbols;
    vector<vector<string>> machineDescriptionTape;
    vector<string> permissableActions = {"L", "N", "R"};
    string bufferTape[2];
    //a vector is theoretically infinite????
    //vector<string> tapeDescription = {"1", "1", "1"};
    //vector<string> tapeDescription = {};

    long long startIndex = 5000;
    long long endIndex = 10000-1;
    string tapeDescription[10000];



    public:
        void setValues(vector<string>, string, string, string, vector<string>, vector<vector<string>>);
        void halt();
        void simulate();
        void printTape();

        string returnVar(){
            return machineDescriptionTape[1][1];
        }
};

void universalTuringMachine::setValues (vector<string> States, string InitialState, string TerminatingState, string BlankSymbol,
    vector<string> PermissableSymbols, vector<vector<string>> Rules){
    states = States;
    initialState = InitialState;
    terminatingState = TerminatingState;
    blankSymbol = BlankSymbol;
    permissableSymbols = PermissableSymbols;
    machineDescriptionTape = Rules;
    for(int x=0; x<10000; x++){
        tapeDescription[x] = "0";
        }
        /*
    tapeDescription[startIndex] = "1";
    tapeDescription[startIndex+1] = "1";
    tapeDescription[startIndex+2] = "1";
    */
    }

void universalTuringMachine::halt(){
    for(int x=0; x<endIndex; x++){
        cout << tapeDescription[x] << " ";
    }
    cout << endl;
}

void universalTuringMachine::printTape(){
    for(int x=0; x<endIndex; x++){
        cout << tapeDescription[x] << " ";
    }
    cout << endl;
}

void universalTuringMachine::simulate(){
    bool HALT = false;
    long long index = startIndex;
    bufferTape[0] = initialState;
    long long count = 0;
    while(HALT == false){
        printTape();
        for(int x=0; x<machineDescriptionTape.size(); x++){
            if(machineDescriptionTape[x][0] == bufferTape[0] && machineDescriptionTape[x][1] == tapeDescription[index]){
                if(machineDescriptionTape[x][4] == terminatingState){
                    cout << "ITS ENDING BRO" <<endl;
                    cout << machineDescriptionTape[x][1] << endl;
                    tapeDescription[index] = machineDescriptionTape[x][2];
                    halt();
                    HALT = true;
                    break;
                }
                cout << machineDescriptionTape[x][3] << endl;
                bufferTape[0] = machineDescriptionTape[x][4];
                if(machineDescriptionTape[x][3] == "right"){
                    cout << "ITS MOVING RIGHT BRO!"<<endl;
                    cout << tapeDescription[index] << endl;
                    tapeDescription[index] = machineDescriptionTape[x][2];
                    index++;
                    break;
                }else if(machineDescriptionTape[x][3] == "left"){
                    cout << "ITS MOVING LEFT BRO!"<<endl;
                    tapeDescription[index] = machineDescriptionTape[x][2];
                    index--;
                    break;
                }else if(machineDescriptionTape[x][3] == "stay"){
                    cout << "lol"<<endl;
                    tapeDescription[index] = machineDescriptionTape[x][2];
                    break;
                }
            }
        }
        count++;
    }
}
/*
kororo = crying
maitei = greeting
karu = eating
mo ai = wll not
ma = were not, was
akaruma = I was not eating
ojupita =
*/


int main() {

    // Simple incrementer Turing machine
    /*
    universalTuringMachine test;
    vector<string> state = {"q0", "qf"};
    vector<string> symbols = {"0", "1"};
    vector<vector<string>> rules = {{"q0", "1", "1", "right", "q0"}, {"q0", "0", "1", "stay", "qf"}};
    test.setValues(state, "q0", "qf", "0", symbols, rules);
    test.simulate();
    */

    // 3-State Busy Beaver turing machine
    /*
    universalTuringMachine threeStateBusyBeaver;
    vector<string> state = {"a", "b", "c", "halt"};
    vector<string> symbols = {"0", "1"};
    vector<vector<string>> rules = {{"a", "0", "1", "right", "b"}, {"a", "1", "1", "left", "c"}, {"b", "0", "1", "left", "a"},
    {"b", "1", "1", "right", "b"}, {"c", "0", "1", "left", "b"}, {"c", "1", "1", "stay", "halt"}};
    threeStateBusyBeaver.setValues(state, "a", "halt", "0", symbols, rules);
    threeStateBusyBeaver.simulate();
    */

    // 5-state, 2-symbol probable Busy Beaver machine from wikipedia
    universalTuringMachine fiveStateTwoSymbolBusyBeaver;
    vector<string> state = {"A", "B", "C", "D", "E", "H"};
    vector<string> symbols = {"0", "1"};
    vector<vector<string>> rules = {{"A", "0", "1", "right", "B"}, {"A", "1", "1", "left", "C"}, {"B", "0", "1", "right", "C"},
    {"B", "1", "1", "right", "B"}, {"C", "0", "1", "right", "D"}, {"C", "1", "0", "left", "E"}, {"D", "0", "1", "left", "A"},
    {"D", "1", "1", "left", "D"}, {"E", "0", "1", "stay", "H"}, {"E", "1", "0", "left", "A"}};
    fiveStateTwoSymbolBusyBeaver.setValues(state, "A", "H", "0", symbols, rules);
    fiveStateTwoSymbolBusyBeaver.simulate();





}
