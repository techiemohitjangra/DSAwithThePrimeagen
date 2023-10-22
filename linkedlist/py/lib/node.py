from typing import Optional


class Node:
    def __init__(self, value: int = 0):
        self.prev: Optional[Node] = None
        self.value: int = value
        self.next: Optional[Node] = None
