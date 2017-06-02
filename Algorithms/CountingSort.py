#!/usr/bin/python
"""Counting Sort."""

import random


def counting_sort(array):
    """Counting Sort."""
    max_element = max(array)
    freq = [0] * (max_element + 1)
    for element in array:
        freq[element] += 1
    for i in range(max_element):
        freq[i + 1] += freq[i]
    sorted_array = [0] * (len(array))
    for element in array:
        freq[element] -= 1
        sorted_array[freq[element]] = element
    print(sorted_array)


def main():
    """Main function."""
    array = [random.randint(0, 100) for i in range(20)]
    print(array)
    counting_sort(array)


if __name__ == '__main__':
    main()
