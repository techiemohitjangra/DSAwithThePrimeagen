from typing import Optional
from lib.node import Node


class LinkedList:
    def __init__(self, head: Optional[Node] = None,
                 tail: Optional[Node] = None):
        """
        params:
            self: LinkedList
            head: Node | None
            tail: Node | None
        """
        self.head: Optional[Node] = head
        self.tail: Optional[Node] = tail
        self.length = 0

        # checks if length is 0 or not
        if head is not None:
            self.length = 1
            temp = head
            # iterate until temp becomes same as tail or None
            while temp is not tail and temp is not None:
                temp = temp.next
                self.length += 1

    # special method to overload [] to set value at index [x]
    def __setitem__(self, key: int, item: int) -> bool:
        """
        params:
            self: LinkedList
            index: int
            value: int
        return: bool
        """
        if key >= self.length:
            raise IndexError("Index out of bound!\n")

        curr: int = 0
        temp = self.head

        # iterate until curr index is equal to index or temp becomes None
        while curr is not key and temp is not None:
            temp = temp.next
            curr += 1

        # update value at the curr index and return true on success
        if curr is key and temp is not None:
            temp.value = item
            return True

        return False

    # special method to overload [] to get value at index [x]
    def __getitem__(self, index: int) -> Optional[int]:
        """
        params:
            self: LinkedList
            index: int
        return: int | None
        """
        current: int = 0
        temp = self.head

        # iterate until curr index is equal to index or temp becomes None
        while current is not index and temp is not None:
            temp = temp.next
            current += 1
            # checks if current index is same as required index
            if current is index and temp is not None:
                return temp.value
        return None

    # special method to overload [] to delete value at index [x]
    def __delitem__(self, key: int) -> bool:
        """
        params:
            self: LinkedList
            index: int
        return: int | None
        """
        if key >= self.length:
            raise IndexError("Index out of bound!\n")

        if key == 0 and self.head is not None:
            temp = self.head
            self.head = self.head.next
            del temp
            return True

        if key == self.length-1 and self.tail is not None:
            temp = self.tail
            self.tail = self.tail.prev
            del temp
            return True

        currItem: int = 0
        temp = self.head

        # iterate until curr index is equal to index or temp becomes None
        while currItem is not key and temp is not None:
            temp = temp.next
            currItem += 1

        # update value at the curr index and return true on success
        if temp is not None and temp.prev is not None and temp.next is not None:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev
            del temp
            return True
        return False

    def __len__(self):
        return self.length

    def __str__(self):
        if self.head is None:
            return '<LinkedList>[]'

        str = '<LinkedList>['
        temp = self.head
        while temp.next is not None:
            str += f"{temp.value} <=> "
            temp = temp.next
        str += f"{temp.value}"
        str += ']'
        return str

    def insert(self, index: int, value: int) -> bool:
        """
        params:
            index: int
            value: int
        return: bool
        """
        if index > self.length:
            return False

        if index == 0:
            return self.push_head(value)

        if index == self.length:
            return self.push_tail(value)

        curr: int = 0
        temp = self.head
        while curr is not index and temp is not None:
            temp = temp.next
            curr += 1

        if curr is index and temp is not None and temp.prev is not None:
            newNode = Node(value)
            newNode.next = temp
            newNode.prev = temp.prev
            temp.prev.next = newNode
            temp.prev = newNode

        return False

    def delete_node(self, index: int) -> Optional[int]:
        """
        params:
            self: LinkedList
            index: int
        return: bool
        """
        if index >= self.length:
            return None

        if index == 0:
            return self.pop_head()

        if index == self.length-1:
            return self.pop_tail()

        curr: int = 0
        temp = self.head
        while curr is not index and temp is not None:
            temp = temp.next
            curr += 1

        if temp is not None and temp.prev is not None and temp.next is not None:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev
            value = temp.value
            del temp
            return value

        return False

    def get_head(self) -> Optional[int]:
        """
        params:
            self: LinkedList
        return: int | None
        """
        if self.head is not None:
            return self.head.value
        return None

    def push_head(self, item: int) -> bool:
        """
        params:
            self: LinkedList
            item: int
        return: bool
        """

        newNode = Node(item)

        if self.head is not None:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        else:
            self.head = self.tail = newNode

        return True

    def pop_head(self) -> Optional[int]:
        """
        params:
            self: LinkedList
        return: int | None
        """
        if self.head is not None:
            value = self.head.value
            self.head = self.head.next
            if self.head is not None:
                del self.head.prev
                self.head.prev = None
            return value
        return None

    def get_tail(self) -> Optional[int]:
        """
        params:
            self:LinkedList
        return: int | None
        """
        if self.tail is not None:
            return self.tail.value
        return None

    def push_tail(self, item: int) -> bool:
        """
        params:
            self: LinkedList
            item: int
        return: bool
        """
        newNode = Node(item)

        if self.tail is not None:
            newNode.prev = self.tail
            self.tail.next = newNode
            self.tail = newNode
        else:
            self.head = self.tail = newNode

        return True

    def pop_tail(self) -> Optional[int]:
        """
        params:
            self: LinkedList
        return: int | None
        """
        if self.tail is not None:
            value = self.tail.value
            self.tail = self.tail.prev
            if self.tail is not None:
                del self.tail.next
                self.tail.next = None
            return value
        return None
