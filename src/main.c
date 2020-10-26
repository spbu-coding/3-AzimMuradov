/*
 * Task #3
 *
 * Azim Muradov, group #171
 */

#include <stdio.h>
#include <string.h>

#include "experiment_float.h"
#include "experiment_double.h"

#define DATA_MAX_SIZE 75

typedef int (*experiment_float_function_t)(experiment_data_unit_float_t *experiment_data);

typedef int (*experiment_double_function_t)(experiment_data_unit_double_t *experiment_data);

void print_experiment_float_data(experiment_data_unit_float_t *experiment_data);

void print_experiment_double_data(experiment_data_unit_double_t *experiment_data);

void run_and_compare_experiments(
    const char *title,
    experiment_float_function_t f_float,
    experiment_double_function_t f_double
) {
    experiment_data_unit_float_t experiment_data_float[DATA_MAX_SIZE];
    experiment_data_unit_double_t experiment_data_double[DATA_MAX_SIZE];

    memset(experiment_data_float, 0, DATA_MAX_SIZE * sizeof *experiment_data_float);
    memset(experiment_data_double, 0, DATA_MAX_SIZE * sizeof *experiment_data_double);

    int cnt_float = f_float(experiment_data_float);
    int cnt_double = f_double(experiment_data_double);

    printf("\"%s\": float - %d | double - %d\n\n", title, cnt_float, cnt_double);
    print_experiment_float_data(experiment_data_float);
    printf("\n");
    print_experiment_double_data(experiment_data_double);
    printf("\n\n");
}

void print_experiment_float_data(experiment_data_unit_float_t *experiment_data) {
    printf("%*ci - d%*c x%*c y%*c dist%*c\n", 2 - 1, ' ', 22 - 1, ' ', 22 - 1, ' ', 22 - 1, ' ', 22 - 4, ' ');
    for (int i = 0; experiment_data[i].dist != 0.0; ++i) {
        printf("%2d - %.20f %.20f %.20f %.20f\n", i + 1,
               experiment_data[i].d,
               experiment_data[i].x,
               experiment_data[i].y,
               experiment_data[i].dist
        );
    }
}

void print_experiment_double_data(experiment_data_unit_double_t *experiment_data) {
    printf("%*ci - d%*c x%*c y%*c dist%*c\n", 2 - 1, ' ', 22 - 1, ' ', 22 - 1, ' ', 22 - 1, ' ', 22 - 4, ' ');
    for (int i = 0; experiment_data[i].dist != 0.0; ++i) {
        printf("%2d - %.20f %.20f %.20f %.20f\n", i + 1,
               experiment_data[i].d,
               experiment_data[i].x,
               experiment_data[i].y,
               experiment_data[i].dist
        );
    }
}


int main(void) {
    run_and_compare_experiments("Math optimisations", run_experiment_float_1, run_experiment_double_1);
    run_and_compare_experiments("Kramer's method", run_experiment_float_2, run_experiment_double_2);

    return 0;
}
