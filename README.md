# Warehouse Management System

A terminal-based **C++** application that simulates a small warehouse: products, stock, users, orders and reports. Written to practise object-oriented design.

## Features

- **Product management** — add, remove, search and list products
- **Order management** — create and view orders, with product availability checks
- **Reports** — `ReportManager` and `analyzeWarehouse` summarise the warehouse state
- **Input validation** — `InputValidator` rejects invalid menu input and values
- **Capacity control** — custom exceptions (`WarehouseFullException`, `WarehouseOccupancyWarning`) when the warehouse is full or nearly full

## Design

```
BaseProduct (abstract: virtual display(), pure virtual calculateTax())
   └── Product
Warehouse  ── holds products, checks capacity, throws custom exceptions
Order      ── order data + static viewOrders()
User, ReportManager, InputValidator, Menu
```

OOP concepts used: abstraction, inheritance, polymorphism (virtual functions), encapsulation, custom exception classes and STL containers.

## Build and Run

```bash
g++ -std=c++17 *.cpp -o warehouse
./warehouse
```

## Author

**Buket Çolak** — [github.com/bucolak](https://github.com/bucolak)
