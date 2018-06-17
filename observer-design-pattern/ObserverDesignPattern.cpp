#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

class Observer;

class Car {
    int position;
    vector<Observer*> observerList;

public:
    int getPosition() { return position; }
    void setPosition(int newPosition) {
        position = newPosition;
        notify();
    }

    void attach(Observer *observer) {
        observerList.push_back(observer);
    }

    void detach(Observer *obs) {
        observerList.erase(remove(observerList.begin(), observerList.end(), obs), observerList.end());
    }

    void notify();

};

class Observer {
    Car *_car;
public:
    Observer(Car *car) {
        _car = car;
        _car->attach(this);
    }
    virtual void update() = 0;

protected:
    Car *getCar() {
        return _car;
    }
};


void Car::notify() {
    for(int i=0; i<observerList.size(); i++) {
        observerList[i]->update();
    }
}


class LeftObserver: public Observer {
public:
    LeftObserver(Car *car): Observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if(pos < 0) {
            cout << "left side "<<endl;
        }
    }
};


class RightObserver: public Observer {
public:
    RightObserver(Car *car): Observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if(pos > 0) {
            cout << "right side "<<endl;
        }
    }
};

class MiddleObserver: public Observer {
public:
    MiddleObserver(Car *car): Observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if(pos == 0) {
            cout << "middle side "<<endl;
        }
    }
};

int main () {
    Car *car = new Car();
    LeftObserver leftObserver(car);
    RightObserver rightObserver(car);
    MiddleObserver middleObserver(car);

    cout<<"hit left right button to drive a car in your city!!! and press Esc to close!!!" << endl;
    char pressedButton;

    bool breakLoop = false;

    while(!breakLoop) {
        cin>>pressedButton;
        switch (pressedButton) {
            case 108: {
                car->setPosition(-1);
                break;
            }
            case 99: {
                car->setPosition(0);
                break;
            }
            case 114: {
                car->setPosition(1);
                break;
            }
            case 98: {
                breakLoop = true;
                break;
            }
            default: {
                cout<<"Please drive carefully\n";
            }

        }
    }
    cout<<"Bye!!!\n";
}
