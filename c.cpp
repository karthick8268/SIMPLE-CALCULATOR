#include <iostream>
#include <limits>
using namespace std;

int main()
{
    double a, b, result;
    int choice;
    char again;

    do
    {
        // Display the calculator menu
        cout << "\n===== SIMPLE CALCULATOR =====\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        // Validate the menu input
        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Exit the calculator
        if (choice == 5)
        {
            cout << "Thank you for using the calculator!\n";
            break;
        }

        // Check whether the menu choice is valid
        if (choice < 1 || choice > 4)
        {
            cout << "Invalid choice! Please select 1 to 5.\n";
            continue;
        }

        // Get the two numbers
        cout << "Enter first number: ";
        if (!(cin >> a))
        {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter second number: ";
        if (!(cin >> b))
        {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Perform the selected arithmetic operation
        if (choice == 1)
        {
            result = a + b;
            cout << "Result = " << result << '\n';
        }
        else if (choice == 2)
        {
            result = a - b;
            cout << "Result = " << result << '\n';
        }
        else if (choice == 3)
        {
            result = a * b;
            cout << "Result = " << result << '\n';
        }
        else if (choice == 4)
        {
            // Prevent division by zero
            if (b == 0)
            {
                cout << "Error: Division by zero is not allowed!\n";
            }
            else
            {
                result = a / b;
                cout << "Result = " << result << '\n';
            }
        }

        // Ask whether the user wants another calculation
        cout << "Do you want to calculate again? (y/n): ";
        cin >> again;

        if (again != 'y' && again != 'Y' &&
            again != 'n' && again != 'N')
        {
            cout << "Invalid input. Exiting calculator.\n";
            break;
        }

    } while (again == 'y' || again == 'Y');

    cout << "Calculator closed.\n";

    return 0;
}