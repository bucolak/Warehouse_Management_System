#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include "Warehouse.h"
#include <limits>

class InputValidator {
public:
    // Get a correct integer from the user
    static int getValidIntInput(const std::string& prompt);

    // Get a correct decimal number from the user
    static double getValidDoubleInput( std::string& prompt);

    // Get a correct string from the user
    static std::string getValidStringInput(const std::string& prompt);

    // Check the capacity and ensure that it is a valid number
    static int getValidCapacityInput(int maxCapacity);

    // Receive a secure order quantity from the user
    static int getValidOrderQuantity( Warehouse& warehouse,  Product& product);

    // Receive a valid email from the user
    static string getValidEmailInput();

    // Get a valid password from the user
    static string getValidPasswordInput();
};

#endif // INPUTVALIDATOR_H

