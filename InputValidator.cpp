#include "InputValidator.h"

// Get a true integer from the user
int InputValidator::getValidIntInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        //  Check if the input from the user is numeric
        if (cin.fail()) {
            cin.clear(); // Clear remaining erroneous data
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear remaining erroneous data
            cout << "Incorrect input! Please enter a valid integer.\n";
        } else {
            return input;
        }
    }
}

//Get a correct decimal number from the user
double InputValidator::getValidDoubleInput( string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        cin >> input;

        // Check if the input from the user is numeric
        if (cin.fail()) {
            cin.clear(); // Clear error status
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear remaining erroneous data
            cout << "Incorrect entry! Please enter a valid decimal number.\n";
        } else {
            return input;
        }
    }
}

// Get a correct string from the user
string InputValidator::getValidStringInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> ws;  // Clear the gaps
        getline(cin, input);

        if (input.empty()) {
            cout << "Blank entries are not allowed. Please enter a valid text..\n";
        } else {
            return input;
        }
    }
}

//Check the capacity and ensure that it is a valid number
int InputValidator::getValidCapacityInput(int maxCapacity) {
    int capacity;
    while (true) {
        capacity = getValidIntInput("Enter the warehouse capacity: ");

        if (capacity <= 0) {
            cout << "Capacity must be greater than 0. Please enter again.\n";
        } else if (capacity > maxCapacity) {
            cout << "Capacity cannot exceed the maximum value. Maximum capacity:  " << maxCapacity << endl;
        } else {
            return capacity;
        }
    }
}

// Receive a secure order quantity from the user
int InputValidator::getValidOrderQuantity( Warehouse& warehouse,  Product& product) {
    int quantity;
    while (true) {
        quantity = getValidIntInput("Enter the order quantity: ");

        if (quantity <= 0) {
            cout << "Order quantity must be greater than 0.\n";
        } else if (quantity > product.getQuantity()) {
            cout << "Insufficient stock! Available stock: " << product.getQuantity() << endl;
        } else {
            return quantity;
        }
    }
}

// Receive a valid email from the user
string InputValidator::getValidEmailInput() {
    string email;
    while (true) {
        email = getValidStringInput("Enter your email address: ");
        if (email.find('@') != string::npos && email.find('.') != string::npos) {
            return email;
        } else {
            cout << "Invalid e-mail address! Please enter a valid e-mail.\n";
        }
    }
}

// Get a valid password from the user
string InputValidator::getValidPasswordInput() {
    string password;
    while (true) {
        password = getValidStringInput("Enter your password: ");
        if (password.length() < 6) {
            cout << "The password must be at least 6 characters.\n";
        } else {
            return password;
        }
    }
}

