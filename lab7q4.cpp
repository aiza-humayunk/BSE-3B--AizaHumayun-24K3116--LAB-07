#include <iostream>
using namespace std;
int n = 7, parts = 0;
void display(int a[]) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
int partition(int a[], int low, int high) {
    parts++;
    int pivot = a[high];
    cout << "Pivot = " << pivot << ", low = " << low << ", high = " << high << endl;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    cout << "Array after partition: ";
    display(a);
    return i + 1;
}
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
int main() {
    int a[] = {40, 20, 70, 10, 60, 30, 50};
    quickSort(a, 0, n - 1);
    cout << "Sorted array: ";
    display(a);
    cout << "Partition operations: " << parts << endl;
    return 0;
}
