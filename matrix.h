#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H

#include <stdexcept>
#include "node.h"

using namespace std;

template <typename T>
class Matrix {
private:
    Node<T> *root;
    unsigned rows, columns;

public:
    Matrix(unsigned rows, unsigned columns){
        this -> rows = rows;
        this -> columns = columns;
        this -> root = new Node<T>;
        Node <T> *dummy = this->root;

        for (unsigned i = 0; i< rows; ++i){
            Node<T> *temp = new Node<T>;
            temp->y = i;
            dummy->down = temp;
            dummy = dummy->down;
        }

        dummy = this->root;

        for (unsigned i = 0; i< columns; ++i){
            Node<T> *temp = new Node<T>;
            temp->x = i;
            dummy->next = temp;
            dummy = dummy->next;
        }

    }

    void set(unsigned x,unsigned y, T value) {

        Node<T> *dummy = this->root;

        auto insert = new Node<T>(x,y,value);


        for (unsigned i = 0; i < x; ++i) {
            dummy = dummy->next;
            while (dummy && dummy->y < y) {
                dummy = dummy->down;
            }
            if (dummy != nullptr) {
                Node<T> *temp = dummy->down;
            }

        }
        Node<T> *dummy2 = this->root;


        for (unsigned j = 0; j < y; ++j) {
            dummy2 = dummy2->down;
        }


    }

    T operator()(unsigned x, unsigned y) const{
        Node<T> *temp = root->next;
        while(x > temp->x){
            temp = temp->next;
        }
        temp = temp->down;
        while(temp != nullptr and y > temp->y ){
            temp = temp->down;
        }
        if (temp != nullptr and temp->x==x and temp->y==y){
            return temp->value;
        }
        return 0;

    };

    Matrix<T> operator*(T scalar) const{
        Matrix NewMatrix(rows,columns);
        Node<T> *temp = root->next;
        for (unsigned int i = 0; i <columns ; ++i) {
            for (unsigned int j = 0; j <rows ; ++j) {
                NewMatrix.set(i,j,NewMatrix(i,j)*scalar);
            }

            }
        return NewMatrix;
    };

    Matrix<T> operator*(Matrix<T> other) const {
        Matrix NewMatrix(rows, other.columns);
        int temp = 0;
        for (unsigned i = 0; i < rows; ++i) {

            for (unsigned j = 0; j < other.columns; ++j) {

                for (unsigned k = 0; k < other.rows; ++k) {
                    temp = temp + (this->operator()(i, k) * other(k, j));

                }

                NewMatrix(i, j) = temp;
                temp = 0;
            }

        }
        return NewMatrix;
        //other. "para cualquier cosa en la otra matrix"
    };


    Matrix<T> operator+(Matrix<T> other) const{

    };
    Matrix<T> operator-(Matrix<T> other) const{

    };
    Matrix<T> transpose() const;
    void print() const;

    ~Matrix();
};

#endif //SPARSE_MATRIX_MATRIX_H