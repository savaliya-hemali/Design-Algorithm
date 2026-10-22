
#include <stdio.h>
#include <time.h>

int main() {
    int a[100], n, key, low, high, mid;
    int found = 0;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found == 0) {
        printf("Element not found\n");
    }

    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("CPU Execution Time: %f seconds\n", cpu_time);

    return 0;
}
