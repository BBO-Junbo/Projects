import threading
import random
import time

# 缓冲区
buffer = []
buffer_size = int(input("Please enter the size of buffer:"))

# 用户输入生产者和消费者的数量
num_producers = int(input("Please enter the number of producers: "))
num_consumers = int(input("Please enter the number of consumers: "))

# 用户输入程序执行的时间（秒）
execution_time = int(input("Please enter the execution time (seconds): "))

# 信号量
mutex = threading.Semaphore(1)
empty = threading.Semaphore(buffer_size)
full = threading.Semaphore(0)

# 计数器用于跟踪生产和消费的数量
items_produced = 0
items_consumed = 0

# 标志变量用于控制线程运行时间
running_flag = True

def producer(id):
    global buffer
    global items_produced
    global running_flag
    while running_flag:
        item = random.randint(1, 100)
        time.sleep(random.uniform(0.1, 1.0))  # 模拟生产过程
        empty.acquire()
        mutex.acquire()
        buffer.append(item)
        items_produced += 1
        mutex.release()
        full.release()
        print(f"Producer {id} produced item {item}. Buffer: {buffer}")

def consumer(id):
    global buffer
    global items_consumed
    global running_flag
    while running_flag or items_consumed < items_produced:
        full.acquire()
        mutex.acquire()
        item = buffer.pop(0)
        items_consumed += 1
        mutex.release()
        empty.release()
        print(f"Consumer {id} consumed item {item}. Buffer: {buffer}")
        time.sleep(random.uniform(0.1, 1.0))  # 模拟消费过程

# 创建生产者和消费者线程
producers = [threading.Thread(target=producer, args=(i,)) for i in range(1, num_producers + 1)]
consumers = [threading.Thread(target=consumer, args=(i,)) for i in range(1, num_consumers + 1)]

# 启动线程
for producer_thread in producers:
    producer_thread.start()

for consumer_thread in consumers:
    consumer_thread.start()

# 主线程等待指定的执行时间
time.sleep(execution_time)
running_flag = False  # 设置标志变量以停止线程

# 等待所有线程结束
for producer_thread in producers:
    producer_thread.join()

for consumer_thread in consumers:
    consumer_thread.join()

print("All threads have finished.")
