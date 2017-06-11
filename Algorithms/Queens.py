"""N Queens Problem."""

import sys


def can_place(x, k, i):
    """
    Check if you can place a queen in k^th row and i^th column.

    k in the row.
    i is the column.
    """
    for j in range(k):
        if x[j] == i or abs(x[j] - i) == abs(j-k):
            return False
    return True


def n_queens(x, k, n):
    """
    The recursive method.

    x refers to the vector.
    k refers to the row.
    n is the number of queens or n x n chess board.
    """
    for i in range(n):
        if can_place(x, k, i):
            x[k] = i
            if(k == n - 1):
                print(x)
            else:
                n_queens(x, k+1, n)


def main():
    """The main function."""
    n = int(sys.argv[1])
    x = [0] * n
    n_queens(x, 0, n)


if __name__ == '__main__':
    main()

"""
Output
My Repositories/Misc-Mini/Algorithms on  master [!?]
➜ python Queens.py 4
[1, 3, 0, 2]
[2, 0, 3, 1]
"""
