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
};

class Wheel {
public:
    Wheel() {
        std::cout << "Wheel constructor" << std::endl;
    }
    ~Wheel() {
        std::cout << "Wheel destructor" << std::endl;
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
    
    void setBody(const std::shared_ptr<Body>& body) {
        this->body = body;
    }

    void addWheel(const std::shared_ptr<Wheel>& wheel) {
        wheels.push_back(wheel);
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

    return 0;
}
