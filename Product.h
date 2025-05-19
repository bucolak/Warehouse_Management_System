#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "BaseProduct.h"
using namespace std;
// I wrote this page so that it would not be complicated, I opened another page and wrote the methods open there, I already call this page in product.cpp.
class Product : public BaseProduct{
    private:
    // Here I have defined the features that should be in the product class.
        int id;
        string name;
        int quantity;
        double price;

    public:
    // I defined the constructor and get set methods.
        Product();
        Product(int id, string name, int quantity, double price);
        
        void setId(int id);
        int getId() const;

        void setName(string name);
        string getName() ;

        void setQuantity(int quantity);
        int getQuantity() const;

        void setPrice(double price);
        double getPrice() const;

        void display() const override {
            cout << "Product ID: " << id << ", Name: " << name
                 << ", Quantity: " << quantity << ", Price: " << price << endl;
        }
        double calculateTax() const override {
            return price * 0.18; // Calculate 18% VAT
        }
};

#endif
