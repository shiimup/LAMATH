#ifndef MATRIX_H__
#define MATRIX_H__
#define N 4

void print_matrix(float m[N][N]);

void matmul(float m1[N][N], float m2[N][N],float res[N][N]);

void init_matrix(float m[N][N]);

void cl_matmul(float m1[N][N], float m2[N][N],float res[N][N]);

void mat_copy(float m1[N][N],float m2[N][N]);

void LUdecompose(float L[N][N],float U[N][N],float A[N][N]);

void qsort1(float* arr,int size);

void _fill_matrix(float m[N][N]);
#endif
