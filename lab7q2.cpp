#include <iostream>
using namespace std;
int comp = 0;
void display(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
void merge(int a[], int l, int m, int r) {
    int L[50], R[50];
    int n1 = m - l + 1, n2 = r - m;
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    cout << "Left: ";
    display(L, n1);
    cout << "Right: ";
    display(R, n2);
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comp++;
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main() {
    int a[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    mergeSort(a, 0, 7);
    cout << "Sorted prices: ";
    display(a, 8);
    cout << "Total comparisons: " << comp << endl;
    return 0;
}
