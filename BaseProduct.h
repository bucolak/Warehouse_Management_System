#ifndef BASEPRODUCT_H
#define BASEPRODUCT_H
using namespace std;
class BaseProduct {
    public:
        BaseProduct() {}
        virtual ~BaseProduct() {} // Virtual destructor
        
        // Virtual functions
        virtual void display() const {
            cout << "This is a basic product class."  << endl;
        }
        
        // Pure virtual function (makes the class abstract)
        virtual double calculateTax() const = 0;
    };

#endif
