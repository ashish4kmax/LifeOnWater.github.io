import psutil

def get_cpu_utilization():
    # Get CPU utilization percentage
    cpu_percent = psutil.cpu_percent(interval=1)

    return cpu_percent

if __name__ == "__main__":
    cpu_utilization = get_cpu_utilization()
    print(f"CPU Utilization: {cpu_utilization}%")
