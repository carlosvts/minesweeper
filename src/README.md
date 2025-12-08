# CLI Minesweeper

A command-line application game simulation of Minesweeper built in C++. This project was developed with the primary purpose of studying and applying **Object-Oriented Programming (OOP)** concepts.

## Features

* **Dynamic Map:** The user can choose the grid layout (rows and columns) at runtime.
* **Object-Oriented Design:** Code structured with modular classes (`Board`, `Cell`).
* **Robust Randomization:** Uses the **Mersenne Twister** engine (`std::mt19937`) for uniform mine distribution.
* **Recursion:** Uses recursion to check the table and reveal the cells of the map

## Controls
The game accepts commands via standard input using the format: `<Action> <Row> <Column>`.

* **`r` (Reveal):** Uncovers a cell. Example: r 5 3 (where i = 5 and j = 3)
* **`f` (Flag):** Marks/Unmarks a cell as a potential mine. Example f 2 5 (where i = 2 and j = 5)

## Difficulty Levels

When running the game, you must select a difficulty ID (0-4). This determines the density of mines on the board:

| ID | Difficulty | Mine Density |
|:--:|:-----------|:------------:|
| 0  | Easy       | 10%          |
| 1  | Medium     | 15%          |
| 2  | Hard       | 20%          |
| 3  | Overkill   | 27%          |
| 4  | Impossible | 40%          |

## How to Build and Run
### Prerequisites

You need a C++ compiler (like `g++`) and `make` installed on your system.


### Compilation

This project includes a `Makefile` to simplify the build process. Just open your terminal in the project folder and run:

```bash
make
