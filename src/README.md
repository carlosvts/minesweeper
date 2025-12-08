# CLI Minesweeper

A command-line application game simulation of Minesweeper built in C++. This project was developed with the primary purpose of studying and applying **Object-Oriented Programming (OOP)** concepts.

## Features

* **Dynamic Map:** The user can choose the grid layout (rows and columns) at runtime.
* **Object-Oriented Design:** Code structured with modular classes (`Board`, `Cell`).
* **Robust Randomization:** Uses the **Mersenne Twister** engine (`std::mt19937`) for uniform mine distribution.
* **Recursion:** Uses recursion to check the table and reveal the cells of the map

## How to Build and Run

### Prerequisites

You need a C++ compiler (like `g++`) and `make` installed on your system.

### Compilation

This project includes a `Makefile` to simplify the build process. Just open your terminal in the project folder and run:

```bash
make
