# Universal Turing Machine Simulator

<img src="https://github.com/SriLikesToSing/universalTuringMachineC-/blob/main/turing.gif" width="500" height="200">

Welcome to the Universal Turing Machine (UTM) Simulator. This program allows you to simulate the behavior of a Turing machine based on a given machine description.
A fully functional 3 tape universal turing machine written from scratch in C++. Very useful to solve or approximate Busy Beaver puzzle lol.

## Introduction

- [A Primer on Turing Machines and The Busy Beaver Problem](https://math.mit.edu/research/highschool/primes/circle/documents/2022/Esther%20&%20Sarah.pdf)

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Prerequisites

Before running the UTM Simulator, make sure you have the following prerequisites installed on your system:

- C++ Compiler (e.g., g++)
- Code Editor or IDE (e.g., Visual Studio Code, Dev-C++, or any other C++ development environment)

## Installation

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/SriLikesToSing/universalTuringMachineC-
   ```
   Navigate to the project directory:

   ```bash
   cd universalTuringMachineC-
   ```
   Compile the program using your C++ compiler:
   ```bash
   g++ main.cpp -o turing_machine_simulator
   ```
## Usage

   To run the UTM Simulator, use the following command:

   ```bash
   ./turing_machine_simulator
   ```
   This will execute the program and simulate the behavior of the Turing machine based on the provided machine description.

## Examples

   The program includes examples of Turing machines that you can simulate. Uncomment the example you want to run in the main function of the main.cpp file.

   # Simple Incrementer Turing Machine
   ```bash
   universalTuringMachine test;
   vector<string> state = {"q0", "qf"};
   vector<string> symbols = {"0", "1"};
   vector<vector<string>> rules = {{"q0", "1", "1", "right", "q0"}, {"q0", "0", "1", "stay", "qf"}};
   test.setValues(state, "q0", "qf", "0", symbols, rules);
   test.simulate();
   ```

   # 3-State Busy Beaver Turing Machine
   ```bash
   universalTuringMachine threeStateBusyBeaver;
   vector<string> state = {"a", "b", "c", "halt"};
   vector<string> symbols = {"0", "1"};
   vector<vector<string>> rules = {{"a", "0", "1", "right", "b"}, {"a", "1", "1", "left", "c"}, {"b", "0", "1", "left", "a"},
   {"b", "1", "1", "right", "b"}, {"c", "0", "1", "left", "b"}, {"c", "1", "1", "stay", "halt"}};
   threeStateBusyBeaver.setValues(state, "a", "halt", "0", symbols, rules);
   threeStateBusyBeaver.simulate();
   ```

   # 5-State, 2-Symbol Probable Busy Beaver Turing Machine
-  The interesting part about this is that it does not have a computable answer that is within the bounds of a normal computers memory size, only a bound that is really large. 
   ```bash
   universalTuringMachine fiveStateTwoSymbolBusyBeaver;
   vector<string> state = {"A", "B", "C", "D", "E", "H"};
   vector<string> symbols = {"0", "1"};
   vector<vector<string>> rules = {{"A", "0", "1", "right", "B"}, {"A", "1", "1", "left", "C"}, {"B", "0", "1", "right", "C"},
   {"B", "1", "1", "right", "B"}, {"C", "0", "1", "right", "D"}, {"C", "1", "0", "left", "E"}, {"D", "0", "1", "left", "A"},
   {"D", "1", "1", "left", "D"}, {"E", "0", "1", "stay", "H"}, {"E", "1", "0", "left", "A"}};
   fiveStateTwoSymbolBusyBeaver.setValues(state, "A", "H", "0", symbols, rules);
   fiveStateTwoSymbolBusyBeaver.simulate();
   ```

Feel free to uncomment and run any of the provided examples or create your own Turing machine configurations for simulation.


   

   

