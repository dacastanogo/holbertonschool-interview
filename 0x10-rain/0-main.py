#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":

    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print("[0, 1, 0, 2, 0, 3, 0, 4]")
    print(rain(walls))

    walls = [0, 1, 0, 1, 0, 1, 0, 1]
    print("[0, 1, 0, 1, 0, 1, 0, 1]")
    print(rain(walls))

    walls = [0, 1, 0, 2, 0, 3, 0]
    print("[0, 1, 0, 2, 0, 3, 0]")
    print(rain(walls))

    walls = [0, 4, 0, 3, 0, 2, 0, 1]
    print("[0, 4, 0, 3, 0, 2, 0, 1]")
    print(rain(walls))

    walls = [1, 0, 2, 0, 3, 0, 4, 0]
    print("[1, 0, 2, 0, 3, 0, 4, 0]")
    print(rain(walls))

    walls = [0, 1]
    print("[0, 1]")
    print(rain(walls))

    walls = [0]
    print("[0]")
    print(rain(walls))

    walls = [1, 2]
    print("[1, 2]")
    print(rain(walls))

    walls = [1, 0, 2]
    print("[1, 0, 2]")
    print(rain(walls))

    walls = [1]
    print("[1]")
    print(rain(walls))
