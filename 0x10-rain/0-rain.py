#!/usr/bin/python3
"""
Calculates how much water will be retained
"""


def rain(walls):
    """
    Calculates water retained given width of walls
    """
    if walls is None or len(walls) < 2:
        return 0

    water = 0
    n = len(walls)
    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for idx in range(1, n):
        left[idx] = max(left[idx - 1], walls[idx])

    right[n - 1] = walls[n - 1]
    for idx in range(n - 2, -1, -1):
        right[idx] = max(right[idx + 1], walls[idx])

    for idx in range(0, n):
        water += min(left[idx], right[idx]) - walls[idx]

    return water
