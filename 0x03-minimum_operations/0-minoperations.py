#!/usr/bin/python3


"""
Calculates the minimum operations necessary to reach a n quantity of characters
starting with a single character and being only able to perform two actions
copy all and paste
"""


def minOperations(n):
    answer = 0
    x = 2
    while n > 1:
        while n % x == 0:
            answer += x
            n /= x
        x += 1
    return answer
