#include <iostream>
using namespace std;
void display(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
void countSort(int a[], int n, int exp, int show) {
    int output[100], freq[10] = {0};
    for (int i = 0; i < n; i++) freq[(a[i] / exp) % 10]++;
    if (show) {
        cout << "Frequency: ";
        display(freq, 10);
    }
    for (int i = 1; i < 10; i++) freq[i] += freq[i - 1];
    if (show) {
        cout << "Cumulative: ";
        display(freq, 10);
    }
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[freq[d] - 1] = a[i];
        freq[d]--;
    }
    if (show) {
        cout << "Output: ";
        display(output, n);
    }
    for (int i = 0; i < n; i++) a[i] = output[i];
}
int radixSort(int a[], int n, int show) {
    int max = a[0], passes = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    for (int exp = 1; max / exp > 0; exp *= 10) {
        passes++;
        cout << "Pass " << passes << endl;
        countSort(a, n, exp, show);
        cout << "Array after pass " << passes << ": ";
        display(a, n);
    }
    return passes;
}
int main() {
    int a[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = 8;
    cout << "Original array: ";
    display(a, n);
    int p = radixSort(a, n, 0);
    cout << "Sorted array: ";
    display(a, n);
    cout << "Total passes: " << p << endl;
    return 0;
}
