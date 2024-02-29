#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void FindAndSwapMinMax(int** a, const int k, const int n, int i = 0, int currentRow = 0);
void FindMinMaxRecursive(int** a, const int k, const int n, const int currentRow, int currentCol, int& minValue, int& minCol, int& maxValue, int& maxCol);
void Swap(int& a, int& b);

int main() {
    int Low = 7;
    int High = 65;
    int k;
    int n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, k, n);

    FindAndSwapMinMax(a, k, n);
    cout << "Swapped matrix:" << endl;
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j) {
    if (i < k) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, k, n, Low, High, i, j + 1);
        }
        else {
            Create(a, k, n, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int k, const int n, int i, int j) {
    if (i < k) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, k, n, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, k, n, i + 1, 0);
        }
    }
}

void FindAndSwapMinMax(int** a, const int k, const int n, int i, int currentRow) {
    if (currentRow >= k)
        return;

    int minCol = 0, maxCol = 0;
    int minValue = a[currentRow][0], maxValue = a[currentRow][0];

    FindMinMaxRecursive(a, k, n, currentRow, 0, minValue, minCol, maxValue, maxCol);

    Swap(a[currentRow][minCol], a[currentRow][maxCol]);

    FindAndSwapMinMax(a, k, n, i, currentRow + 2);
}

void FindMinMaxRecursive(int** a, const int k, const int n, const int currentRow, int currentCol, int& minValue, int& minCol, int& maxValue, int& maxCol) {
    if (currentCol >= n)
        return;

    if (a[currentRow][currentCol] < minValue) {
        minValue = a[currentRow][currentCol];
        minCol = currentCol;
    }
    if (a[currentRow][currentCol] > maxValue) {
        maxValue = a[currentRow][currentCol];
        maxCol = currentCol;
    }

    FindMinMaxRecursive(a, k, n, currentRow, currentCol + 1, minValue, minCol, maxValue, maxCol);
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
