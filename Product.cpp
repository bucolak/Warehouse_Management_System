#include "Product.h"

//Constructor
Product::Product(){
    id=0;
    name="";
    quantity= 0;
    price= 0.0;

}
Product::Product(int id, string name, int quantity, double price){
    this->id=id;
    this->name=name;
    this->quantity=quantity;
    this->price=price;
}

int Product:: getId() const{
    return id;
}
void Product:: setId(int id){
    this->id=id;
}
string Product:: getName() {
    return name;
}
void Product:: setName(string name){
    this->name=name;
}
int Product:: getQuantity() const{
    return quantity;
}
void Product:: setQuantity(int quantity){
    this->quantity=quantity;
}
double Product:: getPrice() const{
    return price;
}
void Product:: setPrice(double price){
    this->price=price;
}