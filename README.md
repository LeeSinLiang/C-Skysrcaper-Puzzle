# Skyscraper Puzzle Solver

<p align="center">
	<img src="pictures\skyscraper.PNG" width=30% height=30% />
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/LeeSinLiang/C-Skysrcaper-Puzzle.svg?style=flat-square" alt="license"/>
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/LeeSinLiang/C-Skysrcaper-Puzzle?color=blue&style=flat-square" />
</p>

This is a solver for the Skyscraper Puzzle, which is a logic puzzle that involves a grid of buildings with varying heights. The objective of the puzzle is to determine the heights of the buildings in each row and column, based on the clues given on the edges of the grid.

## Puzzle Rules

The rules of the puzzle are as follows:

- The grid is a square with a size of N x N.
- Each cell in the grid represents a building, and its value represents the height of the building.
- The buildings in each row and column must have different heights.
- The clues on the edges of the grid indicate how many buildings can be seen from that direction. A building can be seen if its height is greater than the heights of the buildings in front of it in that direction.

## Usage

To use this solver, follow these steps:

1. Run `gcc -Wall -Wextra -Werror main.c grid.c print.c solve.c valid.c -o skyscraper` in terminal.
2. Run `./skyscraper 'UpFirst UpSecond UpThird UpFourth DownFirst DownSecond DownThird DownFourth LeftFirst LeftSecond LeftThird LeftFourth RightFirst RightSecond RightThird RightFourth'`
3. Enjoy!

## Algorithm
This solver uses a backtracking algorithm to find the solution to the puzzle. The algorithm works by iterating through each cell in the grid, and attempting to fill it with a valid value. If there are no valid values for a cell, the algorithm backtracks to the previous cell and tries a different value.

## Note
The current solver only supports 4x4 grid. For NxN grid, dynamic programming approach is not implemented yet.
