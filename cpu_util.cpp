#include <iostream>
#include <windows.h>

double GetCpuUtilization() {
    FILETIME idleTime, kernelTime, userTime;
    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
        ULARGE_INTEGER totalTime, idleTotalTime;
        totalTime.LowPart = userTime.dwLowDateTime;
        totalTime.HighPart = userTime.dwHighDateTime;
        totalTime.LowPart += kernelTime.dwLowDateTime;
        totalTime.HighPart += kernelTime.dwHighDateTime;

        idleTotalTime.LowPart = idleTime.dwLowDateTime;
        idleTotalTime.HighPart = idleTime.dwHighDateTime;

        double idleTimeInSeconds = idleTotalTime.QuadPart / 10e6;
        double totalTimeInSeconds = totalTime.QuadPart / 10e6;

        return 100.0 * (1.0 - (idleTimeInSeconds / totalTimeInSeconds));
    }
    return -1.0; // Error
}

int main() {
    double cpuUtilization = GetCpuUtilization();
    if (cpuUtilization >= 0) {
        std::cout << "CPU Utilization: " << cpuUtilization << "%" << std::endl;
        return static_cast<int>(cpuUtilization); // Return CPU utilization as integer
    } else {
        std::cerr << "Error getting CPU utilization." << std::endl;
        return -1;
    }
}
