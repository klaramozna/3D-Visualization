//
// Created by klara on 22.08.2023.
//

#include "Matrix.h"
#include <stdexcept>
#include <iostream>

Matrix::Matrix(int width, int height) {
    this->width = width;
    this->height = height;
    values.resize(height);
    for(auto & value : values){
        value.resize(width);
    }
}

double Matrix::getValueAt(int row, int col) const {
    if (notInRange(row, col)) {
        throw std::out_of_range("Given values are outside of the matrix.");
    }
    return values[row][col];
}

void Matrix::setValueAt(int row, int col, double val) {
    if (notInRange(row, col)) {
        throw std::out_of_range("Given values are outside of the matrix.");
    }
    values[row][col] = val;
}

Matrix Matrix::add(Matrix matrix) const {
    if(height != matrix.height || width != matrix.width){
        throw std::invalid_argument("Incompatible dimensions.");
    }
    Matrix result(width, height);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            result.values[row][col] = matrix.values[row][col] + values[row][col];
        }
    }
    return result;
}

Matrix Matrix::scale(double constant) const {
    Matrix result(width, height);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            result.values[row][col] = constant * values[row][col];
        }
    }
    return result;
}

Matrix Matrix::multiply(Matrix rightMatrix) const {
    if(width != rightMatrix.height){
        throw std::invalid_argument("Incompatible dimensions.");
    }
    Matrix result(rightMatrix.width, height);
    result.setToVal(0);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < rightMatrix.width; col++){
            for(int i = 0; i < width; i++){
                result.values[row][col] += values[row][i] * rightMatrix.values[i][col];
            }
        }
    }
    return result;
}

void Matrix::setToVal(double val) {
    for(auto & row : values){
        for(auto & col : row){
            col = val;
        }
    }
}

void Matrix::print() const {
    for(auto & row : values){
        for(auto & col : row){
            std::cout << col << ' ';
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::getInverse() const {
    Matrix adjugate = getAdjugate();
    double det = getDeterminant();
    if(det == 0){
        throw std::domain_error("Determinant is zero.");
    }
    adjugate.scale(1.0/static_cast<double>(det));
    return adjugate;
}

double Matrix::getDeterminant() const {
    if(width < 1 || height < 1 || height != width){
        throw std::invalid_argument("Determinant can only be computed for square matrices.");
    }

    if(height == 1){
        return getValueAt(0, 0);
    }
    if(height == 2){
        return getValueAt(0,  0) * getValueAt(1, 1) - getValueAt(0, 1) * getValueAt(1, 0);
    }
    if(height == 3){
        return getValueAt(0, 0) * (getValueAt(1, 1) * getValueAt(2, 2) - getValueAt(1, 2) * getValueAt(2, 1))
        - getValueAt(0, 1) * (getValueAt(1, 0) * getValueAt(2, 2) - getValueAt(2, 0) * getValueAt(1, 2))
        + getValueAt(0, 2) *(getValueAt(1, 0) * getValueAt(2, 1) - getValueAt(1, 1) * getValueAt(2, 0));
    }
    double det = 0;
    for(int col = 0; col < width; col++){
        det += getValueAt(1, col) * getCofactorAt(1, col);
    }
    return det;
}

Matrix Matrix::getTranspose() const {
    Matrix transpose = Matrix(height, width);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            transpose.setValueAt(col, row, getValueAt(row, col));
        }
    }
    return transpose;
}

double Matrix::getCofactorAt(int row, int col) const {
    if(height <= 1 && width <= 1){
        throw std::invalid_argument("Matrix too small.");
    }
    double sign = (row + col) % 2 == 0 ? 1 : -1;
    Matrix removeRowCol = Matrix(width-1, height-1);
    int rowNew = 0;
    int colNew = 0;
    for(int i = 0; i < height; i++){
        if(i != row){
            for(int j = 0; j < width; j++){
                if(j != col){
                    removeRowCol.setValueAt(rowNew, colNew, getValueAt(i, j));
                    colNew++;
                }
            }
            colNew = 0;
            rowNew++;
        }
    }
    return sign * removeRowCol.getDeterminant();
}

Matrix Matrix::getCofactor() const {
    Matrix cofactor = Matrix(width, height);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            cofactor.setValueAt(row, col, getCofactorAt(row, col));
        }
    }
    return cofactor;
}

Matrix Matrix::getAdjugate() const {
    return getCofactor().getTranspose();
}

template<class Iterator>
Matrix::Matrix(int width, int height, Iterator begin, Iterator end) {
    if(width * height != end - begin){
        throw std::domain_error("Size does not match.");
    }
    this->width = width;
    this->height = height;
    values.resize(height);
    Iterator it = begin;
    for(int row = 0; row < height; row++){
        values[row].resize(width);
        for(int col = 0; col < width; col++){
            values[row][col] = *it;
            ++it;
        }
    }
}

Matrix Matrix::operator*(const Matrix &m) const {
    return multiply(m);
}

Matrix Matrix::operator+(const Matrix &m) const {
    return add(m);
}

int Matrix::getWidth() const {
    return width;
}

int Matrix::getHeight() const{
    return height;
}


template Matrix::Matrix(int height, int width, std::vector<double>::iterator, std::vector<double>::iterator);
