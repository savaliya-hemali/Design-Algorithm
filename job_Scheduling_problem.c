#include <stdio.h>

struct Job
{
    char id[10];
    int deadline;
    int profit;
};

int main()
{
    int n, i, j;
    int maxDeadline = 0;
    int totalProfit = 0;

    struct Job jobs[20], temp;
    int slot[20];

    /* Input number of jobs */
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    /* Input jobs */
    printf("\nEnter Job ID, Deadline and Profit:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d",
              jobs[i].id,
              &jobs[i].deadline,
              &jobs[i].profit);

        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    /* Sort jobs according to decreasing profit */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (jobs[i].profit < jobs[j].profit)
            {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    /* Initialize slots */
    for (i = 0; i < maxDeadline; i++)
    {
        slot[i] = -1;
    }

    /* Schedule jobs */
    for (i = 0; i < n; i++)
    {
        for (j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                totalProfit = totalProfit + jobs[i].profit;
                break;
            }
        }
    }

    /* Display result */
    printf("\nScheduled Jobs: ");

    for (i = 0; i < maxDeadline; i++)
    {
        if (slot[i] != -1)
        {
            printf("%s ", jobs[slot[i]].id);
        }
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}
/*
Enter number of jobs: 5

Enter Job ID, Deadline and Profit:
J1 2 60
J2 1 100
J3 3 20
J4 2 40
J5 1 20

Scheduled Jobs: J1 J2 J3 
Total Profit = 180
*/  