/**
 * A demo showing how to realize DI (Dependency Injection) in C++ using shared pointers.
 * The setter method uses 'copy by value', while the getter method uses 'copy by reference'.
 */
#include <iostream>
#include <memory>
#include <vector>

class Body {
public:
    Body() {
        std::cout << "Body constructor" << std::endl;
    }
    ~Body() {
        std::cout << "Body destructor" << std::endl;
    }
    std::string getName() {
        return "Body";
    }
};

class Wheel {
public:
    Wheel() {
        std::cout << "Wheel constructor" << std::endl;
    }
    ~Wheel() {
        std::cout << "Wheel destructor" << std::endl;
    }
    std::string getName() {
        return "Wheel";
    }
};

class Car {
public:
    Car() {
        std::cout << "Car constructor" << std::endl;
    }
    ~Car() {
        std::cout << "Car destructor" << std::endl;
    }
    
    void setBody(std::shared_ptr<Body> body) {
        this->body = body;
    }

    void addWheel(std::shared_ptr<Wheel> wheel) {
        this->wheels.push_back(wheel);
    }

    const std::shared_ptr<Body>& getBody() const {
        return body;
    }

    const std::vector<std::shared_ptr<Wheel> >& getWheels() const {
        return wheels;
    }

private:    
    std::shared_ptr<Body> body;
    std::vector<std::shared_ptr<Wheel> > wheels;
};


int main() {
    
    Car car;

    car.setBody(std::make_shared<Body>());
    car.addWheel(std::make_shared<Wheel>());
    car.addWheel(std::make_shared<Wheel>());
    car.addWheel(std::make_shared<Wheel>());
    car.addWheel(std::make_shared<Wheel>());

    auto body = car.getBody();
    std::cout << body->getName() << std::endl;

    return 0;
}
