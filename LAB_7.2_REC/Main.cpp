#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void FindAndSwapMinMax(int** a, const int k, const int n, int i = 0);
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
    cout << "Swaped matrix:" << endl;
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

void FindAndSwapMinMax(int** a, const int k, const int n, int i) {
    if (i < k) {
        int minRow = i, minCol = 0;
        int maxRow = i, maxCol = 0;
        int minValue = a[i][0], maxValue = a[i][0];

        for (int j = 0; j < n; j++) {
            if (a[i][j] < minValue) {
                minValue = a[i][j];
                minCol = j;
            }
            if (a[i][j] > maxValue) {
                maxValue = a[i][j];
                maxCol = j;
            }
        }

        for (int j = 0; j < n; j++) {
            if (a[i][j] == minValue) {
                minCol = j;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] == maxValue) {
                maxCol = j;
                break;
            }
        }
        Swap(a[minRow][minCol], a[maxRow][maxCol]);
        FindAndSwapMinMax(a, k, n, i + 2);
    }
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
