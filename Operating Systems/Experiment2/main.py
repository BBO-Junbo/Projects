import multiprocessing
import time

def sender(pipe, messages):
    for message in messages:
        print(f"Sender sending message: {message} ")
        pipe.send(message)
        time.sleep(1)  # 模拟发送消息的耗时操作
    pipe.close()

def receiver(pipe, name):
    while True:
        try:
            received_message = pipe.recv()
            print(f"{name} received message: {received_message} ")
        except EOFError:
            break

if __name__ == "__main__":
    # 创建管道
    pipe1_parent, pipe1_child = multiprocessing.Pipe()
    pipe2_parent, pipe2_child = multiprocessing.Pipe()

    # 创建发送者进程
    sender1_process = multiprocessing.Process(target=sender, args=(pipe1_child, ["Message 1", "Message 2"]))
    sender2_process = multiprocessing.Process(target=sender, args=(pipe2_child, ["Message 3", "Message 4"]))
    sender3_process = multiprocessing.Process(target=sender, args=(pipe2_child, ["Message 5", "Message 6"]))

    # 创建接收者进程
    receiver1_process = multiprocessing.Process(target=receiver, args=(pipe1_parent, "Receiver 1"))
    receiver2_process = multiprocessing.Process(target=receiver, args=(pipe2_parent, "Receiver 2"))

    # 启动进程
    sender1_process.start()
    sender2_process.start()
    sender3_process.start()
    receiver1_process.start()
    receiver2_process.start()

    # 等待发送者进程结束
    sender1_process.join()
    sender2_process.join()

    # 关闭管道，通知接收者进程结束
    pipe1_parent.close()
    pipe2_parent.close()

    # 等待接收者进程结束
    receiver1_process.join()
    receiver2_process.join()

