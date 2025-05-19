#ifndef MENU_H
#define MENU_H

#include "Order.h"
#include "ReportManager.h"

using std::vector;
class Menu {
public:
    // Shows the main menu
    void showMainMenu(Warehouse& k, vector<Order>& orders, vector<Product>& products);

    // shows the product menu
    void showProductMenu(Warehouse& k, vector<Product>& products);

    // Shows the order menu
    void showOrderMenu(Warehouse& k, vector<Order>& orders);
};

#endif // MENU_H

