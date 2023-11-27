// generate_cpu_utilization.cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    while (true) {
        // Simulate CPU work
        for (int i = 0; i < 100000000; ++i) {
            // Do some computation
        }

        // Sleep for a short duration to avoid 100% CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
