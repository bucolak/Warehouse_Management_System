#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Product.h"
#include <vector>
#include <exception>
#include <iomanip>

using std::exception;
class Warehouse{
    private:
        int capacity;
        vector<Product> products;
    public:
        Warehouse(){}
        Warehouse(int capacity){
            this->capacity=capacity;
        }
        int addProduct(Product p); //add product
        void removeProduct(int ProductId); //product release
        void searchProduct(int productID); //search for products
         vector<Product>& GetProducts() ; //get the goods from the warehouse
        int getCapacity() ; // take capacity
        int getCurrentStock() ; // instant total number of products
        bool is_product_available(Product p); //is the product available?
        friend void analyzeWarehouse(const Warehouse& warehouse);
};

class WarehouseFullException : public exception // thrown error when adding a product if the warehouse is
{
    public: 
        const char *what()  throw()
        {
            return "Warehouse capacity full, unable to add product!\n";
        }
};

class WarehouseOccupancyWarning : public exception
{
    public: 
        const char *what()  throw()
        {
            return "Warehouse capacity is almost full!\n";
        }
};

#endif
