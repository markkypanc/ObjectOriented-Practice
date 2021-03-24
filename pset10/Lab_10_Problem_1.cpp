/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 10
 Question No: 1
 Date: March 24, 2021
 
 */

#include <iostream>
#include <string>
using namespace std;

// MARK: - Customer Class

class Customer {
protected:
    string type;
    string email;
public:
    void createMail(string email) {
        this->email = email;
        cout << "Successfully registered with email \"" << email << "\"\n\n";
    }
    string getType() {
        return this->type;
    }
    
    string getEmail() {
        return this->email;
    }
};//: CUSTOMER



// MARK: - Regular Type
class RegularCustomer: public Customer {
public:
    RegularCustomer() {
        this->type = "Regular Customer";
    }
};//: REGULAR


// MARK: - Mountain Type
class MountainCustomer: public Customer {
public:
    MountainCustomer() {
        this->type = "Mountain Customer";
    }
};//: MOUNTAIN


// MARK: - Deliquent Type
class DelinquentCustomer: public Customer {
public:
    DelinquentCustomer() {
        this->type = "Delinquent Customer";
    }
};//: DELINQUENT


// MARK: - CustomerMailApplication

class CustomerMailApplication {
    
private:
    
    Customer customer;
    string emailDB;
    
public:
    
    void generateMail() {
        emailDB = customer.getEmail();
    }
    
    string getCustomerTypeFromUser() {
        return customer.getType();
    }
    
};//: APPLICATION


//MARK: - MAIN

int main() {
    
    int decision;
    
    while (true) {
        cout << "1) Regular\n2) Mountain\n3) Delinquent\n";
        cout << "Your choice: ";
        cin >> decision;
        switch (decision) {
            case 1: {
                RegularCustomer customer;
                cout << "\nType of customer: [ " << customer.getType() << " ]\n";
                customer.createMail("regular_1@gmail.com");
                break;
            }
            case 2: {
                MountainCustomer customer;
                cout << "\nType of customer: [ " << customer.getType() << " ]\n";
                customer.createMail("mountain_1@gmail.com");
                break;
            }
            case 3: {
                DelinquentCustomer customer;
                cout << "\nType of customer: [ " << customer.getType() << " ]\n";
                customer.createMail("delinquent_1@gmail.com");
                break;
            }
            default:
                cout << "The program has been terminated.";
                exit(0);
        }
    }
}
