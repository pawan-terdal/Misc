"""Program to find Subset Sum."""

import sys


def subset_sum(arr, sub_arr, pos, k, given_sum):
    """Subset sum function."""
    n = len(arr)
    if(pos == n):
        return
    for i in range(k, n):
        sub_arr[pos] = arr[i]
        sum_of_array = sum(sub_arr[:pos+1])
        if(sum_of_array == given_sum):
            print(sub_arr[:pos+1])
        if(sum_of_array > given_sum):
            return
        subset_sum(arr, sub_arr, pos + 1, i + 1, given_sum)


def main():
    """The main function."""
    arr = sys.argv[1:-1]
    arr = [int(i) for i in arr]
    given_sum = int(sys.argv[-1])
    subset_sum(arr, [0] * len(arr), 0, 0, given_sum)


if __name__ == '__main__':
    main()

"""
Output
My Repositories/Misc-Mini/Algorithms on  master [!?]
➜ python Subset.py 1 2 5 6 8 8
[1, 2, 5]
[2, 6]
[8]
"""
