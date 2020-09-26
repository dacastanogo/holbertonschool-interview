#!/usr/bin/python3
"""
Write a method determines
if a given data set represents valid UTF-8 encoding
"""


def validUTF8(data):
    """
    method determines valid UTF-8 encoding
    """
    index = 0
    for i, m in enumerate(data):
        if (index == 0):
            if (m >> 5) == 0b110:
                index = 1
            elif (m >> 4) == 0b1110:
                index = 2
            elif (m >> 3) == 0b11110:
                index = 3
            elif (m >> 7):
                return False
        elif (index > 0):
            if (m >> 6) != 0b10:
                return False
            index -= 1
    return True
