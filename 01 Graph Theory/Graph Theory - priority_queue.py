import heapq
class PriorityQueue:
    def __init__(self, key=None, heap=[]):
        self.key = key
        self.heap = heapq.heapify(heap) if heap else []
    def __bool__(self): return bool(self.heap)
    def __len__(self): return len(self.heap)
    def __iter__(self):
        if self.key: return map(lambda x: x[1], self.heap)
        else: return iter(self.heap)
    def __str__(self):
        if self.key: str(map(lambda x: str(x[1]), self.heap))
        else: return str(self.heap)
    def push(self, x):
        if self.key: heapq.heappush(self.heap, (self.key(x), x))
        else: heapq.heappush(self.heap, x)
    def top(self):
        if self.key: return self.heap[0][1]
        else: return self.heap[0]
    def pop(self):
        if self.key: return heapq.heappop(self.heap)[1]
        else: return heapq.heappop(self.heap)
    def pushpop(self, x):
        if self.key: return heapq.heappushpop(self.heap, (self.key(x), x))[1]
        else: return heapq.heappop(self.heap)
