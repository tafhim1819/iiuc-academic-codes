#include <iostream>
#include <string>
#include <limits>
using namespace std;

void printMenu();
void generateRightTriangle(int height);
void generatePyramid(int height);
void generateDiamond(int height);
void generateNumberPattern(int height);
void generateCustomPattern(int height);

int main() {
    cout << "=========================================" << endl;
    cout << "          PATTERN GENERATOR              " << endl;
    cout << "=========================================" << endl;
    cout << "This program generates various patterns" << endl;
    cout << "using different types of loop." << endl << endl;

    bool exitProgram = false;
    while (!exitProgram) {
        printMenu();

        int choice;
        cout << "Enter your choice (1-6): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (choice == 6) {
            exitProgram = true;
            cout << "Thank you for using the Pattern Generator!" << endl;
            continue;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
            continue;
        }

        int height;
        cout << "Enter pattern height (1-20): ";
        if (!(cin >> height)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (height < 1 || height > 20) {
            cout << "Invalid height! Please enter a value between 1 and 20." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                generateRightTriangle(height);
                break;
            case 2:
                generatePyramid(height);
                break;
            case 3:
                generateDiamond(height);
                break;
            case 4:
                generateNumberPattern(height);
                break;
            case 5:
                generateCustomPattern(height);
                break;
        }
        cout << endl;
    }
    return 0;
}

void printMenu() {
    cout << "\nSelect a pattern to generate:" << endl;
    cout << "1. Right-angled Triangle (using for loop)" << endl;
    cout << "2. Pyramid (using while loop)" << endl;
    cout << "3. Diamond (using do-while loop)" << endl;
    cout << "4. Number Pattern (using nested loops)" << endl;
    cout << "5. Custom Pattern (combination of loops)" << endl;
    cout << "6. Exit" << endl;
}

// 1. Right-angled triangle using FOR loops
void generateRightTriangle(int height) {
    cout << "\n--- Right-angled Triangle (For loop) ---\n" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// 2. Pyramid using WHILE loops
void generatePyramid(int height) {
    cout << "\n--- Pyramid Pattern (While loop) ---\n" << endl;
    int row = 0;

    while (row < height) {
        int space = 0;
        while (space < height - row - 1) {
            cout << " ";
            space++;
        }

        int star = 0;
        while (star < 2 * row + 1) {
            cout << "*";
            star++;
        }
        cout << endl;
        row++;
    }
}

// 3. Diamond using DO-WHILE loops
void generateDiamond(int height) {
    cout << "\n--- Diamond Pattern (Do-While loop) ---\n" << endl;
    int row = 0;

    // Upper half
    do {
        int space = 0;
        do {
            cout << " ";
            space++;
        } while (space < height - row);

        int star = 0;
        do {
            cout << "* ";
            star++;
        } while (star <= row);
        cout << endl;
        row++;
    } while (row < height);

    // Lower half
    row = height - 2;
    while (row >= 0) {
        int space = 0;
        do {
            cout << " ";
            space++;
        } while (space < height - row);

        int star = 0;
        do {
            cout << "* ";
            star++;
        } while (star <= row);
        cout << endl;
        row--;
    }
}

// 4. Number pattern using NESTED loops
void generateNumberPattern(int height) {
    cout << "\n--- Number Pattern (Nested Loops) ---\n" << endl;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        for (int j = i - 1; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 5. Custom pattern: hollow square (for + continue) and number pyramid (while + for + break)
void generateCustomPattern(int height) {
    cout << "\n--- Custom Pattern (Combined loops) ---\n" << endl;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height; j++) {
            if (i != 1 && i != height && j != 1 && j != height) {
                cout << "  ";
                continue;
            }
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\nAnd another pattern using while and for loops:\n" << endl;

    int i = 1;
    while (i <= height) {
        for (int j = 1; j <= height - i; j++) {
            cout << " ";
        }

        int j = 1;
        while (true) {
            cout << j % 10;
            j++;
            if (j > 2 * i - 1) {
                break;
            }
        }
        cout << endl;
        i++;
    }
}
