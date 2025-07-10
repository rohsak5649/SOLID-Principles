//💡 Analogy:
// You have a universal switch that can turn ON anything — Bulb, Fan, TubeLight, etc.
// You don’t want the switch to care what it’s turning on.
//✅ So, Switch should depend on an interface called "Device" — not on the actual Bulb or Fan.

//❌ BAD CODE (Violates DIP)

#include <iostream>
using namespace std;

// ❌ Low-level class (specific)
class Bulb {
public:
    void turnOn() {
        cout << "Bulb is ON\n";
    }
};

// ❌ High-level class directly depends on Bulb
class Switch {
    Bulb* bulb; // tightly coupled to Bulb
public:
    Switch(Bulb* b) {
        bulb = b;
    }

    void press() {
        bulb->turnOn(); // directly calling Bulb
    }
};

int main() {
    Bulb b;
    Switch s(&b);
    s.press(); // Output: Bulb is ON

    return 0;
}
//🧨 Problem:
// If you want to use Fan or TubeLight instead of Bulb,
// you must change the Switch class = ❌ bad design.

//✅ GOOD CODE (Follows DIP)

#include <iostream>
using namespace std;

// ✅ Interface (Abstraction)
class IDevice {
public:
    virtual void turnOn() = 0;
};

// ✅ Low-level class 1
class Bulb : public IDevice {
public:
    void turnOn() override {
        cout << "Bulb is ON\n";
    }
};

// ✅ Low-level class 2
class Fan : public IDevice {
public:
    void turnOn() override {
        cout << "Fan is ON\n";
    }
};

// ✅ High-level class depends on abstraction, not concrete class
class Switch {
    IDevice* device; // loosely coupled
public:
    Switch(IDevice* d) {
        device = d;
    }

    void press() {
        device->turnOn(); // Works with any device!
    }
};

int main() {
    Bulb bulb;
    Fan fan;

    Switch s1(&bulb); // using bulb
    s1.press();       // Output: Bulb is ON

    Switch s2(&fan);  // using fan
    s2.press();       // Output: Fan is ON

    return 0;
}
//✅ Benefits:
//✅ You can add new devices like TubeLight, AC, etc., without changing the Switch class
//✅ The Switch works with anything that follows the IDevice interface
//✅ High-level code is now flexible and future-proof

//🧠 Final Tip:
//"Use interfaces to connect your classes like plugs and sockets."
