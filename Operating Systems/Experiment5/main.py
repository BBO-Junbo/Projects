import matplotlib.pyplot as plt
import numpy as np

class MemoryManager:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.memory = self.fixed_partitions()
        self.signal = [True] * n

    # 生成固定分区的存储块，n为分区个数，m为分区的大小
    def fixed_partitions(self):
        # 不同分区的所有初始值都赋为0
        memory = [0] * (self.n * self.m)
        return memory

    #获取内存碎片,memory为一维数组,n为分区个数，m为分区的大小
    def get_fragmentation_condition(self):
        #画横向柱状图，1的部分用浅色，0的部分用深色
        # Reshape the 1D array to 2D
        memory_matrix = np.array(self.memory).reshape(self.n, self.m)
        # Plot the 2D array
        plt.imshow(memory_matrix, cmap='Blues', aspect='auto', interpolation='nearest')
        plt.title('Memory Fragmentation Condition')
        plt.xlabel('Memory Blocks')
        plt.ylabel('Partitions')
        plt.show()


    #向固定分区写入,memory为一维数组，size为本次写入的空间大小，n为本次写入的分区，m为每个分区的大小
    def write_in_fixed_partitions(self,size):
        if size >self.m:
            print(f"Error: Size exceeds partition size")
            return
        for i in range(0,self.n):
            if self.signal[i]:
                for j in range( i * self.m, i * self.m + size):
                    self.memory[j] = 1
                print(f"Write successful in partition {i}")
                self.signal[i] = False
                return
        print(f"Error: Memory is full!!")


#用例
num_partitions = 10
partition_size = 15
memory_manager = MemoryManager(num_partitions, partition_size)

print("Initial memory state:")
print(memory_manager.memory)

write_sizes = [4,3,5,9,10,15,14]
for size in write_sizes:
    memory_manager.write_in_fixed_partitions(size)

print("Memory state after writing:")
print(memory_manager.memory)

memory_manager.get_fragmentation_condition()
