#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double RHS(double y)
{
    return y;
}

int main()
{

    FILE *fp;
    fp = fopen("eulerVL.txt", "w");
    if (fp == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden!\n");
        return -1;
    }

    // explicit euler
    double y_0 = -0.5;
    double y = 0;
    double f = 0;
    double h = 1e-3;
    double t = 0;
    int maxIter = 5000;

    fprintf(fp, "%lf %lf\n", t, y_0);
    y = y_0;
    for (int i = 0; i < maxIter; i++)
    {
        f = RHS(y);
        y = y + (h * f);
        t = t + h;
        fprintf(fp, "%lf %lf\n", t, y);
    }

    fclose(fp);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "plot 'eulerVL.txt'\n");
    pclose(gnuplotPipe);

    return 0;
}