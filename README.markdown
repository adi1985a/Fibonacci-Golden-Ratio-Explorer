# 🌀✨ Fibonacci & Golden Ratio Explorer 📐
_A C++ console application for calculating extensive Fibonacci sequences, exploring the golden ratio, and managing results with file I/O._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📝 Project Description

The **Fibonacci & Golden Ratio Explorer** is an insightful C++ console application designed for the computation and analysis of the Fibonacci sequence and its fascinating connection to the golden ratio (Phi, φ). Users can generate Fibonacci sequences up to a remarkable 100,000 terms, with the application efficiently calculating each number. It also computes an approximation of the golden ratio based on the generated sequence. The program features a colorful user interface for enhanced readability, robust input validation, the ability to save calculation results to a file (`fibonacci_results.txt`), load previous results, and log any operational errors to `fibonacci.log`.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🔢 **Extensive Fibonacci Sequence Calculation**: Generate the Fibonacci sequence for a user-specified number of terms, supporting up to 100,000 numbers.
*   📐 **Golden Ratio Computation**: Calculates an approximation of the golden ratio (φ ≈ 1.6180339887...) by dividing consecutive large Fibonacci numbers. The accuracy improves with longer sequences.
*   💾 **Save & Load Results**:
    *   Save the generated Fibonacci sequence and the calculated golden ratio to a text file (`fibonacci_results.txt`).
    *   Load and display previously saved results from the file.
*   📄 **Error Logging**: Logs any operational errors (e.g., invalid input, file issues) to `fibonacci.log` for troubleshooting.
*   🌈 **Colorful Console Interface**: Utilizes colored text for menus, prompts, and output, making the application more engaging (Windows-specific).
*   ✔️ **Input Validation**: Ensures the user enters a valid number of terms for the Fibonacci sequence (e.g., within the 1 to 100,000 range).
*   📋 **Menu-Driven Operation**: Simple and intuitive menu for accessing all functionalities.

## 🖼️ Screenshots

_Screenshots showcasing the main menu, Fibonacci sequence output, golden ratio calculation, and file content examples._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
</p>

## ⚙️ System Requirements

*   **Operating System**: Windows (due to the use of `windows.h` for console color manipulation and `conio.h` for functions like `_getch()`).
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
    *   *Note: For very large Fibonacci numbers (e.g., approaching the 100,000th term), standard integer types like `long long` might overflow. The implementation might require a BigInt library or a strategy to handle very large numbers if displaying the actual numbers is a feature beyond just counting terms or calculating the ratio.*
*   **No External Custom Header Files Required (as per description)**: Relies on standard C++ libraries and Windows-specific headers. Utility functions for color, etc., are likely part of `main.cpp` or a linked standard library.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Compile the Program**:
    Open a terminal (like Command Prompt or PowerShell) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp -o fibonacci_calculator.exe -static-libgcc -static-libstdc++
    ```
    *(Assuming your main source code file is `main.cpp`)*

4.  **Run the Application**:
    After successful compilation, execute the generated program:
    ```bash
    ./fibonacci_calculator.exe
    ```
    or simply in CMD:
    ```bash
    fibonacci_calculator.exe
    ```

## ▶️ How to Use

Upon launching the application, you will be presented with a main menu. Enter the number corresponding to your desired action:

1.  **Calculate Fibonacci sequence**:
    *   Prompts you to enter the number of Fibonacci terms you wish to calculate (valid range: 1 to 100,000).
    *   Displays the generated sequence (or a summary if too long) and the computed golden ratio.
2.  **Save results to file**:
    *   Saves the most recently calculated Fibonacci sequence and golden ratio to `fibonacci_results.txt`.
3.  **Load previous results**:
    *   Loads and displays the content from `fibonacci_results.txt`.
4.  **Exit**:
    *   Terminates the application.

*Error messages and important events are logged to `fibonacci.log`.*

## 💡 Technical Details & Program Logic

*   **Fibonacci Calculation**: Implements an iterative (or potentially recursive with memoization for smaller N) algorithm to generate Fibonacci numbers. For very large N (up to 100,000), an iterative approach is essential for performance.
    *   *Handling Large Numbers*: If displaying the actual Fibonacci numbers beyond what `unsigned long long` can hold is required, the program would need to use a custom BigInt implementation or library. The description implies calculation and ratio, so it might just store the last few for ratio calculation.
*   **Golden Ratio**: Calculated as F(n) / F(n-1) for large n. The program likely uses the last two computed Fibonacci numbers from the sequence.
*   **Input Validation**: Checks that the requested number of terms is within the supported range (1-100,000).
*   **File I/O**: Uses C++ file streams (`fstream`) to write results to `fibonacci_results.txt` and read from it. Errors are logged to `fibonacci.log`.
*   **Console Manipulation**: Employs Windows-specific functions from `windows.h` (like `SetConsoleTextAttribute`) for colored output and `conio.h` (e.g., `_getch()`) for simple "press any key" prompts.
*   **Random Number Generation (Seeding)**: `srand(time(NULL))` is typically used to seed the random number generator if any part of the program requires randomness (though not explicitly mentioned for Fibonacci calculation itself, it's good practice for other potential features or if utility functions are shared).

## 🤝 Contributing

Contributions to the **Fibonacci & Golden Ratio Explorer** are welcome! If you have ideas for optimizations, additional mathematical explorations (e.g., Lucas numbers), improved large number handling, or UI enhancements:

1.  Fork the repository.
2.  Create a new branch for your feature: `git checkout -b feature/your-math-enhancement`
3.  Implement your changes and commit them: `git commit -m "Feature: Add your math enhancement"`
4.  Push your changes to your branch: `git push origin feature/your-math-enhancement`
5.  Open a Pull Request.

Please ensure your code is well-commented and aligns with the project's existing style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Mathematical Algorithm Enthusiast_

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
🌌 _Exploring the mathematical beauty woven into the fabric of nature._
