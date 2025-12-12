# Classic Minesweeper (C++ & SFML)

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

A fully interactive recreation of the classic Minesweeper game in CLI, built using C++.

## About the Project

The goal was to create a robust game loop, win/loss conditions, OOP, and C++ skils in general.

## Features

* **Recursive Flood Fill:** Automatically clears empty areas when a cell with zero neighbors.
* **State Management:** Cells handle multiple states: Hidden, Revealed, Flagged.
* **Randomized Minefield:** Uses **Mersenne Twister (`std::mt19937`)** to ensure a statistically uniform and unpredictable distribution of mines.

## Controls

| Command | Sintax | Action |
| :--- | :--- | :--- |
| **Reveal** | `r i j` | Opens the cell at the line `i`, column `j`. If it is a bomb, game over |
| **Flag** | `f i j` | Adds or remove a flag at line  `i`, column `j` . |

##  Installation & Setup
###  Prerequisites

* **C++ Compiler**: GCC (`g++`) or Clang supporting **C++17** or higher.
* **Build Tool**: GNU Make.
* **Version Control**: Git.
* **Library**: SFML 2.5+ (Simple and Fast Multimedia Library).

### Installing Dependencies (SFML)

If you don't have SFML installed, run the command corresponding to your Linux distribution:

<details>
<summary><strong>Click to expand installation commands</strong></summary>
| Distribution | Command |
| :--- | :--- |
| **Arch Linux** | `sudo pacman -S sfml` |
| **Fedora** | `sudo dnf install SFML-devel` |
| **Ubuntu/Debian** | `sudo apt-get install libsfml-dev` |
| **macOS (Homebrew)** | `brew install sfml` |
</details>

---

#### 1. Clone the Repository
Open your terminal and clone the project to your local machine:

```bash
git clone https://github.com/carlosvts/minesweeper
cd minesweeper (or the name you gave it)
```

## Build and Run

Once the dependencies are installed and the repository is cloned, follow these steps to compile and execute the project.

### 1. Build the Project
Run the `make` command to compile the C++ source code with SFML linkage (using C++17):

```bash
make
./minesweeper (or the name you gave it)
```
