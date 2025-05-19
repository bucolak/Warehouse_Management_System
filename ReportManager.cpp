
#include "ReportManager.h"

// List all products in the warehouse
void ReportManager::listAllProducts(Warehouse &warehouse)
{
    cout << "\n--- All Products in Warehouse ---\n";
    warehouse.GetProducts();
}

// Critical stock report (products with stock quantity below a certain ethical value)
void ReportManager::criticalStockReport( Warehouse &warehouse, int threshold)
{
    cout << "\n--- Critical Stock Report (Stock quantity less than " << threshold << ") ---\n";
    vector<Product> products = warehouse.GetProducts();
    bool found = false;

    for ( Product &prod : products)
    {
        if (prod.getQuantity() < threshold)
        {
            found = true;
            cout << "Product Name: " << prod.getName()
                 << " | ID: " << prod.getId()
                 << " | Quantity: " << prod.getQuantity() << endl;
        }
    }

    if (!found)
    {
        cout << "There is no product below the critical stock level.\n";
    }
}

// List all orders
void ReportManager::listAllOrders( vector<Order> &orders)
{
    cout << "\n--- Order Backlog ---\n";
    for ( Order &o : orders)
    {
        if (o.flag == 1)  // If the order is successfull
        {
            cout << "Order ID: " << o.getOrderId() << " (Order successful)" << endl;
        }
    }
}

// Show the report menu
void ReportManager::showReportMenu( Warehouse &warehouse,  vector<Order> &orders)
{
    int choice;
    do
    {
        cout << "\n========= REPORT MENU =========" << endl;
        cout << "1. List all products" << endl;
        cout << "2. Indicates critical stock items" << endl;
        cout << "3. List all orders" << endl;
        cout << "0. Exit the report menu" << endl;
        cout << "Make your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            listAllProducts(warehouse);
            break;
        case 2:
            int threshold;
            cout << "Enter the stock threshold value: ";
            cin >> threshold;
            criticalStockReport(warehouse, threshold);
            break;
        case 3:
            listAllOrders(orders);
            break;
        case 0:
            cout << "Exiting the report menu..." << endl;
            break;
        default:
            cout << "Invalid selection! Please try again." << endl;
            break;
        }
    } while (choice != 0);
}
