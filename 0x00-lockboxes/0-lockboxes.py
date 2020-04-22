"""
Lockboxes, checks if all boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Lockboxes, checks if all boxes can be opened
    Return true or false
    """
    if len(boxes) == 0:
        return True
    visited = {0}
    stack_of_keys = [0]

    while stack_of_keys:
        room = stack_of_keys.pop()
        for key in boxes[room]:
            if isinstance(
                    key, int) and 0 <= key < len(boxes) and key not in visited:
                visited.add(key)
                stack_of_keys.append(key)

    return len(boxes) == len(visited)
