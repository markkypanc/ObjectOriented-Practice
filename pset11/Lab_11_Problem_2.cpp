/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 11
 Question No: 2
 Date: April 1, 2021
 
 */

#include <iostream>
#include <memory>
using namespace std;

//MARK: - CUSTOMER
class Customer {
public:
    virtual string generatemail() = 0;
};//: CUSTOMER


//MARK: - REGULAR
class RegularCustomer :public Customer {
public:
    string generatemail() {
        return "Regular Customer";
    }
};//: REGULAR

//MARK: - MOUNTAIN
class MountainCustomer :public Customer {
public:
    string generatemail() {
        return "Mountain Customer";
    }
};//: MOUNTAIN


//MARK: - DELINQUENT
class DeliquentCustomer :public Customer {
public:
    string generatemail() {
        return "Deliquent Customer";
    }
};//:: DELINQUENT


//MARK: - MAIL
class CustomerMailApplication {
public:
    
    unique_ptr<Customer>customer;
    
    string generateMail(int type) {
        getCustomerTypeFromUser(type);
        return customer->generatemail();
    }//: GENERATING
    
    void getCustomerTypeFromUser(int type) {
        switch (type) {
            case 1:
                customer = make_unique<RegularCustomer>();
                break;
            case 2:
                customer = make_unique<MountainCustomer>();
                break;
            default:
                customer = make_unique<DeliquentCustomer>();
        }//: SWITCH
    }//: GETTYPE
};

//MARK: - RUN

int main() {
    while (true) {
        int decision;
        cout << "1.)Regular \n2.)Mountain \n3.)Deliquent \n0.)Exit" << endl;
        cout << "Your choice: ";
        cin >> decision;
        CustomerMailApplication output;
        
        if (decision >= 1 and decision <= 3) {
            cout << output.generateMail(decision) << endl;
        } else if (decision == 0) {
            cout << "Program has been terminated.\n";
            exit(0);
        } else {
            cout << "Choice is invalid. Try again.\n";
        }
    }//: LOOP
}//: MAIN
