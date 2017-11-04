"""M Coloring Problem."""


def validity_check(vertex, matrix, n, color, vector):
    """Check if Color is valid."""
    for i in range(n):
        if matrix[vertex][i] != 0 and vector[i] == color:
            return False
    return True


def m_color(vertex, matrix, n, m, vector):
    """M Coloring."""
    if vertex == n:
        print(vector)
        return
    for i in range(1, m + 1):
        if validity_check(vertex, matrix, n, i, vector):
            vector[vertex] = i
            m_color(vertex + 1, matrix, n, m, vector)
            vector[vertex] = 0


def main():
    """Main function."""
    print("Enter number of vertices : ")
    n = int(input())
    print("Enter number of colors : ")
    m = int(input())
    print("Enter Matrix : ")
    matrix = []
    for j in range(n):
        row = input().split()
        row = [int(i) for i in row]
        matrix.append(row)
    vector = [0] * n
    m_color(0, matrix, n, m, vector)


if __name__ == '__main__':
    main()
