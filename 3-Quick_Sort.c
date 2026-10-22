#include <stdio.h>
#include <time.h>

int a[100], pass = 0;

int partition(int low, int high) {
    int pivot = a[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    pass++;
    printf("Pass %d: ", pass);
    for(j = 0; j < high + 1; j++)
        printf("%d ", a[j]);
    printf("\n");

    return i + 1;
}

void quickSort(int low, int high) {
    if(low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();
    quickSort(0, n - 1);
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal partition passes: %d", pass);
    printf("\nCPU Execution Time: %f seconds\n", cpu_time);

    printf("Best Case: O(n log n)\n");
    printf("Average Case: O(n log n)\n");
    printf("Worst Case: O(n^2)\n");
    printf("Space Complexity: O(log n) average\n");

    return 0;
}
