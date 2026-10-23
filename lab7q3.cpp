#include <iostream>
using namespace std;
int calls = 0, merges = 0, comp = 0;
void merge(int a[], int temp[], int l, int m, int r) {
    merges++;
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        comp++;
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int x = l; x <= r; x++) a[x] = temp[x];
}
void mergeSort(int a[], int temp[], int l, int r) {
    calls++;
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, temp, l, m);
        mergeSort(a, temp, m + 1, r);
        merge(a, temp, l, m, r);
    }
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Error: invalid size" << endl;
        return 0;
    }
    int *a = new int[n];
    int *temp = new int[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, temp, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    cout << "Recursive calls: " << calls << endl;
    cout << "Merge operations: " << merges << endl;
    cout << "Comparisons: " << comp << endl;
    
    delete[] a;
    delete[] temp;
    return 0;
}
