#include <iostream>
#include <cmath>    // For mathematical functions like sqrt(), pow(), etc.
#include <limits>   // For numeric_limits
#include <iomanip>  // For output formatting

using namespace std;

// Function to get a valid double input from the user
double getValidDoubleInput(const string& prompt) {
    double value;
    bool validInput = false;

    do {
        cout << prompt;
        if (cin >> value) {
            validInput = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
        }
    } while (!validInput);

    return value;
}

// Function to get a valid integer input from the user
int getValidIntInput(const string& prompt) {
    int value;
    bool validInput = false;

    do {
        cout << prompt;
        if (cin >> value) {
            validInput = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a whole number." << endl;
        }
    } while (!validInput);

    return value;
}

// Function to check if user wants to use previous result
bool checkUsePreviousResult(double& num, double lastResult, bool hasPreviousResult) {
    if (hasPreviousResult) {
        cout << "Previous result: " << lastResult << endl;
        cout << "Would you like to use the previous result? (1 for yes, 0 for no): ";
        int useLastResult;
        cin >> useLastResult;

        if (useLastResult == 1) {
            num = lastResult;
            return true;
        }
    }
    return false;
}

int main() {
    // Display a welcome message
    cout << "=======================================" << endl;
    cout << "       INTERACTIVE CALCULATOR          " << endl;
    cout << "=======================================" << endl;
    cout << "This calculator allows you to perform" << endl;
    cout << "various mathematical operations." << endl << endl;

    bool exitProgram = false;  // Controls whether the program should exit
    int choice;                // Stores the user's menu choice

    // Variables to store the last calculation result
    double lastResult = 0;
    bool hasPreviousResult = false;

    // Set output precision for floating-point numbers
    cout << fixed << setprecision(4);

    while (!exitProgram) {
        // Display the menu
        cout << "\nPlease select an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Square Root" << endl;
        cout << "6. Exponentiation (Power)" << endl;
        cout << "7. Exit" << endl;
        cout << "8. Remainder (Modulo)" << endl;
        cout << "9. Absolute Value" << endl;

        cout << "\nEnter your choice (1-9): ";

        // Get the user's choice with validation
        if (!(cin >> choice)) {
            // If input is not a number, clear the error state and discard the input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;  // Skip the rest of the loop and start over
        }

        // Variables to store the operands
        double num1, num2, result;

        // Process the user's choice using a switch statement
        switch (choice) {
            case 1:  // Addition
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter first number: ");
                }

                num2 = getValidDoubleInput("Enter second number: ");

                // Calculate and display the result
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;

                // Store the result for potential future use
                lastResult = result;
                hasPreviousResult = true;
                break;

            case 2:  // Subtraction
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter first number: ");
                }

                num2 = getValidDoubleInput("Enter second number: ");

                // Calculate and display the result
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;

                // Store the result for potential future use
                lastResult = result;
                hasPreviousResult = true;
                break;

            case 3:  // Multiplication
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter first number: ");
                }

                num2 = getValidDoubleInput("Enter second number: ");

                // Calculate and display the result
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;

                // Store the result for potential future use
                lastResult = result;
                hasPreviousResult = true;
                break;

            case 4:  // Division
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter numerator: ");
                }

                num2 = getValidDoubleInput("Enter denominator: ");

                // Check for division by zero
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    // Calculate and display the result
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;

                    // Store the result for potential future use
                    lastResult = result;
                    hasPreviousResult = true;
                }
                break;

            case 5:  // Square Root
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter a number: ");
                }

                // Check if the number is negative
                if (num1 < 0) {
                    cout << "Error: Cannot calculate square root of a negative number." << endl;
                } else {
                    // Calculate and display the result
                    result = sqrt(num1);
                    cout << "Result: sqrt(" << num1 << ") = " << result << endl;

                    // Store the result for potential future use
                    lastResult = result;
                    hasPreviousResult = true;
                }
                break;

            case 6:  // Exponentiation
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter base: ");
                }

                num2 = getValidDoubleInput("Enter exponent: ");

                // Calculate and display the result
                result = pow(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;

                // Store the result for potential future use
                lastResult = result;
                hasPreviousResult = true;
                break;

            case 7:  // Exit
                exitProgram = true;
                cout << "Thank you for using the Interactive Calculator. Goodbye!" << endl;
                break;

            case 8:  // Remainder (Modulo)
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter dividend: ");
                }

                num2 = getValidDoubleInput("Enter divisor: ");

                // Check for division by zero
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    // Calculate and display the result
                    // Note: Modulo requires integers, so we cast to int
                    result = static_cast<int>(num1) % static_cast<int>(num2);
                    cout << "Result: " << static_cast<int>(num1) << " % " << static_cast<int>(num2) << " = " << result << endl;
                    cout << "Note: Values were converted to integers for modulo operation." << endl;

                    // Store the result for potential future use
                    lastResult = result;
                    hasPreviousResult = true;
                }
                break;

            case 9:  // Absolute Value
                // Check if user wants to use previous result
                if (!checkUsePreviousResult(num1, lastResult, hasPreviousResult)) {
                    num1 = getValidDoubleInput("Enter a number: ");
                }

                // Calculate and display the result
                result = abs(num1);
                cout << "Result: |" << num1 << "| = " << result << endl;

                  // Store the result for potential future use
                lastResult = result;
                hasPreviousResult = true;
                break;

            default:  // Invalid choice
                cout << "Invalid choice! Please enter a number between 1 and 9." << endl;
                break;
        }  // End of switch statement
    }      // End of while loop

    return 0;
}  // End of main function
