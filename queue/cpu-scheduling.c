// CPU Scheduling
// Arrival time(at):task arrived
// Waiting time (wt):task waited
// Burst time(bt):task complete its execution
// Completion time (ct):task execution complete
// Turn-Around time (tat):total time taken by task
// tat=ct-at
// wt=tat-bt

#include <stdio.h>
int num_tasks;
int arr_at[10];
int arr_bt[10];
int srttemp_at[10];
int srttemp_bt[10];
int arr_tat[10];
int arr_wt[10];
int wt, tat, at = 0, bt = 0, ct = 0;

void input()
{
    scanf("%d", &num_tasks);
    for (int k = 0; k < num_tasks; k++)
    {
        scanf("%d", &arr_at[k]);
        scanf("%d", &arr_bt[k]);
    }
}

void sorting()
{
    int temp;
    // copying array of arrival time
    for (int i = 0; i < num_tasks; i++)
    {
        srttemp_at[i] = arr_at[i];
    }
    // bubble sorting temporary arrival time array
    for (int i = num_tasks - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (srttemp_at[j] > srttemp_at[j + 1])
            {
                temp = srttemp_at[j];
                srttemp_at[j] = srttemp_at[j + 1];
                srttemp_at[j + 1] = temp;
            }
        }
    }
}

void task_manager(int ind)
{
    tat = 0;
    wt = 0;
    at = srttemp_at[ind];
    bt = srttemp_bt[ind];
    if (at > ct)
        ct += at + bt;
    else
        ct += bt;
    tat = ct - at;
    wt = tat - bt;
    arr_tat[ind] = tat;
    arr_wt[ind] = wt;
}

void display_sorted()
{
    // displaying sorted tasks
    for (int i = 0; i < num_tasks; i++)
    {
        for (int j = 0; j < num_tasks; j++)
        {
            if (srttemp_at[i] == arr_at[j])
            {
                printf("P%d ", j + 1);
                // creating sorted burst time list a/c to arrival time
                srttemp_bt[i] = arr_bt[j];
                break;
            }
        }
    }
    printf("\n", NULL);
}

void task_display()
{
    for (int i = 0; i < num_tasks; i++)
    {
        for (int j = 0; j < num_tasks; j++)
        {
            if (arr_at[i] == srttemp_at[j])
            {
                printf("P%d %d %d\n", i + 1, arr_tat[j], arr_wt[j]);
                break;
            }
        }
    }
}

void avg_time()
{
    float avg_tat = 0.0;
    float avg_wt = 0.0;
    for (int k = 0; k < num_tasks; k++)
    {
        avg_tat += arr_tat[k];
        avg_wt += arr_at[k];
    }
    avg_tat = avg_tat / num_tasks;
    avg_wt = avg_wt / num_tasks;
    printf("%.1f %.0f", avg_tat, avg_wt);
}

int main(int argc, char const *argv[])
{
    input();
    sorting();
    display_sorted();
    for (int i = 0; i < num_tasks; i++)
    {
        task_manager(i);
    }
    task_display();
    avg_time();
    return 0;
}