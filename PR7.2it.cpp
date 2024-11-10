#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int SumMinOddRows(int** a, const int k, const int n) {
    int sum = 0;
    for (int i = 1; i < k; i += 2) { 
        int minElement = a[i][0]; // Початковий мінімум — перший елемент рядка
        for (int j = 1; j < n; j++) {
            if (a[i][j] < minElement) {
                minElement = a[i][j];
            }
        }
        sum += minElement;
    }
    return sum;
}

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int k, n;

    cout << "k (rows) = ";
    cin >> k;
    cout << "n (columns) = ";
    cin >> n;

    // Динамічне виділення пам'яті для матриці
    int** a = new int* [k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    Create(a, k, n, Low, High);
    cout << "Generated Matrix:" << endl;
    Print(a, k, n);

    int sumMinOddRows = SumMinOddRows(a, k, n);
    cout << "Sum of minimum elements in odd rows = " << sumMinOddRows << endl;

    for (int i = 0; i < k; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
