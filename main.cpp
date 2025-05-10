#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

// Color constants
const int WHITE = 7;
const int CYAN = 11;
const int YELLOW = 14;
const int LIGHT_RED = 12;

class Logger {
private:
    ofstream logFile;
public:
    Logger() {
        logFile.open("fibonacci.log", ios::app);
    }
    
    void log(const string& message) {
        logFile << "[" << __DATE__ << " " << __TIME__ << "] " << message << endl;
    }
    
    ~Logger() {
        logFile.close();
    }
};

class Fib {
private:
    long double liczba_fib[100000];
    Logger logger;
    
public:
    int n;

    void displayHeader() {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
        cout << "************************************************\n";
        cout << "*     Fibonacci Sequence Calculator v2.0         *\n";
        cout << "*     Created by: Adrian Lesniak                *\n";
        cout << "************************************************\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        cout << "Program features:\n";
        cout << "1. Calculate Fibonacci numbers\n";
        cout << "2. Display golden ratio\n";
        cout << "3. Save results to file\n";
        cout << "4. Load previous calculations\n\n";
    }

    void displayMenu() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
        cout << "\n=== MENU ===\n";
        cout << "1. Calculate Fibonacci sequence\n";
        cout << "2. Save results to file\n";
        cout << "3. Load previous results\n";
        cout << "4. Exit\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }

    void ile() {
        try {
            cout << "Enter how many Fibonacci numbers (1-100000): ";
            cin >> n;
            if (n <= 0 || n > 100000) {
                throw out_of_range("Invalid input range");
            }
        } catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
            cout << "Error: Please enter a number between 1 and 100000\n";
            n = 0;
        }
    }

    void wypisz() {
        liczba_fib[0]=1;
        liczba_fib[1]=1;

        for (int i=2 ; i < n ; i++)
        {
            liczba_fib[i] = liczba_fib[i-1] + liczba_fib[i-2] ;
        }

        cout <<setprecision(100000);
    }

    void ktory() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
        for (int i=0 ; i < n; i++)
        {
            cout << "\nCount:" << i+1 << ": " << liczba_fib[i] ;
        }

        cout << endl << "\nCount:"<< n << " is number: " << liczba_fib[n-1];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }

    void zlota() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
        cout << "\nGolden ratio: " << liczba_fib[n-1]/liczba_fib[n-2] << endl;
        cout << "The higher the count, the more accurate the golden ratio." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }

    void saveToFile() {
        ofstream file("fibonacci_results.txt");
        file << "Fibonacci Sequence (n=" << n << ")\n";
        for (int i = 0; i < n; i++) {
            file << i+1 << ": " << fixed << setprecision(0) << liczba_fib[i] << endl;
        }
        file.close();
        cout << "\nResults saved to fibonacci_results.txt\n";
    }

    void loadFromFile() {
        ifstream file("fibonacci_results.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "No previous results found.\n";
        }
    }
};

int main() {
    Fib calculator;
    int choice;

    while (true) {
        calculator.displayHeader();
        calculator.displayMenu();
        
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        system("cls");
        calculator.displayHeader();

        switch (choice) {
            case 1:
                calculator.ile();
                if (calculator.n > 0) {
                    calculator.wypisz();
                    calculator.ktory();
                    calculator.zlota();
                }
                break;
            case 2:
                calculator.saveToFile();
                break;
            case 3:
                calculator.loadFromFile();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nPress any key to return to menu...";
        _getch();
        system("cls");
    }

    return 0;
}
