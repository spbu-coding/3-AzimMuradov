/*
 * Task #3
 *
 * Azim Muradov, group #171
 */

// GENERATED FROM "experiment_c"

#include "experiment_float.h"

#include <math.h>

float dist_float(vector_2d_float_t v, vector_2d_float_t u) { return hypotf(v.x - u.x, v.y - u.y); }

int run_experiment_float_1(experiment_data_unit_float_t *experiment_data) {
    static const float BASIC_DIF = 0.0001f;
    static const float DIF_0 = 0.0001f;
    static const float REDUCTION = 2.0f;
    static const float MAX_DISTANCE = 10e-6f;

    static const vector_2d_float_t V0 = {1.0f, 1.0f};

    float distance;
    float _distance = 0.0f;
    float d = DIF_0;

    int counter = 0;

    float x, y;

    do {
        x = (BASIC_DIF - d) / BASIC_DIF;
        y = (BASIC_DIF + d) / BASIC_DIF;

        distance = dist_float(V0, (vector_2d_float_t) {x, y});
        if (distance == _distance) return -1; else _distance = distance;

        experiment_data[counter++] = (experiment_data_unit_float_t) {d, x, y, distance};

        d /= REDUCTION;
    } while (distance > MAX_DISTANCE);

    return counter;
}

float get_matrix_determinant_float(matrix_2d_float_t matrix) {
    return matrix.col1.x * matrix.col2.y - matrix.col1.y * matrix.col2.x;
}

int run_experiment_float_2(experiment_data_unit_float_t *experiment_data) {
    static const float S_1 = 2.0f;
    static const float S_2 = 2.0001f;
    static const float DIF_0 = 0.0001f;
    static const float REDUCTION = 2.0f;
    static const float MAX_DISTANCE = 10e-6f;

    static const vector_2d_float_t V0 = {1.0f, 1.0f};

    static const vector_2d_float_t A_COL = {1.0f, 1.0f};
    static const vector_2d_float_t B_COL = {1.0f, 1.0001f};

    float distance;
    float _distance = 0.0f;
    float d = DIF_0;

    int counter = 0;

    float x, y;

    vector_2d_float_t s_col;
    float det_x, det_y, det;

    do {
        s_col = (vector_2d_float_t) {S_1, S_2 + d};
        det_x = get_matrix_determinant_float((matrix_2d_float_t) {s_col, B_COL});
        det_y = get_matrix_determinant_float((matrix_2d_float_t) {A_COL, s_col});
        det = get_matrix_determinant_float((matrix_2d_float_t) {A_COL, B_COL});

        x = det_x / det;
        y = det_y / det;

        distance = dist_float(V0, (vector_2d_float_t) {x, y});
        if (distance == _distance) return -1; else _distance = distance;

        experiment_data[counter++] = (experiment_data_unit_float_t) {d, x, y, distance};

        d /= REDUCTION;
    } while (distance > MAX_DISTANCE);

    return counter;
}
