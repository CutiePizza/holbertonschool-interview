#!/usr/bin/python3
"""
Making change
"""


def makeChange(coins, total):
    """determine the fewest number of coins
    """
    if not coins:
        return (-1)
    if total in coins:
        return (1)
    coins.sort()
    if (total < coins[0]):
        return (-1)
    n = 0
    i = 0
    j = len(coins) - 1
    while (n < total and j >= 0):
        if (n + coins[j] > total):
            j = j - 1
        else:
            n = n + coins[j]
            i = i + 1
    if (n == total):
        return (i)
    return (-1)
