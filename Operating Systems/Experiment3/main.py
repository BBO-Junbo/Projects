import random

class Job:
    def __init__(self, name, arrival_time, burst_time):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.start_time = None
        self.end_time = None

def fcfs_scheduler(jobs):
    jobs.sort(key=lambda x: x.arrival_time)

    current_time = 0
    total_wait_time = 0
    total_turnaround_time = 0

    for job in jobs:
        if current_time < job.arrival_time:
            current_time = job.arrival_time

        job.start_time = current_time
        job.end_time = current_time + job.burst_time

        total_wait_time += (job.start_time - job.arrival_time)
        total_turnaround_time += (job.end_time - job.arrival_time)

        current_time = job.end_time

    average_wait_time = total_wait_time / len(jobs)
    average_turnaround_time = total_turnaround_time / len(jobs)

    return average_wait_time, average_turnaround_time

random_jobs = [
    Job(f"Job{i}", random.randint(0, 5), random.randint(1, 10))
    for i in range(1, 6)
]

print("*****************Arrival Time and Burst Time*****************")
for job in random_jobs:
    print(f"{job.name}: Arrival Time={job.arrival_time}, Burst Time={job.burst_time}")

average_wait_time, average_turnaround_time = fcfs_scheduler(random_jobs)
print("************************************************************\n")

print("***************Start Time and finish Time*******************")
for job in random_jobs:
    print(f"{job.name}: Start Time={job.start_time}, Finish Time={job.end_time}")
print("************************************************************\n")

print("*********************** Average ****************************")
print(f"\nAverage Wait Time: {average_wait_time}")
print(f"Average Turnaround Time: {average_turnaround_time}")
