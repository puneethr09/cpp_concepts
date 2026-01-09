#include <iostream>
#include <memory>
#include <string>

// The Adapter Pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate.
// It acts as a wrapper between two objects. It catches calls for one object and transforms them to format and interface recognizable by the second object.

// below example explained:
//  Target (EuropeanSocket) is the interface that the client expects to use.
//  Adaptee (USASocket) is the existing class with an incompatible interface.
//  Adapter (SocketAdapter) implements the Target interface and wraps the Adaptee instance.
//  Example usage:
//  std::unique_ptr<EuropeanSocket> socket = std::make_unique<SocketAdapter>();
//  socket->voltage220();
//  Output: Adapter converts 220V to 110V for USA Socket.
//          USA Socket supplies 110V.

// Step 1: Target Interface (European Socket - requires 220V)
class EuropeanSocket {
public:
    virtual void voltage220() = 0;
    virtual ~EuropeanSocket() = default;
};

// Step 2: Adaptee (USA Socket - supplies 110V)
// This is the class we want to use, but its interface is incompatible.
class USASocket {
public:
    void voltage110() {
        std::cout << "USA Socket supplies 110V." << std::endl;
    }
};

// Step 3: Adapter
// This class implements the Target interface (EuropeanSocket) and internally calls the Adaptee (USASocket).
class SocketAdapter : public EuropeanSocket {
private:
    std::unique_ptr<USASocket> usaSocket;

public:
    SocketAdapter() : usaSocket(std::make_unique<USASocket>()) {}

    // Implements the interface client expects (voltage220)
    void voltage220() override {
        std::cout << "Adapter converts 220V to 110V for USA Socket." << std::endl;
        // Accesses the Adaptee functionality
        usaSocket->voltage110();
    }
};
