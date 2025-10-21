#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

/*
  Interactive Math & String Utility Program
  Week 5 – Control Structures II (while, for, do-while, nested loops)

  Menu:
    1) Factorial (while)
    2) Number Pyramid (nested for)
    3) Sum of Even or Odd (do-while)
    4) Reverse a String (while)
    5) Exit
*/

// ----------- Function Prototypes -----------
void showMenu();
int  getMenuChoice();

void factorialCalculator();        // while loop
void numberPyramid();              // nested for loops
void sumEvenOrOdd();               // do-while loop
void reverseStringUtility();       // while loop

// Small helpers for safe input
bool readInt(const string& prompt, int& out);
bool readPositiveInt(const string& prompt, int& out);
void clearInputLine();

// --------------- main ----------------------
int main() {
    bool running = true;
    cout << "========= Interactive Utility Program =========\n";
    while (running) {
        showMenu();
        int choice = getMenuChoice();

        switch (choice) {
            case 1: factorialCalculator();      break;
            case 2: numberPyramid();            break;
            case 3: sumEvenOrOdd();             break;
            case 4: reverseStringUtility();     break;
            case 5:
                cout << "Goodbye! Thanks for using the program.\n";
                running = false;
                break;
            default:
                cout << "Invalid option. Choose 1-5.\n\n";
        }
    }
    return 0;
}

// ------------- Implementations -------------
void showMenu() {
    cout << "\n"
         << "1. Factorial Calculator\n"
         << "2. Number Pyramid\n"
         << "3. Sum of Even or Odd Numbers\n"
         << "4. Reverse a String\n"
         << "5. Exit\n"
         << "==============================================\n";
}

int getMenuChoice() {
    cout << "Enter your choice: ";
    int c;
    if (!(cin >> c)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return c;
}

/* 1) Factorial Calculator (while loop)
   - Prompt for positive integer N
   - Use while loop to compute factorial
   - Show: "Factorial of 5 is: 120"
*/
void factorialCalculator() {
    int n;
    if (!readPositiveInt("Enter a positive integer: ", n)) return;

    // Using 64-bit to keep it simple; note overflow for larger n.
    unsigned long long result = 1ULL;
    int i = 1;

    // while loop requirement
    while (i <= n) {
        result *= static_cast<unsigned long long>(i);
        ++i;
    }

    cout << "Factorial of " << n << " is: " << result << "\n\n";
}

/* 2) Number Pyramid (nested for loops)
   Example for rows=5:
       1
      1 2
     1 2 3
    1 2 3 4
   1 2 3 4 5
*/
void numberPyramid() {
    int rows;
    if (!readPositiveInt("Enter number of rows: ", rows)) return;

    for (int r = 1; r <= rows; ++r) {
        // leading spaces (optional, for centering)
        for (int s = 0; s < rows - r; ++s) cout << " ";
        // numbers 1..r
        for (int c = 1; c <= r; ++c) {
            cout << c;
            if (c < r) cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/* 3) Sum of Even or Odd Numbers (do-while loop)
   - Ask even/odd
   - Ask upper limit N
   - Use do-while to sum 1..N (taking even or odd terms)
   Show: "Sum of even numbers up to 10: 30"
*/
void sumEvenOrOdd() {
    cout << "Choose type (e for even, o for odd): ";
    char type;
    if (!(cin >> type)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\n\n";
        return;
    }
    type = static_cast<char>(tolower(type));
    if (type != 'e' && type != 'o') {
        cout << "Please enter 'e' for even or 'o' for odd.\n\n";
        return;
    }

    int n;
    if (!readPositiveInt("Enter upper limit (N): ", n)) return;

    long long sum = 0;
    int i = 1;

    // do-while requirement
    do {
        bool isEven = (i % 2 == 0);
        if ((type == 'e' && isEven) || (type == 'o' && !isEven)) {
            sum += i;
        }
        ++i;
    } while (i <= n);

    cout << "Sum of " << (type == 'e' ? "even" : "odd")
         << " numbers up to " << n << ": " << sum << "\n\n";
}

/* 4) Reverse a String (while loop)
   Input: "hello" -> Output: "olleh"
*/
void reverseStringUtility() {
    cout << "Enter a string: ";
    // Eat leftover newline before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);

    string reversed;
    reversed.reserve(input.size());

    // while loop requirement
    int i = static_cast<int>(input.size()) - 1;
    while (i >= 0) {
        reversed.push_back(input[static_cast<size_t>(i)]);
        --i;
    }

    cout << "Reversed string: " << reversed << "\n\n";
}

// ----------- Input helpers -----------
bool readInt(const string& prompt, int& out) {
    cout << prompt;
    if (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a whole number.\n\n";
        return false;
    }
    return true;
}

bool readPositiveInt(const string& prompt, int& out) {
    if (!readInt(prompt, out)) return false;
    if (out <= 0) {
        cout << "Please enter a positive integer.\n\n";
        return false;
    }
    return true;
}

void clearInputLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
