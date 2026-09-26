#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int linearSerach(int a[], int data, int n) {
    int i;
    for (i = 0; i <= n; i++) {
        if (a[i] == data) {
            return i;
        }
    }
    if (i == n)
        return -1;
}

void selectionSort(int a[], int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(&a[i], &a[min]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void bubbleSort(int a[], int n) {
    int i, j, flag, temp;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int binarySearch(int a[], int n, int data) {
    int left, right, mid;
    left = 0, right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (data == a[mid])
            return mid;
        else if (data < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start, end;
    start = lb;
    end = ub;
    while (start < end) {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
            swap(&a[start], &a[end]);
    }
    swap(&a[lb], &a[end]);
    return end;
}

void quickSort(int a[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int i, j, k, b[ub];
    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
            k++;
        } else {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++) {
        a[k] = b[k];
    }
}

void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int choice, num, res;

    do {
        int array[] = {5, 8, 7, 2, 4, 1, 0, 46, 55, 78, 99993, 9, 6};
        int size = sizeof (array) / sizeof (array[0]);

        printf("1: Linear Search\n");
        printf("2: Selection Sort\n");
        printf("3: Insertion Sort\n");
        printf("4: Bubble Sort\n");
        printf("5: Binary Search\n");
        printf("6: Quick Sort\n");
        printf("7: Merge Sort\n");
        printf("\nScelta:");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("Exit\n");
                break;

            case 1:
                printArray(array, size);
                printf("Insert number to find: ");
                scanf("%d", &num);
                res = linearSerach(array, num, size);
                if (res == -1)
                    printf("Not found\n");
                else
                    printf("Number %d found in pos %d\n", num, res + 1);
                break;

            case 2:
                printArray(array, size);
                selectionSort(array, size);
                printArray(array, size);
                break;

            case 3:
                printArray(array, size);
                insertionSort(array, size);
                printArray(array, size);
                break;

            case 4:
                printArray(array, size);
                bubbleSort(array, size);
                printArray(array, size);
                break;

            case 5:
                mergeSort(array, 0, size);
                printArray(array, size);
                printf("Insert number to find: ");
                scanf("%d", &num);
                res = binarySearch(array, size, num);
                if (res == -1)
                    printf("Not found\n");
                else
                    printf("Number %d found in position %d\n", num, res + 1);
                break;
            case 6:
                printArray(array, size);
                quickSort(array, 0, size);
                printArray(array, size);
                break;
            case 7:
                printArray(array, size);
                mergeSort(array, 0, size-1);
                printArray(array, size);
                break;

            default:
                printf("Not valid!\n");
                break;

        }
    } while (choice != 0);

}

