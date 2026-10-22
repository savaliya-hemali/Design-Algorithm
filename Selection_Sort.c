#include <stdio.h>
#include <time.h>

int main() {
    int a[100], n, i, j, min, temp, pass = 0;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    for(i = 0; i < n - 1; i++) {
        min = i;

        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        pass++;

        printf("Pass %d: ", pass);
        for(j = 0; j < n; j++)
            printf("%d ", a[j]);
        printf("\n");
    }

    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal passes: %d", pass);
    printf("\nCPU Execution Time: %f seconds\n", cpu_time);

    printf("Best Case: O(n^2)\n");
    printf("Average Case: O(n^2)\n");
    printf("Worst Case: O(n^2)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
