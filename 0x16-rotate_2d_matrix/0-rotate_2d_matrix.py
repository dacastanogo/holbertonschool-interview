#!/usr/bin/python3
"""
0-rotate_2d_matrix.py
"""


def rotate_2d_matrix(matrix):
    """function that rotates an n x n 2D matrix by 90 degrees"""

    # Evaluate matrix size
    size = len(matrix)

    # Make a (hard) copy of matrix with swapped elements
    # along the matrix diagonal
    copy_1 = [[0 for j in range(size)] for i in range(size)]
    for i in range(size):
        for j in range(size):
            copy_1[i][j] = matrix[j][i]
    # Make a (hard) copy of copy_1 with swapped elements
    # along the mid-width vertical axis
    copy_2 = [[0 for j in range(size)] for i in range(size)]
    for i in range(size):
        for j in range(size):
            copy_2[i][j] = copy_1[i][size - 1 - j]

    # Copy the values in matrix (matrix keeps the same ids,
    # only the values change) -> "Edit in Place"
    for i in range(size):
        for j in range(size):
            matrix[i][j] = copy_2[i][j]
