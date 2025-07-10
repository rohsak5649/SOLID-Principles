//💡 Real-Life Example: Birds and Flying
//❌ Violating LSP:

class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying\n";
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow flies\n";
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        // ❌ Ostriches can't fly!
        throw "I can't fly!";
    }
};

void makeBirdFly(Bird* bird) {
    bird->fly();
}

int main() {
    Sparrow s;
    makeBirdFly(&s); // ✅ works

    Ostrich o;
    makeBirdFly(&o); // ❌ crashes program

    return 0;
}
//🧨 What went wrong?
//Ostrich is a Bird but can’t fly.
//We assumed all Birds can fly.
//Replacing parent (Bird) with child (Ostrich) breaks the program → ❌ Violates LSP




//✅ Following LSP: Separate responsibilities

class Bird {
public:
    virtual void eat() {
        cout << "Bird is eating\n";
    }
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        cout << "Sparrow is flying\n";
    }
};

class Ostrich : public Bird {
    // Ostrich can’t fly but still is a Bird.
};

void letItFly(FlyingBird* fb) {
    fb->fly();
}

int main() {
    Sparrow s;
    letItFly(&s); // ✅ Works fine

    // Ostrich o;
    // letItFly(&o); ❌ Won't compile — because Ostrich isn't a FlyingBird
    return 0;
}

//✅ This way:
//Ostrich is just a Bird 🐦 (not a FlyingBird)
//We never assume all birds can fly
//💥 Problem solved, LSP followed
