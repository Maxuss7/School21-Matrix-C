#ifndef S21_MATRIX
#define S21_MATRIX

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 0 — OK;
// 1 — Ошибка, некорректная матрица;
// 2 — Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т. д.).
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц
#define SUCCESS 1
#define FAILURE 0
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Сложение (sum_matrix) и вычитание матриц (sub_matrix)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

// Матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы (determinant)
int s21_determinant(matrix_t *A, double *result);

// Обратная матрица (inverse_matrix)
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные фукнции
int s21_is_a_good_matrix(matrix_t *A);
int s21_copy_matrix(matrix_t *source, matrix_t *destination);
int s21_minor(matrix_t *A, matrix_t *minor, int row, int column);

int s21_is_matrix_square(matrix_t *A);

#endif