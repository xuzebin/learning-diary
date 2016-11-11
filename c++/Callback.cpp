/**
 * A simple example showing how to use callback in C++.
 * Reference: http://tedfelix.com/software/c++-callbacks.html
 */

#include <string>
#include <iostream>

class CallbackInterface {
public:
  virtual void callback_func(std::string something) = 0;
};

class Caller {
private:
  CallbackInterface* callback;

public:
  void addCallback(CallbackInterface* callback) {
    this->callback = callback;
  }

  void testCallback() {
    if (callback != NULL) {
      callback->callback_func("callback is inovked!");
    }
  }
};

class Callee : public CallbackInterface {
public:
  void callback_func(std::string something) {
    std::cout << something << std::endl;
  }
};

int main() {
  Caller caller;
  Callee callee;
  caller.addCallback(&callee);
  caller.testCallback();
  return 0;
}
