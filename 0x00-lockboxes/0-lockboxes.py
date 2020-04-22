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
    lockers = list(range(1, len(boxes)))
    keys = set(boxes[0])
    x = 0
    while x < len(lockers):
        if lockers[x] in keys:
            keys.update(boxes[lockers[x]])
            keys.remove(lockers[x])
            lockers.remove(lockers[x])
            x = 0
        else:
            x += 1
    if lockers == []:
        return True
    else:
        return False
