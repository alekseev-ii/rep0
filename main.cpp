#include <iostream>
#include <cstddef>

int ** create(size_t rows, size_t cols);
void remove(int ** m, size_t rows);
void input(int ** m, size_t rows, size_t cols);
void output(const int * const * m, size_t rows, size_t cols);
int ** convert(const int * t, size_t n, size_t * lns, size_t rows);

int main () {
    // size_t rows = 0, cols = 0;
    // std::cin >> rows >> cols;
    // if (!std::cin) {
	   //  return 1;
    // }
    //
    // int ** m = create(rows, cols);
    //
    // input(m, rows, cols);
    // if (!std::cin) {
	   //  remove(m, rows);
	   //  return 1;
    // }
    //
    // output(m, rows, cols);
    // std::cout << "\n";
    //
    // remove(m, rows);
    size_t rows = 4;
    size_t lns[rows]{4ull, 2ull, 5ull, 1ull};
    size_t n = 12;
    int t[n]{5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
    int ** res = convert(t, n, lns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < lns[i]; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }

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

int ** convert(const int * t, size_t n, size_t * lns, size_t rows) {
    int ** result = new int*[rows];
    size_t total = 0ull;
    for (size_t i = 0ull; i < rows; ++i) {
        result[i] = new int[lns[i]];
        for (size_t j = 0ull; j < lns[i]; ++j) {
            result[i][j] = t[total + j];
        }
        total += lns[i];
    }
    return result;
}

