#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "Order.h"
#include <iomanip>

class ReportManager
{
public:
    ReportManager() {}

    // List all products in the warehouse
    static void listAllProducts(Warehouse &warehouse);

    // Critical stock report (critical under 10 products by default)
    static void criticalStockReport( Warehouse &warehouse, int threshold = 10);

    // List all products
    static void listAllOrders( std::vector<Order> &orders);

    // Displaying report menu
    static void showReportMenu( Warehouse &warehouse,  std::vector<Order> &orders);
};

#endif

