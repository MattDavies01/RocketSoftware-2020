#include "IO.h"
#include "iostream"
#include<thread>

IO::IO() {

}

IO::~IO() {
    std::cout << "destroy thread" << std::endl;
	thisThread.~thread(); 
	std::cout << "Thread " << "testSensorThread" << " killed:" << std::endl;
}

void IO::initialize() {
	if (createThread) {
		std::cout << "create thread" << std::endl;

		thisThread = std::thread(&IO::run, this);
		thisThread.detach();
	}