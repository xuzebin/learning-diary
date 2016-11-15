/**
 * Another way (probably the traditional way) of using callback pattern in C++.
 * Referencing GLUT callback APIs such as glutDisplayFunc(), glutMouseFunc().
 * 
 * This example shows callback pattern by invoking the callback function every second and pass in an updated timestamp.
 * The callback function (callee) simply print the timestamp;
 */

#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>

//example: invoke func every second, and update time.
void caller(void (*func)(std::clock_t)) {
  int count = 0;
  while (true) {
    //sleep for 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    clock_t t = std::clock();

    //invoke callback
    (*func)(t);

    //let loop terminates after about 10 seconds
    if (count++ > 10) {
      break;
    }
  }
}

void callee(std::clock_t time) {
  std::cout << time << std::endl;
}


int main() {
  caller(callee);
  return 0;
}
