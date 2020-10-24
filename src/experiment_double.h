/*
 * Task #3
 *
 * Azim Muradov, group #171
 */

// GENERATED FROM "experiment_c"

#ifndef TASK_3_EXPERIMENT_DOUBLE_H
#define TASK_3_EXPERIMENT_DOUBLE_H

typedef struct vector_2d_double {
    double x;
    double y;
} vector_2d_double_t;

double dist_double(vector_2d_double_t v, vector_2d_double_t u);

typedef struct experiment_data_unit_double {
    double d;
    double x;
    double y;
    double dist;
} experiment_data_unit_double_t;

int run_experiment_double_1(experiment_data_unit_double_t *experiment_data);

typedef struct matrix_2d_double {
    vector_2d_double_t col1;
    vector_2d_double_t col2;
} matrix_2d_double_t;

double get_matrix_determinant_double(matrix_2d_double_t matrix);

int run_experiment_double_2(experiment_data_unit_double_t *experiment_data);

#endif // TASK_3_EXPERIMENT_DOUBLE_H
