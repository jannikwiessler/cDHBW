#include <stdbool.h>

#pragma once

#define LOWER_DEFAULT -0.123456
#define UPPER_DEFAULT -0.123456
#define STEPSIZE_DEFAULT 100000
#define FCNCODE_DEFAULT "###"

typedef struct
{
    double lower;
    double upper;
    double stepsize;
    char *fcn;
} config;

config get_config(int argc, char **argv);
void print_config(config *cfg);
bool is_valid_config(config cfg);
void generate_function_executable(config cfg);
double function_executable(double x);
void generate_data(config cfg);
void generate_final_plot();
void clean_up();