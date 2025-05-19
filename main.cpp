#include <iostream>
#include <vector>
#include "Product.h"
#include "Warehouse.h"
#include "Order.h"
#include "Menu.h"
#include "InputValidator.h"

using namespace std;

int main() {
    // Determine warehouse capacity
    //int capacity = InputValidator::getValidCapacityInput(1000); // Get a maximum capacity of 1000
    Warehouse warehouse(1000000);
    
    vector<Product> products;
    vector<Order> orders;
    
    Product p1(1, "Laptop", 10, 5000);
    Product p2(2, "Phone", 20, 3000);
    Product p3(3, "Tablet", 15, 2500);
    
    // Add products to warehouse
    warehouse.addProduct(p1);
    warehouse.addProduct(p2);
    warehouse.addProduct(p3);  
    
    products = warehouse.GetProducts(); // Receive uploaded products
    
    // Create a menu object
    Menu menu;
    
    cout << "=== Welcome to Warehouse Management System ===" << endl;
    bool running = true;
    //analyzeWarehouse(warehouse); // Analyze the warehouse
    while (running) {
        // Show main menu
        menu.showMainMenu(warehouse, orders, products);
        int choice = InputValidator::getValidIntInput("Your choice: ");
        
        switch (choice) {
            case 1:
                // Product management
                menu.showProductMenu(warehouse, products);
                break;
            case 2:
                // Order management
                menu.showOrderMenu(warehouse, orders);
                break;
            case 3: {  
                // Reporting
                ReportManager reportManager; // Create a Report Manager object
                reportManager.showReportMenu(warehouse, orders);
                break;
            }
            case 4:
                running = false;
                return 0;
                break;
            default:
                cout << "Invalid selection! Please try again." << endl;
                break;
        }
    }
    return 0;
}
