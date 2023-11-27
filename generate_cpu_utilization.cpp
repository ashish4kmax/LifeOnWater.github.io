#include <iostream>
#include <sys/sysinfo.h>

int main() {
  // Get the current CPU utilization
  struct sysinfo si;
  sysinfo(&si);

  // Calculate CPU utilization percentage
  double cpu_usage = si.cpu_total - si.cpu_idle;
  double cpu_percent = cpu_usage / si.cpus * 100;

  // Convert CPU percentage to integer
  int cpu_utilization = (int)cpu_percent;

  // Print CPU utilization
  std::cout << "CPU utilization: " << cpu_utilization << "%" << std::endl;

  return 0;
}
