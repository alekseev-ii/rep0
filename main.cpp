#include <iostream>
#include <cstddef>

int ** create(size_t rows, size_t cols);
void remove(int ** m, size_t rows);
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
	    remove(m, rows);
	    return 1;
    }

    output(m, rows, cols);
    std::cout << "\n";

    remove(m, rows);
}



void input(int ** m, size_t rows, size_t cols) {
    for (size_t i = 0ull; i < rows; ++i) {
	    for (size_t j = 0ull; j < cols; ++j) {
	        std::cin >> m[i][j];
        }
    }
}

void output(const int * const * m, size_t rows, size_t cols) {
    for (size_t i = 0ull; i < rows; ++i) {
	    std::cout << m[i][0];
        for (size_t j = 1ull; j < cols; ++j) {
            std::cout << " " << m[i][j];
        }
	std::cout << "\n";
    }
}

int ** create(size_t rows, size_t cols) {
    int ** result = new int*[rows];
    size_t i = 0ull;
    try {
    	for (i; i < rows; ++i) {
            result[i] = new int[cols];
        }
    } catch (...) {
	    remove(result, i);
	    throw;
    }
    return result;
}

void remove(int ** m, size_t rows) {
    for (size_t i = 0ull; i < rows; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

