/*
 * Task #3
 *
 * Azim Muradov, group #171
 */

// GENERATED FROM "experiment_c"

#ifndef TASK_3_EXPERIMENT_FLOAT_H
#define TASK_3_EXPERIMENT_FLOAT_H

typedef struct vector_2d_float {
    float x;
    float y;
} vector_2d_float_t;

float dist_float(vector_2d_float_t v, vector_2d_float_t u);

typedef struct experiment_data_unit_float {
    float d;
    float x;
    float y;
    float dist;
} experiment_data_unit_float_t;

int run_experiment_float_1(experiment_data_unit_float_t *experiment_data);

typedef struct matrix_2d_float {
    vector_2d_float_t col1;
    vector_2d_float_t col2;
} matrix_2d_float_t;

float get_matrix_determinant_float(matrix_2d_float_t matrix);

int run_experiment_float_2(experiment_data_unit_float_t *experiment_data);

#endif // TASK_3_EXPERIMENT_FLOAT_H
