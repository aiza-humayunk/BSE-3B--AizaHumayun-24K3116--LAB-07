#include <iostream>
using namespace std;
int n = 7, comp = 0;
void display(int a[]) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comp++;
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[low], a[i - 1]);
    cout << "Pivot = " << pivot << ", array: ";
    display(a);
    return i - 1;
}
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
int main() {
    int a[] = {55, 25, 75, 15, 65, 35, 45};
    quickSort(a, 0, n - 1);
    cout << "Sorted array: ";
    display(a);
    cout << "Total comparisons: " << comp << endl;
    return 0;
}
