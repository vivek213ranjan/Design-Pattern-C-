#include <iostream>
using namespace std;

#include "CarFactory.cpp"

#define SIMPLE_CAR 1
#define LUXURY_CAR 2

int main() {
    int type;
    while(1) {
        cout<<"Enter the type of Car or zero for exit" << endl;
        cin>> type;
        if(!type) {
            break;
        }
        CarFactory *factory = NULL;
        switch (type) {
            case SIMPLE_CAR: {
                factory = new SimpleCarFactory;
                break;
            }
            case LUXURY_CAR: {
                factory = new LuxuryCarFactory;
                break;
            }
            default:
            {
                cout<<"Wrong input ....."<<endl;
                break;
            }
        }
        if(factory) {
            Car *car = factory->buildWholeCar();
            car->printDetails();
        }
    }
    cout<<"Exit.."<<endl;
    return 0;
}