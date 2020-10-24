/*
 * Task #3
 *
 * Azim Muradov, group #171
 */

// GENERATED FROM "experiment_c"

#include "experiment_double.h"

#include <math.h>

double dist_double(vector_2d_double_t v, vector_2d_double_t u) { return hypot(v.x - u.x, v.y - u.y); }

int run_experiment_double_1(experiment_data_unit_double_t *experiment_data) {
    static const double BASIC_DIF = 0.0001;
    static const double DIF_0 = 0.0001;
    static const double REDUCTION = 2.0;
    static const double MAX_DISTANCE = 10e-6;

    static const vector_2d_double_t V0 = {1.0, 1.0};

    double distance;
    double _distance = 0.0;
    double d = DIF_0;

    int counter = 0;

    double x, y;

    do {
        x = (BASIC_DIF - d) / BASIC_DIF;
        y = (BASIC_DIF + d) / BASIC_DIF;

        distance = dist_double(V0, (vector_2d_double_t) {x, y});
        if (distance == _distance) return -1; else _distance = distance;

        experiment_data[counter++] = (experiment_data_unit_double_t) {d, x, y, distance};

        d /= REDUCTION;
    } while (distance > MAX_DISTANCE);

    return counter;
}

double get_matrix_determinant_double(matrix_2d_double_t matrix) {
    return matrix.col1.x * matrix.col2.y - matrix.col1.y * matrix.col2.x;
}

int run_experiment_double_2(experiment_data_unit_double_t *experiment_data) {
    static const double S_1 = 2.0;
    static const double S_2 = 2.0001;
    static const double DIF_0 = 0.0001;
    static const double REDUCTION = 2.0;
    static const double MAX_DISTANCE = 10e-6;

    static const vector_2d_double_t V0 = {1.0, 1.0};
    static const vector_2d_double_t A_COL = {1.0, 1.0};
    static const vector_2d_double_t B_COL = {1.0, 1.0001};

    double distance;
    double _distance = 0.0;
    double d = DIF_0;

    int counter = 0;

    double x, y;

    vector_2d_double_t s_col;
    double det_x, det_y, det;

    do {
        s_col = (vector_2d_double_t) {S_1, S_2 + d};
        det_x = get_matrix_determinant_double((matrix_2d_double_t) {s_col, B_COL});
        det_y = get_matrix_determinant_double((matrix_2d_double_t) {A_COL, s_col});
        det = get_matrix_determinant_double((matrix_2d_double_t) {A_COL, B_COL});

        x = det_x / det;
        y = det_y / det;

        distance = dist_double(V0, (vector_2d_double_t) {x, y});
        if (distance == _distance) return -1; else _distance = distance;

        experiment_data[counter++] = (experiment_data_unit_double_t) {d, x, y, distance};

        d /= REDUCTION;
    } while (distance > MAX_DISTANCE);

    return counter;
}
