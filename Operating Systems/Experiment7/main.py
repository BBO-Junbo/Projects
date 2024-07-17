import random


class DiskRequest:
    def __init__(self, track_number):
        self.track_number = track_number


class DiskScheduler:
    def __init__(self, track_count=200):
        self.track_count = track_count
        self.current_position = random.randint(0, track_count - 1)
        self.requests = [DiskRequest(random.randint(0, track_count - 1)) for _ in range(10)]
        self.rotation_time = 0.0001
        self.transfer_time = 0.00001

    def scan(self):
        sorted_requests = sorted(self.requests, key=lambda x: x.track_number)
        schedule = []

        schedule.extend(range(self.current_position, sorted_requests[0].track_number + 1))

        for request in sorted_requests:
            schedule.append(request.track_number)

            self.current_position = request.track_number

        return schedule

    def simulate(self):
        schedule = self.scan()
        total_delay = 0
        print(f"Initial Position: {self.current_position}")
        print(f"Requests: {[request.track_number for request in self.requests]}")
        print("Schedule:")

        for track_number in schedule:
            seek_delay = abs(track_number - self.current_position) * self.transfer_time
            rotation_delay = self.rotation_time

            print(f"Move to Track {track_number}, Delay: {rotation_delay + seek_delay:.5f} ms (Rotation + Seek)")

            self.current_position = track_number
            total_delay += rotation_delay + seek_delay

        print(f"Total Seek Time: {total_delay:.5f} ms")


if __name__ == "__main__":
    disk_scheduler = DiskScheduler()
    disk_scheduler.simulate()
