#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

# expected True
boxes = []
print(canUnlockAll(boxes))

# expected True
boxes = [[]]
print(canUnlockAll(boxes))

# expected True
boxes = [[1]]
print(canUnlockAll(boxes))

# expected True
boxes = [[2]]
print(canUnlockAll(boxes))

# expected True
boxes = [[1], [2]]
print(canUnlockAll(boxes))

# expected False
boxes = [[3], [2]]
print(canUnlockAll(boxes))

# expected True
boxes = [[1], []]
print(canUnlockAll(boxes))

# expected False
boxes = [[], [2]]
print(canUnlockAll(boxes))
