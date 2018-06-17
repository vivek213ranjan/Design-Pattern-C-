#include <iostream>
using namespace std;

#include "ToyFactory.cpp"

int main() {
    int type;
    while(1) {
        cout<<"Enter the type of toy or zero for exit" << endl;
        cin>> type;
        if(!type) {
            break;
        }
        Toy *v = ToyFactory::createToy(type);
        if(v) {
            v->showProduct();
            delete(v);
        }
    }
    cout<<"Exit.."<<endl;
    return 0;
}