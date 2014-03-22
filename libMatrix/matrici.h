#ifndef MATRICI_H
#define MATRICI_H

struct Matrix {
	int lines;
	int columns;

	double determinant;
	double trace;
			
	double **value;
	struct Matrix *inverse;
};

struct Matrix *create_matrix(int rows, int columns);
void read_matrix(struct Matrix *a);
int print_matrix(struct Matrix *a);
struct Matrix *get_minor(struct Matrix *a, int line, int column);
void multiply_matrix_with_scalar(struct Matrix *a, double scalar); 
int get_transpose(struct Matrix *a, struct Matrix **transpose);
void distroy_matrix(struct Matrix *a); 
int compute_inverse(struct Matrix *a);
double get_determinant(struct Matrix *a);
int multiply_matrices(struct Matrix *a, struct Matrix *b, struct Matrix **result);
int add_matrices(struct Matrix *a, struct Matrix *b, struct Matrix **result);
void copy_matrix(struct Matrix *a, struct Matrix **destination); 
struct Matrix *matrix_pow(struct Matrix *a, int power); 



#endif 