class My_stack:
    # Constructor
    def __init__(self):
        self.items = list()
        self.top = 0
    # Adds element to the My_stack
    def push(self, item):
        self.items.append(item)
        self.top += 1
        return True
    # Removes element from My_stack
    def pop(self):
        if self.top <= 0:
            return ("stack underflow")
        ret = self.items.pop()
        self.top -= 1
        return ret
    # Peeks element from My_stack
    def peek(self):
        if self.isEmpty():
            return ("stack is empty")
        ret = self.items[self.top - 1]
        return ret
    # Size of the My_stack
    def size(self) -> int:
        return self.top
    # is empty the My_stack
    def isEmpty(self) -> bool:
        return self.top == 0

s = My_stack()
for i in range(9):
    s.push(i)
print(s.items)
print(f"remove item: {s.pop()}")
print(s.items)
for i in range(9):
    print(f"removed item: {s.pop()}")
    print(s.items)
    print(f"top of stack: {s.peek()}")
    print(f"is Empty? {s.isEmpty()}")
    print()

