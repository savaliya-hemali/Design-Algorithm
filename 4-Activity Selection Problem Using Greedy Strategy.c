
#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, temp;
    int start[100], finish[100];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities by finish time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    clock_t begin = clock();

    printf("\nSelected activities:\n");

    if (n > 0) {
        printf("Activity with start %d and finish %d\n",
               start[0], finish[0]);

        int lastFinish = finish[0];

        for (i = 1; i < n; i++) {
            if (start[i] >= lastFinish) {
                printf("Activity with start %d and finish %d\n",
                       start[i], finish[i]);
                lastFinish = finish[i];
            }
        }
    }

    clock_t end = clock();

    printf("\nCPU Execution Time: %f seconds\n",
           (double)(end - begin) / CLOCKS_PER_SEC);

    return 0;
}
