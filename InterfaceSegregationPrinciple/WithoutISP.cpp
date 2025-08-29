#include <iostream>
using namespace std;

class RemoteControl
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void record() = 0;
};

class TV : public RemoteControl
{
public:
    void turnOn()
    {
        cout << "Turning on the TV." << endl;
    }
    void turnOff()
    {
        cout << "Turning off the TV." << endl;
    }

    // We have to implement record method here unnecessarily
    void record()
    {
        cout << "Recording TV show..." << endl;
    }
};

class Camera : public RemoteControl
{
public:
    void turnOn()
    {
        cout << "Turning on the Camera." << endl;
    }
    void turnOff()
    {
        cout << "Turning off the Camera." << endl;
    }
    void record()
    {
        cout << "Recording..." << endl;
    }
};

int main()
{
    TV tv;
    tv.turnOn();
    tv.turnOff();
    tv.record(); // This is unnecessary

    Camera camera;
    camera.turnOn();
    camera.record();
    camera.turnOff();

    return 0;
}