/*
Program: First Come First Served Scheduling algorithm
Language: C
*/

#include <stdio.h>
#include <stdlib.h>

struct PCB{
    int pid, arrival, burst, completion, turnaround;
}p[10], temp;

void pline(int x){
    for(int i=0; i<x; i++){
        printf("-");
    }
    printf("\n");
}

int main()
{
    int i, num, j;
    float sum =0.0, avg=0.0;

    printf("Enter the number of process: ");
    scanf("%d", &num);

    for(i=0; i<num; i++){
        p[i].pid = i+1;
        printf("Enter the arrival and burst time of process %d: ", p[i].pid);
        scanf("%d%d", &p[i].arrival, &p[i].burst);
    }

    // sort the array in order of their arrival time
    for(i=0; i<num-1; i++){
        for(j=0; j<num-i-1; j++){
            if(p[j].arrival > p[j+1].arrival){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // finding the completion and turnaround time
    for(i=0; i<num; i++){
        sum += p[i].burst;
        p[i].completion = sum;
        p[i].turnaround = p[i].completion - p[i].arrival;
    }
    sum = 0;
    pline(44);
    printf("PID\tArrival\tBurst\tComp\tTurnaround\n");
    pline(44);
    for(i=0; i<num; i++){
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround);
        sum += p[i].turnaround;
    }
    pline(44);
    avg = sum/(float)num;
    printf("\nTotal Turnaround time: %f.", sum);
    printf("\nAverage Turnaround time: %.3f.", avg);

    return 0;
}
