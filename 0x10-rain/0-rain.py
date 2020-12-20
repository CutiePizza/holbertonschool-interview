#!/usr/bin/python3
"""
Rain task
"""
def rain(walls):
    """
    Method that calculates how much water can it retain
    """
    s = 0
    for i in range(1, len(walls) - 1) : 
        left = walls[i]
        for j in range(i) :
            left = max(left, walls[j]);  
        right = walls[i]   
        for j in range(i + 1 , len(walls)) : 
            right = max(right, walls[j])
        s = s + (min(left, right) - walls[i])
    return s
