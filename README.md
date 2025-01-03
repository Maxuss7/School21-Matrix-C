# 🧮 Matrix Library in C

**Description**:  
A lightweight matrix manipulation library written in C. It supports creation and removal of matrices, arithmetic operations (addition, subtraction, multiplication), matrix transformations (transposition), and more advanced features such as calculating determinants, cofactors, and inverses.

---

### **Features**
- Creation and deallocation of matrices of any valid size.
- Basic operations: addition, subtraction, multiplication.
- Determinant calculation and inversion of square matrices.
- Transpose and matrix of algebraic cofactors support.
- Lightweight and easy to integrate into any C project.

---

### **Technologies Used**
![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)
- **Dynamic memory allocation** for flexible matrix sizes.
- **Unit tests** using the [Check](https://libcheck.github.io/check/) framework.
- **Valgrind** for memory leak detection.
- _gcov_ and _lcov_ for code coverage analysis and visualization, ensuring high test coverage.

---

### **Usage**

#### **1. Clone the repository**
```bash
$ git clone https://github.com/yourusername/s21_matrix_library.git
$ cd s21_matrix_library/src
```

#### **2. Build the library**
Make sure you have a C compiler installed (GCC). Then run:
```bash
$ make s21_matrix.a
```
This will compile the source files and produce a static library `s21_matrix.a`.

#### **3. Run tests**
To validate the implementation, run the included test suite:
```bash
$ make test
```
You can also generate and view a coverage report:
```bash
$ make gcov_report
$ make lcov_report
```
This will create an HTML report in a `coverage` folder (or similar), which you can open in your browser.

#### **4. Include in your project**
To use the library in your own project, include the `s21_matrix.h` header file and link the compiled library.

##### Example:
```c
#include "s21_matrix.h"
#include <stdio.h>

int main() {
    matrix_t A, B, Result;
    // Create a 2x2 matrix A
    s21_create_matrix(2, 2, &A);
    // Create a 2x2 matrix B
    s21_create_matrix(2, 2, &B);

    // Initialize values for A
    A.matrix[0][0] = 1.0; A.matrix[0][1] = 2.0;
    A.matrix[1][0] = 3.0; A.matrix[1][1] = 4.0;

    // Initialize values for B
    B.matrix[0][0] = 5.0; B.matrix[0][1] = 6.0;
    B.matrix[1][0] = 7.0; B.matrix[1][1] = 8.0;

    // Add A and B to get Result
    if (s21_sum_matrix(&A, &B, &Result) == OK) {
        printf("Sum of A and B:\n");
        for (int i = 0; i < Result.rows; i++) {
            for (int j = 0; j < Result.columns; j++) {
                printf("%f ", Result.matrix[i][j]);
            }
            printf("\n");
        }
        s21_remove_matrix(&Result);
    }

    // Cleanup
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);

    return 0;
}
```

Then compile and link with your project:
```bash
$ gcc -o main main.c s21_matrix.a
$ ./main
```

#### **5. Clean up**
Run:
```bash
$ make clean
```
to remove all generated files (object files, test executables, coverage reports, etc.) and restore the directory to a clean state.
