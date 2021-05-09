#!/usr/bin/python3
"""Python3 program for Pascal's Triangle
"""


def next_row(row):
    """Returns the next row of Pascal's triangle."""
    n = len(row)
    new_row = [row[0]] + [row[i] + row[i+1] for i in range(n - 1)] + [row[-1]]
    return new_row


def pascal_triangle(n):
    """
    return pascals triangle
    """
    if (n <= 0):
        return []
    row1 = [1]
    triangle = [row1]
    for i in range(1, n):
        triangle.append(next_row(triangle[-1]))
    return triangle
