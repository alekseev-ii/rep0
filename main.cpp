#include <iostream>
#include <cstddef>

int ** create(size_t rows, size_t cols);
void remove(int ** m, size_t rows, size_t cols);
void input(int ** m, size_t rows, size_t cols);
void output(const int * const * m, size_t rows, size_t cols);  

int main () {
    size_t rows = 0, cols = 0;
    std::cin >> rows >> cols;
    if (!std::cin) {
	return 1;
    }

    int ** m = create(rows, cols);

    input(m, rows, cols);
    if (!std::cin) {
	remove(m, rows, cols);
	return 1;
    }

    output(m, rows, cols);
    std::cout << "\n";

    remove(m, rows, cols);
}

void input(int ** m, size_t rows, size_t cols) {
    for (size_t i = 0ull; i < rows; i++) {
	for (size_t j = 0ull; j < rows; j++) {
	    std::cin >> m[i][j];
        }
    }
}

void output(const int * const * m, size_t rows, size_t cols) {
    for (size_t i = 0ull; i < rows; i++) {
	std::cout << m[i][j];
        for (size_t j = 1ull; j < rows; j++) {
            std::cout << " " << m[i][j];
        }
	std::cout << "\n";
    }
}

