#include "Warehouse.h"

int Warehouse::getCurrentStock() 
{
    int total=0;
    for(int i = 0;i<products.size();i++)
    {
        total+=products[i].getQuantity();
    }
    return total;
}
int Warehouse::addProduct(Product p)
{
     for (const auto& existingProduct : products)
    {
        if (existingProduct.getId() == p.getId())
        {
            cout << "A product with the same ID already exists. Cannot add the product!\n";
            return 0;
        }
    }

    // Check if the capacity is enough
    int totalStockAfterAddition = getCurrentStock() + p.getQuantity();
    if (totalStockAfterAddition > capacity)
    {
        cout << "Exceeding capacity, please try again!\n";
        return 0;
    }

    // Adding product
    products.push_back(p);

    // give capacity warning
    if (totalStockAfterAddition >= capacity - 2)
    {
        throw WarehouseOccupancyWarning();
    }

    return 1;
    // if(getCurrentStock()+ p.getQuantity() > capacity)
    // {
    //     cout<<"Exceeding capacity, please try again!\n";
    //     return 0;
    // }
    // products.push_back(p);
    // if(getCurrentStock() == capacity-2)
    // {
    //     throw WarehouseOccupancyWarning();
    // }
    // return 1;
}

void Warehouse::removeProduct(int productId) {
    bool found = false;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            if (it->getQuantity() > 0) {
                products.erase(it);
                cout << "Product removed successfully.\n";
            } else {
                cout << "Product out of stock.\n";
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product with ID " << productId << " not found.\n";
    }
}



 vector<Product>& Warehouse::GetProducts() 
{
    cout<<"---------------------------------------------"<<endl;
    cout<<"|               Product List                |"<<endl;
    cout<<"|             ----------------              |"<<endl;
    cout<<"|   NAME    |   ID   | QUANTITY |   PRICE   |"<<endl;
    cout<<"|  ------      ----    --------    -------  |"<<endl;
    
    for( Product &prod : products) // The reason I use &(reference) is to operate with the original object
    {
        cout << "| "
             << std::left << std::setw(10) << prod.getName() << " | "
             << std::right << std::setw(4) << prod.getId() << " | "
             << std::right << std::setw(8) << prod.getQuantity() << " | "
             << std::right << std::setw(8) << std::fixed << std::setprecision(2) << prod.getPrice()
             << "   |" << endl;
    }
    cout<<"---------------------------------------------"<<endl;
    return products;
}

int Warehouse::getCapacity() 
{
    return capacity;
}

void Warehouse::searchProduct(int productID)
{
    bool found = false;
    for(int i = 0; i < products.size(); i++)
    {
        if(productID == products[i].getId())
        {
            found = true;
            cout<<"The product is in stock!"<<endl;
            cout<<"If you want to access product details, please enter “yes” : ";
            
            string response;
            cin >> response;
            if(response == "yes") // here we evaluate the user's response
            {
                cout<<endl;
                cout<<"--------------------------------"<<endl;
                cout<<"-  Product name :          "<<std::left <<std::setw(10)<<products[i].getName()<<"-"<<endl;
                cout<<"-  Product ID :            "<<std::left <<std::setw(10)<<products[i].getId()<<"-"<<endl;
                cout<<"-  Product quantity :      "<<std::left <<std::setw(10)<<products[i].getQuantity()<<"-"<<endl;
                cout<<"-  Product price :         "<<std::left <<std::setw(10)<<products[i].getPrice()<<"-"<<endl;
                cout<<"--------------------------------"<<endl;
                break;
            }
        }
    }
    if(found==false)
        cout<<"Product not found in stock!"<<endl;
}

bool Warehouse::is_product_available(Product p)
{
    for(int i = 0;i < products.size();i++)
    {
        if(p.getId() == products[i].getId())
            return true;
    }
    return false;
}

void analyzeWarehouse(const Warehouse& warehouse) {
    cout << "Warehouse Analysis:" << endl;
    cout << "Total Capacity: " << warehouse.capacity << endl;
    cout << "Number of Products Avaliable: " << warehouse.products.size() << endl;
    
    // Occupancy rate calculation
    double occupancyRate = static_cast<double>(warehouse.products.size()) / warehouse.capacity * 100.0;
    cout << "Occupancy Rate: %" << fixed << setprecision(4) << occupancyRate << endl;
    
    // If the warehouse is empty
    if (warehouse.products.empty()) {
        cout << "The Warehouse is currently empty!" << endl;
        return;
    }
    
    // Total Product value calculation
    double totalValue = 0.0;
    for (const auto& product : warehouse.products) {
        // This part may vary depending on the structure of your Product class
        // For example, if your Product class has getPrice() and getQuantity() methods:
        // totalValue += product.getPrice() * product.getQuantity();
        totalValue += product.getPrice() * product.getQuantity();
    }
    cout << "Total Product Value of the Warehouse: " << totalValue << " TL" << endl;   
}
