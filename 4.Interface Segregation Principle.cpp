//"Don't force a class to implement things it doesn't need."

//In other words:

//✅ Give small, focused interfaces
//❌ Not big, fat ones that force classes to do extra work

//🧠 Real-Life Analogy:
//💡 Imagine a Multi-Remote with 10 buttons:
//TV needs: Power, Volume, Channel
//Fan needs: Power, Speed
//AC needs: Power, Temp

//But the remote has all 10 buttons, and you’re forced to implement all!

//❌ That’s wrong!
//✅ Each device should get only what it needs

//❌ BAD Code (Violates Interface Segregation)


class Machine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

class OldPrinter : public Machine {
public:
    void print() override {
        cout << "Printing...\n";
    }
    void scan() override {
        // ❌ Old printer can't scan!
        throw "Scan not supported!";
    }
    void fax() override {
        // ❌ Old printer can't fax!
        throw "Fax not supported!";
    }
};
//🧨 Problem:
// OldPrinter is forced to implement scan() and fax() even if it doesn’t support them It violates ISP

// ✅ GOOD Code (Follows ISP)
// 💡 Break big interface into small interfaces:

class IPrinter {
public:
    virtual void print() = 0;
};

class IScanner {
public:
    virtual void scan() = 0;
};

class IFax {
public:
    virtual void fax() = 0;
};
//✅ Now create only what you need:
class OldPrinter : public IPrinter {
public:
    void print() override {
        cout << "Printing...\n";
    }
};

class ModernPrinter : public IPrinter, public IScanner, public IFax {
public:
    void print() override {
        cout << "Printing...\n";
    }
    void scan() override {
        cout << "Scanning...\n";
    }
    void fax() override {
        cout << "Faxing...\n";
      
    }
};

