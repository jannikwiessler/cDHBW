#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

void print_config(config *cfg)
{
    printf("\nconfigurations: \n");
    printf("  lower: %lf\n", cfg->lower);
    printf("  upper: %lf\n", cfg->upper);
    printf("  stepsize: %lf\n", cfg->stepsize);
    printf("  function: %s\n\n", cfg->fcn);
}

config get_config(int argc, char **argv)
{

    config cfg = {.lower = LOWER_DEFAULT,
                  .upper = UPPER_DEFAULT,
                  .stepsize = STEPSIZE_DEFAULT,
                  .fcn = FCNCODE_DEFAULT};

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-lb") == 0)
            sscanf(argv[i + 1], "%lf", &cfg.lower);
        else if (strcmp(argv[i], "-ub") == 0)
            sscanf(argv[i + 1], "%lf", &cfg.upper);
        else if (strcmp(argv[i], "-s") == 0)
            sscanf(argv[i + 1], "%lf", &cfg.stepsize);
        else if (strcmp(argv[i], "-c") == 0)
            cfg.fcn = argv[i + 1];
    }

    return cfg;
}

bool is_valid_config(config cfg)
{
    if (cfg.lower == LOWER_DEFAULT)
        return false;
    if (cfg.upper == UPPER_DEFAULT)
        return false;
    if (cfg.stepsize == STEPSIZE_DEFAULT)
        return false;
    if (strcmp(cfg.fcn, FCNCODE_DEFAULT) == 0)
        return false;
    return true;
}

void generate_function_executable(config cfg)
{
    FILE *c_code = fopen("fcn.c", "w");
    if (c_code == NULL)
    {
        printf("unable to open new *.c file\n");
    }
    else
    {
        fprintf(c_code, "# include <stdio.h>\n");
        fprintf(c_code, "# include <stdlib.h>\n");
        fprintf(c_code, "double f(double x){return %s;}\n", cfg.fcn);
        fprintf(c_code, "int main(int argc, char **argv)");
        fprintf(c_code, "{double tmp; sscanf(argv[1], \"%%lf\" , &tmp); printf(\"%%lf\",f(tmp)); return 0;}\n");
        fclose(c_code);
        FILE *compile = popen("gcc fcn.c -o fcn.exe", "r");
        printf("Compile Exit code: %d\n", pclose(compile));
    }
}

double function_executable(double x)
{

    char number[20];
    char command[30] = "fcn.exe ";
    snprintf(number, 50, "%f", x);
    strcat(command, number);

    FILE *executable = popen(command, "r");
    char result_char[100];
    double result = 0;
    fgets(result_char, 100, executable);
    sscanf(result_char, "%lf", &result);
    pclose(executable);
    return result;
}

void generate_data(config cfg)
{
    FILE *data = fopen("data.txt", "w");
    if (data == NULL)
    {
        printf("unable to open new *.txt file\n");
    }
    for (double i = cfg.lower; i < cfg.upper; i += cfg.stepsize)
    {
        fprintf(data, "%lf: %lf\n", i, function_executable(i));
    }
    fclose(data);
}

void generate_final_plot()
{
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "plot 'data.txt'\n");
    fprintf(gnuplot, "exit");
    pclose(gnuplot);
}

void clean_up()
{
    remove("data.txt");
    remove("fcn.c");
    remove("fcn.exe");
}