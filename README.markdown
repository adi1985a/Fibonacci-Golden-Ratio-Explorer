# Fibonacci Sequence Calculator

## Description
A C++ console application for calculating Fibonacci numbers, computing the golden ratio, and saving/loading results. Features a colorful interface, error logging, and input validation for up to 100,000 numbers. Created by Adrian Lesniak.

## Features
- Calculate Fibonacci sequence
- Compute golden ratio
- Save results to `fibonacci_results.txt`
- Load previous results
- Log errors to `fibonacci.log`
- Colorful console interface

## Requirements
- C++ compiler (e.g., g++)
- Windows OS (uses `windows.h` and `conio.h`)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Compile the program:
   ```bash
   g++ main.cpp -o fibonacci_calculator
   ```

## Usage
1. Run the program:
   ```bash
   ./fibonacci_calculator
   ```
2. Choose options 1-4 from the menu:
   - 1: Calculate Fibonacci sequence (enter number of terms, 1-100,000)
   - 2: Save results to file
   - 3: Load previous results
   - 4: Exit
3. Results are saved to `fibonacci_results.txt`, errors to `fibonacci.log`.

## Notes
- Supports sequences up to 100,000 numbers with input validation.
- Golden ratio accuracy improves with larger sequences.
- Uses Windows-specific console functions for color and keypress handling.

## Author
Adrian Lesniak

## License
MIT License