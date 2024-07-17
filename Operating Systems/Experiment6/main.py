from collections import OrderedDict
import matplotlib.pyplot as plt

class external_memory:
    def __init__(self, capacity):
        self.capacity = capacity
        self.pages = {}

    def is_page_present(self, page):
        return page in self.pages

    def add_page(self, page):
        if len(self.pages) >= self.capacity:
            print("external_memory is full")
        self.pages[page] = 1

    def get_page(self, page):
        if self.is_page_present(page):
            return page
        else:
            return False

class virtual_memory:
    def __init__(self, capacity):
        self.capacity = capacity
        self.pages = {}

    def is_page_present(self, page):
        return page in self.pages

class LFU:
    def __init__(self, capacity, external_memory, virtual_memory):
        self.external_memory = external_memory
        self.virtual_memory = virtual_memory
        self.page_frequency = {}
        self.hit_count = 0
        self.total_requests = 0
        self.log = []

    def access_page(self, page):
        self.total_requests += 1
        if self.virtual_memory.is_page_present(page):
            self.hit_count += 1
            self.page_frequency[page] += 1
            self.log.append(f"LFU: Page {page} - Hit")
        else:
            if len(self.virtual_memory.pages) >= self.virtual_memory.capacity:
                least_frequent_page = min(self.page_frequency, key=self.page_frequency.get)
                del self.page_frequency[least_frequent_page]
                del self.virtual_memory.pages[least_frequent_page]
                self.log.append(f"LFU: Evicted Page {least_frequent_page}")

            self.virtual_memory.pages[page] = 1
            self.page_frequency[page] = 1
            self.log.append(f"LFU: Added Page {page}")

class LRU:
    def __init__(self, capacity, external_memory, virtual_memory):
        self.external_memory = external_memory
        self.virtual_memory = virtual_memory
        self.page_order = OrderedDict()
        self.hit_count = 0
        self.total_requests = 0
        self.log = []

    def access_page(self, page):
        self.total_requests += 1
        if self.virtual_memory.is_page_present(page):
            self.hit_count += 1
            if page in self.page_order:
                self.page_order.move_to_end(page)
            else:
                self.page_order[page] = True
            self.log.append(f"LRU: Page {page} - Hit")
        else:
            if len(self.virtual_memory.pages) >= self.virtual_memory.capacity:
                evicted_page = next(iter(self.page_order))
                del self.page_order[evicted_page]
                del self.virtual_memory.pages[evicted_page]
                self.log.append(f"LRU: Evicted Page {evicted_page}")

            self.virtual_memory.pages[page] = 1
            self.page_order[page] = True
            self.log.append(f"LRU: Added Page {page}")

class FIFO:
    def __init__(self, capacity, external_memory):
        self.external_memory = external_memory
        self.virtual_memory = []
        self.page_set = set()
        self.capacity = capacity
        self.hit_count = 0
        self.total_requests = 0
        self.log = []

    def is_page_present(self, page):
        return page in self.page_set

    def access_page(self, page):
        self.total_requests += 1
        if self.is_page_present(page):
            self.hit_count += 1
            self.log.append(f"FIFO: Page {page} - Hit")
        else:
            if len(self.virtual_memory) >= self.capacity:
                oldest_page = self.virtual_memory.pop(0)
                self.page_set.remove(oldest_page)
                self.log.append(f"FIFO: Evicted Page {oldest_page}")

            self.virtual_memory.append(page)
            self.page_set.add(page)
            self.log.append(f"FIFO: Added Page {page}")

def simulate_algorithm(algorithm, page_sequence):
    for page in page_sequence:
        algorithm.access_page(page)

    hit_rate = algorithm.hit_count / algorithm.total_requests
    print(f"Hit rate for {algorithm.__class__.__name__}: {hit_rate * 100:.2f}%")


    with open(f"{algorithm.__class__.__name__}_log.txt", "w") as log_file:
        for entry in algorithm.log:
            log_file.write(entry + "\n")

    return hit_rate

# Example usage with a more complex test case:
external_mem = external_memory(5)
virtual_mem = virtual_memory(3)

page_sequence = [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]

lfu_algorithm = LFU(3, external_mem, virtual_mem)
lru_algorithm = LRU(3, external_mem, virtual_mem)
fifo_algorithm = FIFO(3, external_mem)

lfu_hit_rate = simulate_algorithm(lfu_algorithm, page_sequence)
lru_hit_rate = simulate_algorithm(lru_algorithm, page_sequence)
fifo_hit_rate = simulate_algorithm(fifo_algorithm, page_sequence)

# Plot hit rates
algorithms = ['LFU', 'LRU', 'FIFO']
hit_rates = [lfu_hit_rate, lru_hit_rate, fifo_hit_rate]

plt.bar(algorithms, hit_rates, color=['blue', 'green', 'orange'])
plt.xlabel('Page Replacement Algorithm')
plt.ylabel('Hit Rate')
plt.title('Hit Rate Comparison')
plt.ylim(0, 1)
plt.show()
