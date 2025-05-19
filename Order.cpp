#include "User.h"

Order::Order(int orderid, Product *p, Warehouse *w,int amount) : OrderID(orderid), product(p) 
{
    //here we check the availability of the product and create
    if(p->getQuantity()>0 && p->getQuantity()>=amount && w->is_product_available(*p)==true)
    {
        flag = 1;
        p->setQuantity((p->getQuantity())-amount);
        cout<<"Order created!"<<endl;
    }
    else
    {
        cout<<"Insufficient Stock!"<<endl;
    }
}

void Order::viewOrders(const vector <Order> &orders)
{
    cout<<"---Order List---"<<endl;
    //we print the order list
    for(Order o : orders)
    {
        if(o.flag==1)
            cout<<"Order ID: "<<o.getOrderId()<<" | Product ID: "<<o.product->getId()<<endl;
    }
}

bool Order::isValid() const {
    return flag == 1;
}
