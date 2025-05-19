#include "Menu.h"
using namespace std;
void Menu::showMainMenu(Warehouse& warehouse, vector<Order>& orders, vector<Product>& products) {
    int choice;
    do {
        cout << "\n--- Warehouse Management System ---\n";
        cout << "1. Product Management\n";
        cout << "2. Order Management\n";
        cout << "3. View Product Report\n";
        cout << "4. Changes in the state of the warehouse\n";
        cout << "5. Exit\n";
        cout << "Please make a selection (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                showProductMenu(warehouse, products);
                break;
            case 2:
                showOrderMenu(warehouse, orders);
                break;
            case 3:
                ReportManager::listAllProducts(warehouse); // the function you wrote here did not exist, so I added
                break;
            case 4:
            {
                cout << "Analyzing warehouse...\n";
                //vector<Product>& products = warehouse.GetProducts();
                cout << "\n--- All Products in Warehouse ---\n";
                for (auto& product : products) {
                    product.display(); // You can use the display function here
                }
                cout << "----------------------------------------------\n";
                analyzeWarehouse(warehouse); // Analyze the warehouse
                break;
            }
                
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 5);
}


void Menu::showProductMenu(Warehouse& warehouse, vector<Product>& products) {
    int choice;
    
    do {
        cout << "\n--- Product Management ---\n";
        cout << "1. Search Product\n";
        cout << "2. Add Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Update Product\n";
        cout << "5. Return to Main Menu\n";
        cout << "Please make a selection (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                int productId;
                cout << "Enter product ID to search: ";
                cin >> productId;
                warehouse.searchProduct(productId);
                break;

            }
            case 2:
            {
                string name;
                int id;
                int quantity;
                int price;
                cout << "Enter product ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter product name: ";
                getline(cin, name);

                cout << "Enter quantity: ";
                cin >> quantity;

                cout << "Enter price: ";
                cin >> price;

                Product newProduct(id, name, quantity, price);
                if(warehouse.addProduct(newProduct) == 1)
                    cout << "Product added successfully!\n";
                break;
            }
            case 3:
            {
          
                int id;
                cout << "Enter product ID to delete: ";
                cin >> id;
                warehouse.removeProduct(id);
                break;
            }
            case 4:
            {
                int id;
                cout << "Enter product ID to update: ";
                cin >> id;
                bool found = false;
                for(auto& product : warehouse.GetProducts())
                {
                    string newname;
                    int newquantity;
                    int newprice;

                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(product.getId() == id)
                    {
                        cout << "Enter new product name: ";
                        getline(cin, newname);
    
                        cout << "Enter new quantity: ";
                        cin >> newquantity;
    
                        cout << "Enter new price: ";
                        cin >> newprice;
    
                        product.setName(newname);
                        product.setQuantity(newquantity);
                        product.setPrice(newprice);
    
                         cout << "Product updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product with ID " << id << " not found.\n";
                }
                break;
            }
                
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 5);
}

void Menu::showOrderMenu(Warehouse& warehouse, vector<Order>& orders) {
    int choice;
    do {
        cout << "\n--- Order Management ---\n";
        cout << "1. Place Order\n";
        cout << "2. View Order History\n";
        cout << "3. Return to Main Menu\n";
        cout << "Please make a selection (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                int productId, quantity;
                cout << "Enter product ID to order: ";
                cin >> productId;
                cout << "Enter quantity: ";
                cin >> quantity;

                bool found = false;
                for (auto& product : warehouse.GetProducts()) {
                    if (product.getId() == productId) {
                        Order order(1000 + orders.size(), &product, &warehouse, quantity);
                    
                        if (order.isValid()) {
                            orders.push_back(order);
                            cout << "Order placed successfully!" << endl;
                        } else {
                            cout << "Order failed!" << endl;
                        }
                    
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product not found.\n";
                }
                break;
            }
            case 2:
                Order().viewOrders(orders);
                break;
            case 3:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 3);
}

