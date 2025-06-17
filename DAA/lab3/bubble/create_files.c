#include <time.h>
#include <stdio.h>


void main(){
    int n = 100000;
    FILE *file;
    file = fopen("./best_case.txt","w");

    for (int i = 0; i < n; i++)
    {
        fprintf(file,"%d ",i);
    }

    fclose(file);

    file = fopen("./worst_case.txt","w");

    for (int i = n; i > 0; i--)
    {
        fprintf(file,"%d ",i);
    }

    fclose(file);

    file = fopen("./average_case.txt","w");

    for (int i = n; i > 0; i--)
    {
        fprintf(file,"%d ",rand()%n);
    }

    fclose(file);
}