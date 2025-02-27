#include <iostream>
using namespace std;

void multiplyMatrices(int A[][2], int B[][2], int result[][2], int n)
{
    for (size_t i = 0; i < n; i++) // rows
    {
        for (size_t j = 0; j < n; j++) // columns
        {
            result[i][j] = 0;              // preparation
            for (size_t k = 0; k < n; k++) // n is a number of row and columns for result
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void display(int matrix[][2], int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << matrix[i][j] << " ";
            if (j == column - 1)
                cout << endl;
        }
    }
}

template <size_t N>
void recursiveM(int (&A)[N][N], int (&B)[N][N], int (&result)[N][N], int n)
{
    // Implementation for recursive matrix multiplication can be added here
}

int main()
{
    int firstMatrix[2][2] = {{1, 2},
                             {4, 5}};

    int secondMatrix[2][2] = {{9, 8},
                              {6, 5}};
    int result[2][2];
    int size = 2; // sizes of 1 and 2 matrix

    multiplyMatrices(firstMatrix, secondMatrix, result, size);

    cout << "Resultant Matrix: " << endl;
    display(result, 2, 2);

    return 0;
}