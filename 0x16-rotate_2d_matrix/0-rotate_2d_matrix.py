#!/usr/bin/python3
"""
Rotate 2d Matrux method
"""


def rotate_2d_matrix(matrix):
    n = len(matrix[0])
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            tmp = matrix[i][j]
            ni = n - 1 - i
            nj = n - 1 - j
            matrix[i][j] = matrix[nj][i]
            matrix[nj][i] = matrix[ni][nj]
            matrix[ni][nj] = matrix[j][ni]
            matrix[j][ni] = tmp
