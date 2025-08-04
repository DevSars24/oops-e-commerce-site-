Simple E-commerce System
Overview
This C++ project implements a basic e-commerce system demonstrating the four pillars of Object-Oriented Programming (OOP): Encapsulation, Inheritance, Polymorphism, and Abstraction. The system includes classes for products, users (with customer and admin subclasses), and orders.
How the Four Pillars of OOP are Implemented
1. Encapsulation

Implementation: Private data members in the product and order classes (e.g., id, name, price, stock in product and cust, prod, quantity in order) are protected from direct access.
Access Control: Public getter methods (getid, getname, getprice, getstock) and controlled methods like reducestock ensure data is accessed and modified safely.
Benefit: Protects the internal state of objects, ensuring data integrity (e.g., stock can't be reduced below zero).

2. Inheritance

Implementation: The user class is a base class, with customer and admin as derived classes inheriting the name attribute and showdetails method.
Benefit: Promotes code reuse and establishes a clear hierarchy where customer and admin share common user properties but extend functionality specific to their roles.

3. Polymorphism

Implementation: The showdetails method is declared virtual in the user base class and overridden in the customer and admin derived classes to provide specific behavior.
Benefit: Allows different user types to display their details differently while using a common interface, enabling flexible and extensible code.

4. Abstraction

Implementation: The user class provides an abstract interface with the showdetails method, hiding implementation details of derived classes. The order class abstracts the process of combining a customer, product, and quantity into a single entity.
Benefit: Simplifies interaction with complex objects by exposing only necessary methods and hiding internal details.

How to Run

Compile the main.cpp file using a C++ compiler (e.g., g++):g++ main.cpp -o ecommerce


Run the executable:./ecommerce



Output
The program will:

Create an admin and a customer.
Allow the admin to add products to a product list.
Display available products.
Create an order for a customer, reducing the product stock.
Show order details and updated product stock.

Example Output
Available Products:
ID: 1, Name: Laptop, Price: $999.99, Stock: 10
ID: 2, Name: Phone, Price: $599.99, Stock: 20

Order Details:
Customer name: Alice
Product: Laptop, Quantity: 2, Total Price: $1999.98

Updated Product Stock:
ID: 1, Name: Laptop, Price: $999.99, Stock: 8
ID: 2, Name: Phone, Price: $599.99, Stock: 20

Dependencies

C++ Standard Library (iostream, vector, string)

Notes

The project uses basic C++ features and is kept simple to focus on OOP principles.
Error handling is minimal (e.g., stock check in reducestock) to demonstrate functionality clearly.
Extend the system by adding more features like product categories, user authentication, or persistent storage.
