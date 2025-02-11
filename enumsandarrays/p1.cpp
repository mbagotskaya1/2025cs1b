#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

enum class TrafficLight {
    Red,
    Yellow,
    Green
};

void printLight(TrafficLight light) {
    switch(light) {
        case TrafficLight::Red:
            cout << "light is red!\n";
            break;
        case TrafficLight::Green:
            cout << "light is green!\n";
            break;
        case TrafficLight::Yellow:
            cout << "light is yellow!\n";
            break;
        default:
            break;
    }
}

TrafficLight nextLight(TrafficLight light) {
    switch(light) {
        case TrafficLight::Red:
            return TrafficLight::Green;
        case TrafficLight::Green:
            return TrafficLight::Yellow;
        case TrafficLight::Yellow:
            return TrafficLight::Red;
        default:
            return TrafficLight::Green;
    }
}

int main() {

    TrafficLight light = TrafficLight::Green;

    while(true) {
        printLight(light);
        this_thread::sleep_for(chrono::seconds(2));
        light = nextLight(light);
    }
}