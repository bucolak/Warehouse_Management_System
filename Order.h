#ifndef ORDER_H
#define ORDER_H

#include "Warehouse.h"

class Order
{
    private:
        int OrderID; //order number
        Product *product; //a pointer to point to the Product object to access the product
public:
        int flag = 0; //a flag for writing only products that can be successfully ordered in the order list
        Order() {}
        Order(int orderid, Product *p,Warehouse *w, int amount); // we can create direct order with this constructor
        bool isValid() const;
        int getOrderId()  
        {
            return OrderID; 
        }
        static void viewOrders(const vector <Order> &orders); // The reason it is static is because we access it by class name in main
};
#endif
