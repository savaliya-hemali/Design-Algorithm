#include <stdio.h>
#include <time.h>

int a[100], temp[100], pass = 0;

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high) {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];

    pass++;

    printf("Pass %d: ", pass);
    for(i = 0; i < high + 1; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void mergeSort(int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
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
    mergeSort(0, n - 1);
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal merge passes: %d", pass);
    printf("\nCPU Execution Time: %f seconds\n", cpu_time);

    printf("Best Case: O(n log n)\n");
    printf("Average Case: O(n log n)\n");
    printf("Worst Case: O(n log n)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}
