import threading
import time
import random

# 共享缓冲区
buffer = []
buffer_size = 5

# 信号量
mutex = threading.Semaphore(1)  # 控制对缓冲区的互斥访问
empty = threading.Semaphore(buffer_size)  # 表示缓冲区的空槽数量
full = threading.Semaphore(0)  # 表示缓冲区的满槽数量

# 生产者函数
def producer(id):
    global buffer
    while True:
        item = random.randint(1, 100)
        time.sleep(random.uniform(0.1, 1.0))  # 模拟生产过程

        empty.acquire()  # 等待缓冲区有空槽
        mutex.acquire()  # 获取对缓冲区的互斥访问
        buffer.append(item)
        print(f"Producer {id} produced item {item}. Buffer: {buffer}")
        mutex.release()  # 释放对缓冲区的互斥访问
        full.release()  # 发布一个满槽

# 消费者函数
def consumer(id):
    global buffer
    while True:
        full.acquire()  # 等待缓冲区有满槽
        mutex.acquire()  # 获取对缓冲区的互斥访问
        item = buffer.pop(0)
        print(f"Consumer {id} consumed item {item}. Buffer: {buffer}")
        mutex.release()  # 释放对缓冲区的互斥访问
        empty.release()  # 发布一个空槽
        time.sleep(random.uniform(0.1, 1.0))  # 模拟消费过程

# 创建生产者和消费者线程
producer1 = threading.Thread(target=producer, args=(1,))
producer2 = threading.Thread(target=producer, args=(2,))
consumer1 = threading.Thread(target=consumer, args=(1,))
consumer2 = threading.Thread(target=consumer, args=(2,))

# 启动线程
producer1.start()
producer2.start()
consumer1.start()
consumer2.start()

# 主线程等待所有线程结束
producer1.join()
producer2.join()
consumer1.join()
consumer2.join()
