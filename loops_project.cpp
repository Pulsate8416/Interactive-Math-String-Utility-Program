#include <iostream>
#include <string>
#include <limits>

// Function prototypes
void displayMenu();
void factorialCalculator();
void numberPyramid();
void sumEvenOddNumbers();
void reverseString();
void clearInputBuffer();

int main() {
    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        std::cout << std::endl;

        switch (choice) {
            case 1: factorialCalculator(); break;
            case 2: numberPyramid(); break;
            case 3: sumEvenOddNumbers(); break;
            case 4: reverseString(); break;
            case 5:
                std::cout << "Thank you for using the Interactive Utility Program. Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        if (running) {
            std::cout << "\nPress Enter to continue...";
            clearInputBuffer();
            std::cin.get();
            std::cout << std::endl;
        }
    }
    return 0;
}

void displayMenu() {
    std::cout << "========= Interactive Utility Program =========\n"
              << "========= Jeffrey Davis               =========\n"
              << "========= Professor Whiteley          =========\n"
              << "===============================================\n"
              << "1. Factorial Calculator\n"
              << "2. Number Pyramid\n"
              << "3. Sum of Even or Odd Numbers\n"
              << "4. Reverse a String\n"
              << "5. Exit\n"
              << "==============================================\n";
}
// // professor wants a while loop implementation
void factorialCalculator() {
    int n;
    unsigned long long factorial = 1;

    std::cout << "=== Factorial Calculator ===\n"
              << "Enter a positive integer: ";

    while (!(std::cin >> n) || n < 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        clearInputBuffer();
    }

    int i = 1;
    while (i <= n) {
        if (factorial > std::numeric_limits<unsigned long long>::max() / i) {
            std::cout << "Overflow! The result is too large to calculate.\n";
            return;
        }
        factorial *= i++;
    }

    std::cout << "Factorial of " << n << " is: " << factorial << std::endl;
}
// nested for loops
// delete this later: what is the maximum rows this will print before the OS freezes up?
void numberPyramid() {
    int rows;

    std::cout << "=== Number Pyramid ===\n"
              << "Enter the number of rows: ";

    while (!(std::cin >> rows) || rows <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        clearInputBuffer();
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++)
            std::cout << " ";

        for (int j = 1; j <= i; j++) {
            std::cout << j;
            if (j < i) std::cout << " ";
        }
        std::cout << std::endl;
    }
}


// professor wants a do-while loop implementation
void sumEvenOddNumbers() {
    int choice, limit, sum = 0;

    std::cout << "=== Sum of Even or Odd Numbers ===\n"
              << "1. Sum of Even Numbers\n"
              << "2. Sum of Odd Numbers\n"
              << "Enter your choice (1 or 2): ";

    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Invalid input. Please enter 1 or 2: ";
        clearInputBuffer();
    }

    std::cout << "Enter the upper limit: ";

    while (!(std::cin >> limit) || limit <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        clearInputBuffer();
    }

    int i = (choice == 1) ? 2 : 1;

    do {
        sum += i;
        i += 2;
    } while (i <= limit);

    std::cout << "Sum of " << (choice == 1 ? "even" : "odd") << " numbers up to "
              << limit << ": " << sum << std::endl;
}
// professor wants a while loop implementation
void reverseString() {
    std::string input;

    std::cout << "=== Reverse a String ===\n"
              << "Enter a string: ";
    clearInputBuffer();
    std::getline(std::cin, input);

    std::string reversed;
    int i = input.length() - 1;

    while (i >= 0)
        reversed += input[i--];

    std::cout << "Reversed string: " << reversed << std::endl;
}
// EXTRA CREDIT FUNC
// function to clerar buffer and prevent a slew of errors
//
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
