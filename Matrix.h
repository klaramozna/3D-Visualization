#ifndef INC_3DSDL_MATRIX_H
#define INC_3DSDL_MATRIX_H


#include <vector>
#include <stdexcept>

class Matrix {
public:
    Matrix(): width(0), height(0), values(){};
    Matrix(int width, int height);
    template<class Iterator>Matrix(int width, int height, Iterator begin, Iterator end);
    double getValueAt(int row, int col) const;
    void setValueAt(int row, int col, double val);
    Matrix multiply(Matrix rightMatrix) const;
    Matrix add(Matrix matrix) const;
    Matrix scale(double constant) const;
    void print() const;
    void setToVal(double val);      // sets all values of the matrix to val
    Matrix getInverse() const;
    double getDeterminant() const;
    Matrix getTranspose() const;
    Matrix operator*(Matrix const& m) const;
    Matrix operator+(Matrix const& m) const;
    int getWidth() const;
    int getHeight() const;
private:
    std::vector<std::vector<double>> values;
    int height;
    int width;
    bool notInRange(int row, int col) const {return row < 0 || col < 0 || row >= height || col >= width;};
    double getCofactorAt(int row, int col) const;
    Matrix getCofactor() const;
    Matrix getAdjugate() const;
};


#endif //INC_3DSDL_MATRIX_H
