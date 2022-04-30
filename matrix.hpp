#ifndef lquANaPknGwlswHzxavD
#define lquANaPknGwlswHzxavD
#include <cstdlib>
namespace mtx {
    class matrix {
      private:
        int _row, _col;
        double *_num;
      public:
        matrix(int row, int col) {
            _row = row, _col = col;
            _num = new double[row * col];
        }
        double& operator()(int r, int c) {
            if (0 > r || r >= _row || 0 > c || c >= _col) exit(EXIT_FAILURE);
            return _num[r * _col + c];
        }
        int size_row() { return _row; }
        int size_col() { return _col; }
        matrix operator=(matrix x) {
            *this = matrix(x._row, x._col);
#pragma omp parallel for
            for (int r = 0; r < _row; r++)
#pragma omp parallel for
                for (int c = 0; c < _col; c++)
                    (*this)(r, c) = x(r, c);
            return *this;
        }
        void fill(double (*func)(int, int), int begin_row = 0, int end_row = -1,
                int begin_col = 0, int end_col = -1) {
            if (end_row == -1) end_row = _row;
            if (end_col == -1) end_col = _col;
#pragma omp parallel for
            for (int r = begin_row; r < end_row; r++)
#pragma omp parallel for
                for (int c = begin_col; c < end_col; c++)
                    (*this)(r, c) = func(r, c);
        }
        matrix operator+(matrix x) {
            if (_row != x._row || _col != x._col) exit(EXIT_FAILURE);
            matrix ans(_row, _col);
#pragma omp parallel for
            for (int r = 0; r < _row; r++)
#pragma omp parallel for
                for (int c = 0; c < _col; c++)
                    ans(r, c) = (*this)(r, c) + x(r, c);
            return ans;
        }
        matrix operator-(matrix x) {
            if (_row != x._row || _col != x._col) exit(EXIT_FAILURE);
            matrix ans(_row, _col);
#pragma omp parallel for
            for (int r = 0; r < _row; r++)
#pragma omp parallel for
                for (int c = 0; c < _col; c++)
                    ans(r, c) = (*this)(r, c) - x(r, c);
            return ans;
        }
        matrix operator*(double k) {
            matrix ans(_row, _col);
#pragma omp parallel for
            for (int r = 0; r < _row; r++)
#pragma omp parallel for
                for (int c = 0; c < _col; c++)
                    ans(r, c) = (*this)(r, c) * k;
            return ans;
        }
        matrix operator*(matrix x) {
            if (_col != x._row) exit(EXIT_FAILURE);
            matrix ans(_row, x._col);
#pragma omp parallel for
            for (int r = 0; r < _row; r++)
#pragma omp parallel for
                for (int c = 0; c < x._col; c++) {
                    ans(r, c) = 0;
#pragma omp parallel for
                    for (int i = 0; i < _col; i++)
                        ans(r, c) += (*this)(r, i) * x(i, c);
                }
            return ans;
        }
    };
}
#endif

