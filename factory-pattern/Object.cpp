#include <iostream>
using namespace std;

class Toy {
protected:
    string name;
    float price;

public:
    virtual void prepareParts()  = 0;
    virtual void combineParts()  = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel()    = 0;
    virtual void showProduct()   = 0;

};


class Car : public Toy {
public:
    void prepareParts() { cout<<"Preparing parts for car" << endl; }
    void combineParts() { cout<<"Combining parts for car" << endl; }
    void assembleParts() { cout<<"Assembling parts for car" << endl; }
    void applyLabel() { cout<<"Applying Car Label" << endl; name = "Car"; price = 10; }
    void showProduct() { cout<<"Name: "<<name<<endl<<"Price: "<<price<<endl; }
};

class Bike : public Toy {
public:
    void prepareParts() { cout<<"Preparing parts for Bike" << endl; }
    void combineParts() { cout<<"Combining parts for bike" << endl; }
    void assembleParts() { cout<<"Assembling parts for bike" << endl; }
    void applyLabel() { cout<<"Applying Bike Label" << endl; name = "Bike"; price = 7; }
    void showProduct() { cout<<"Name: "<<name<<endl<<"Price: "<<price<<endl; }
};


class Plane : public Toy {
public:
    void prepareParts() { cout<<"Preparing parts for plane" << endl; }
    void combineParts() { cout<<"Combining parts for plane" << endl; }
    void assembleParts() { cout<<"Assembling parts for plane" << endl; }
    void applyLabel() { cout<<"Applying Plane Label" << endl; name = "Plane"; price = 100; }
    void showProduct() { cout<<"Name: "<<name<<endl<<"Price: "<<price<<endl; }
};