from collections import OrderedDict

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def display(self):
        current = self.head
        if not current:
            return
        print(current.value, end='')
        current = current.next
        while current:
            print(f' {current.value}', end='')
            current = current.next
        print()

    def remove_duplicates(self):
        if not self.head:
            return

        value_map = OrderedDict()
        current = self.head
        value_map[current.value] = True

        while current.next:
            if value_map.get(current.next.value):
                current.next = current.next.next
                if not current.next:
                    self.tail = current
            else:
                value_map[current.next.value] = True
                current = current.next

def solve():
    n = int(input())
    elements = [int(x) for x in input().split()]
    ll = LinkedList()
    for x in elements:
        ll.append(x)
    ll.remove_duplicates()
    ll.display()


def main():
    
    ntc = int(input())
    for _ in range(ntc):
        solve()
    
if __name__ == "__main__":
    main()
