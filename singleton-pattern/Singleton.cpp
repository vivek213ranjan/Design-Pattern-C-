#include <iostream>
#include <string>
using namespace std;

class GameSetting {

    static GameSetting* _instance;
    int _brightness;
    int _width;
    int _height;

    GameSetting(): _width(786), _height(1300), _brightness(75){}

public:

    static GameSetting* getInstance() {
        if(_instance == NULL) {
            _instance = new GameSetting();
        }
        return _instance;
    }

    void setWidth(int w) {
        _width = w;
    }

    void setheight(int h) {
        _height = h;
    }

    void setBrightness(int b) {
        _brightness = b;
    }
    int getWidth() { return  _width; }
    int getHeight() { return _height; }
    int getBrightness() { return  _brightness; }

    void displaySettings() {
        cout<<endl<<"Brightness: "<<_brightness<<" Height: "<<_height<<" Width: "<<_width<<endl<<endl;
    }


};

GameSetting *GameSetting::_instance = NULL;

void someFunction(){
    GameSetting *setting = GameSetting::getInstance();
    setting->displaySettings();
}

int main() {
    GameSetting *setting = GameSetting::getInstance();
    setting->displaySettings();
    setting->setBrightness(100);
    someFunction();
    return 0;
}