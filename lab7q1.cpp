#include <iostream>
using namespace std;

int mergeCount = 0;
int N;

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

void merge(int a[], int l, int m, int r){
    int L[100], R[100];
    int nl = m - l + 1, nr = r - m;
    for (int i = 0; i < nl; i++) L[i] = a[l + i];
    for (int j = 0; j < nr; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < nl && j < nr) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else              a[k++] = R[j++];
    }
    while (i < nl) a[k++] = L[i++];
    while (j < nr) a[k++] = R[j++];

    mergeCount++;
    cout << "After merge #" << mergeCount << " [" << l << ".." << r << "]: ";
    printArr(a, N);
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main(){
    int a[] ={78, 45, 92, 63, 45, 88, 51, 70};
    N = 8;
    mergeSort(a,0,N - 1);
    cout << "Sorted: ";
    printArr(a,N);
    cout << "Total merge operations: " << mergeCount << "\n";
    return 0;
}
