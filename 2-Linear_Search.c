
#include <stdio.h>
#include <time.h>

int main() {
    int a[100], n, key, i, found = 0;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
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
