#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>  // Add this line to include the <iterator> header
#include <unistd.h>

int get_cpu_utilization() {
    std::ifstream stat_file("/proc/stat");
    std::string line;
    std::getline(stat_file, line); // Read the first line containing total CPU stats
    std::istringstream iss(line);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>());

    // Calculate total time spent in user, nice, system, idle, iowait, irq, and softirq modes
    long total_time = std::stol(tokens[1]) + std::stol(tokens[2]) + std::stol(tokens[3]) +
                      std::stol(tokens[4]) + std::stol(tokens[5]) + std::stol(tokens[6]) +
                      std::stol(tokens[7]);

    // Calculate idle time
    long idle_time = std::stol(tokens[4]);

    // Calculate CPU utilization percentage
    double utilization = 100.0 * (1.0 - (static_cast<double>(idle_time) / total_time));

    return utilization;
}

int main() {
    double cpu_utilization = get_cpu_utilization();
    std::cout << "CPU Utilization: " << cpu_utilization << "%" << std::endl;
    return 0;
}
