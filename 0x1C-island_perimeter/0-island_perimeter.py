#!/usr/bin/python3
"""
0-island perimeter
"""


def island_perimeter(grid):
    """
    return Island's perimeter
    """
    p = 0
    for j in range(len(grid)):
        for i in range(len(grid[j])):
            if (grid[j][i] == 1):
                if (j - 1 < 0 or grid[j - 1][i] == 0):
                    p += 1
                if (i - 1 < 0 or grid[j][i - 1] == 0):
                    p += 1
                if (i + 1 >= len(grid[j]) or grid[j][i + 1] == 0):
                    p += 1
                if (j + 1 >= len(grid) or grid[j + 1][i] == 0):
                    p += 1
    return p
