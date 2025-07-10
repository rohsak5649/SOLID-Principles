// ❌ BAD Code (Violates OCP - keep editing old logic)

#include <iostream>
using namespace std;

class BurgerMaker {
public:
    void makeBurger(string type) {
        if (type == "Veg") {
            cout << "Making Veg Burger\n";
        } else if (type == "Chicken") {
            cout << "Making Chicken Burger\n";
        }
        // Now boss wants Fish Burger? You must edit this again 😫
        else if (type == "Fish") {
            cout << "Making Fish Burger\n";
        }
    }
};

int main() {
    BurgerMaker maker;
    maker.makeBurger("Veg");
    maker.makeBurger("Chicken");
    maker.makeBurger("Fish");

    return 0;
}


//✅ GOOD Code (Follows OCP - extend without touching old code)

#include <iostream>
using namespace std;

class Burger {
public:
    virtual void makeBurger() = 0;
};

class VegBurger : public Burger {
public:
    void makeBurger() override {
        cout << "Making Veg Burger\n";
    }
};

class ChickenBurger : public Burger {
public:
    void makeBurger() override {
        cout << "Making Chicken Burger\n";
    }
};

class FishBurger : public Burger {
public:
    void makeBurger() override {
        cout << "Making Fish Burger\n";
    }
};

class BurgerShop {
public:
    void serve(Burger* b) {
        b->makeBurger();
    }
};

int main() {
    BurgerShop shop;

    VegBurger veg;
    ChickenBurger chicken;
    FishBurger fish;

    shop.serve(&veg);
    shop.serve(&chicken);
    shop.serve(&fish);

    return 0;
}
