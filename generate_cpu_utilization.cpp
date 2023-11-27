#include <iostream>
#include <chrono>
#include <thread>

int main() {
    const int loopIterations = 100000000;

    while (true) {
        // Simulate CPU work
        for (int i = 0; i < loopIterations; ++i) {
            // Do some computation
        }

        // Sleep for a short duration to avoid 100% CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
