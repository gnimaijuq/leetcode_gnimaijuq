#include<stdio.h>

void swap(int * a, int * b) {
    int tmp = * a;
    * a = * b;
    * b = tmp;
}

// 循环不变量arr[0...i)已排序,[i...n)未排序
void SelectionSort(int * arr, int arrSize) {
    for (int i = 0; i < arrSize; i ++) {
        int minIndex = i;
        for (int j = i; j < arrSize; j ++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr + i, arr + minIndex);
    }
}

// 循环不变量arr[0...i)未排序,[i...n)已排序
void SelectionSort2(int * arr, int arrSize) {
    for (int i = arrSize - 1; i >= 0; i --) {
        int maxIndex = i;
        for (int j = i; j >= 0; j --) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr + i, arr + maxIndex);
    }
}

int main(int argc, char ** argv) {
    int a[] = {10,2,6,4,1,5,9,24,3};
    SelectionSort2(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); i ++) {
        printf("%d ", a[i]);
    }
}
