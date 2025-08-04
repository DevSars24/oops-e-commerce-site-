#include <iostream>
#include <vector>
#include <string>
using namespace std;

class product {
private:
    int id;
    string name;
    float price;
    int stock;

public:
    // Constructor
    product(int i, string n, float p, int s) {
        id = i;
        name = n;
        price = p;
        stock = s;
    }

    // Show details
    void showdetails() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", Stock: " << stock << endl;
    }

    // Getter methods
    int getid() {
        return id;
    }
    string getname() {
        return name;
    }
    float getprice() {
        return price;
    }
    int getstock() {
        return stock;
    }

    // Reduce stock method
    void reducestock(int qty) {
        if (qty <= stock)
            stock -= qty;
        else
            cout << "Not enough stock!" << endl;
    }
};

class user {
protected:
    string name;

public:
    user(string n) {
        name = n;
    }

    virtual void showdetails() {
        cout << "User: " << name << endl;
    }
};

class customer : public user {
public:
    customer(string n) : user(n) {}

    void showdetails() override {
        cout << "Customer name: " << name << endl;
    }
};

class admin : public user {
public:
    admin(string n) : user(n) {}

    void showdetails() override {
        cout << "Admin name: " << name << endl;
    }

    product addproduct(int id, string name, float price, int stock) {
        return product(id, name, price, stock);
    }
};

class order {
private:
    customer cust;
    product prod;
    int quantity;

public:
    order(customer c, product p, int qty) : cust(c), prod(p), quantity(qty) {
        prod.reducestock(qty);
    }

    void showdetails() {
        cout << "Order Details:" << endl;
        cust.showdetails();
        cout << "Product: " << prod.getname() << ", Quantity: " << quantity 
             << ", Total Price: $" << quantity * prod.getprice() << endl;
    }
};

int main() {
    // Create admin and customer
    admin admin1("John");
    customer cust1("Alice");

    // Admin adds products
    vector<product> products;
    products.push_back(admin1.addproduct(1, "Laptop", 999.99, 10));
    products.push_back(admin1.addproduct(2, "Phone", 599.99, 20));

    // Display products
    cout << "Available Products:" << endl;
    for (auto& p : products) {
        p.showdetails();
    }

    // Create an order
    order order1(cust1, products[0], 2);
    
    // Show order details
    order1.showdetails();

    // Show updated product stock
    cout << "\nUpdated Product Stock:" << endl;
    for (auto& p : products) {
        p.showdetails();
    }

    return 0;
}