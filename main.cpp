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
    vector<vector<string>> rules;
    vector<string> permissableActions = {"L", "N", "R"};
    vector<string> bufferTape;
    vector<string> machineDesription;
    //a vector is theoretically infinite????
    vector<string> tapeDescription = {"1", "1", "1"};

    public:
        void setValues(vector<string>, string, string, string, vector<string>, vector<vector<string>>);
        void halt();
        void simulate();

        string returnVar(){
            return rules[1][1];
        }
};

void universalTuringMachine::setValues (vector<string> States, string InitialState, string TerminatingState, string BlankSymbol,
    vector<string> PermissableSymbols, vector<vector<string>> Rules){
    states = States;
    initialState = InitialState;
    terminatingState = TerminatingState;
    blankSymbol = BlankSymbol;
    permissableSymbols = PermissableSymbols;
    rules = Rules;
    }

void universalTuringMachine::halt(){
    for(int x=0; x<tapeDescription.size(); x++){
        cout << tapeDescription[x] << " ";
    }
    cout << endl;
}

void turingMachineSimulator::simulate(){
        string STATE = bufferTape[0];
        string SYMBOL = bufferTape[1];

       for(int x=0; x<rules.size(); x++){
            if(rules[x][0] == STATE && rules[x][1] == SYMBOL){
                   if(rules[x][4] == "halt"){
                        halt();
                   }
            }

       }


}


/*
string simulate(){ //takes in an object?



    }


}
*/



int main() {
    universalTuringMachine test;
    vector<string> state = {"q0", "qf"};
    vector<string> symbols = {"B", "1"};
    vector<vector<string>> rules = {{"q0", "1", "1", "right", "q0"}, {"q0", "B", "1", "stay", "qf"}};
    test.setValues(state, "q0", "qf", "B", symbols, rules);
}
