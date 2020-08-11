#!/usr/bin/python3
"""
Interview task
"""


def minOperations(n):
    if n == 1 or n == 0:
        return 0
    elif n == 2:
        return 2
    else:
        for i in range(n - 1, 0, -1):
            if n % i == 0:
                op = n // i
                return op + minOperations(i)