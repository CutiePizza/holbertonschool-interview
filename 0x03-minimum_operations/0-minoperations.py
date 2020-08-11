#!/usr/bin/python3
"""
Interview task
"""
def minOperations(n):
    copyAll = 1
    past = 0
    i = 0
    for j in range(1, n//2):
        if n % j == 0:
            i = j
    past = i
    if (past == n):
        print("haha")
        return (past + copyAll)
    else:
        copyAll += 1
        while (past != i):
            past += 1
        return (past + copyAll + 1)
