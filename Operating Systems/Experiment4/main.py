class Process:
    def __init__(self, pid, arrival_time, burst_time):
        self.pid = pid
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.remaining_time = burst_time
        self.waiting_time = 0
        self.turnaround_time = 0

def round_robin(processes, time_slice):
    n = len(processes)
    queue = []
    current_time = 0
    total_waiting_time = 0
    total_turnaround_time = 0

    while True:
        for process in processes:
            if process.arrival_time <= current_time and process not in queue and process.remaining_time > 0:
                queue.append(process)

        if not queue:
            break

        current_process = queue.pop(0)

        if current_process.remaining_time > time_slice:
            current_process.remaining_time -= time_slice
            current_time += time_slice
        else:
            current_time += current_process.remaining_time
            current_process.turnaround_time = current_time - current_process.arrival_time
            current_process.waiting_time = current_process.turnaround_time - current_process.burst_time
            current_process.remaining_time = 0

            total_waiting_time += current_process.waiting_time
            total_turnaround_time += current_process.turnaround_time

        if current_process.remaining_time > 0:
            queue.append(current_process)

    average_waiting_time = total_waiting_time / n
    average_turnaround_time = total_turnaround_time / n

    print("进程\t等待时间\t周转时间")
    for process in processes:
        print(f"{process.pid}\t\t{process.waiting_time}\t\t{process.turnaround_time}")

    print(f"\n平均等待时间: {average_waiting_time}")
    print(f"平均周转时间: {average_turnaround_time}")

if __name__ == "__main__":
    processes1 = [
        Process(1, 0, 3),
        Process(2, 1, 5),
        Process(3, 2, 2),
        Process(4, 3, 4)
    ]

    processes2 = [
        Process(1, 0, 4),
        Process(2, 1, 2),
        Process(3, 2, 6),
        Process(4, 3, 1)
    ]

    processes3 = [
        Process(1, 0, 1),
        Process(2, 1, 1),
        Process(3, 2, 1),
        Process(4, 2, 3)
    ]

    time_slice1 = 3
    time_slice2 = 2
    time_slice3 = 4

    print("Example 1:")
    round_robin(processes1, time_slice1)

    print("\nExample 2:")
    round_robin(processes2, time_slice2)

    print("\nExample 3:")
    round_robin(processes3, time_slice3)

