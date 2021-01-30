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

  - Create a universal turing mahine class????
  - have a simulate function

    - the tape should be a vector<string>
        - give some dedicated amount of space to the buffer at the start

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

                - nextState()


       - simulate() function outputs the resulting tape after computation (output)
            -



*/
int main() {
    cout <<"hi"<<endl;


}
