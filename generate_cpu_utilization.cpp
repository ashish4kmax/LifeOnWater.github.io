// cpu_utilization.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

int get_cpu_utilization() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    std::string cpu;
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

    int idle_time = idle + iowait;
    int non_idle_time = user + nice + system + irq + softirq + steal;

    int total_time = idle_time + non_idle_time;
    double cpu_utilization = (non_idle_time * 100.0) / total_time;

    return cpu_utilization;
}

int main() {
    double utilization = get_cpu_utilization();
    std::cout << "CPU Utilization: " << utilization << "%" << std::endl;
    return 0;
}
