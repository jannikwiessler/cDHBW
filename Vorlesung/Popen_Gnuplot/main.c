#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[])
{
    config cfg = get_config(argc, argv);
    if (!is_valid_config(cfg))
        return -1;
    print_config(&cfg);
    generate_function_executable(cfg);
    generate_data(cfg);
    generate_final_plot();
    clean_up();
    return 0;
}