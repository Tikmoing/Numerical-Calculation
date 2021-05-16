//author youryanmi
#pragma once
#include "yuc.h"
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

//Matrix
template <class Type>
class Matrix{
    private:
        vector<vector<Type>> mat;
    public:
        int row = 0, col = 0;

        //To 1*1 mat value == a
        Matrix(Type a){
            row = 1;
            col = 1;
            mat.push_back(vector<Type> (col,a));
        }
        Matrix(){}

        //To 1*size col vector
        Matrix(vector<Type> colVector){
            row = colVector.size();
            col = 1;
            for(int i = 0 ; i < row ; i ++) mat.push_back(vector<Type> (col,colVector[i]));
        }

        //To matrix dim(m) ~ vv
        Matrix(vector<vector<Type>> matrix){
            row = matrix.size();
            col = matrix[0].size();
            mat = vector<vector<Type>> (matrix);
        }

        //value = Type(0)
        Matrix(int row , int col){
            this->col = col;
            this->row = row;
            mat = vector<vector<Type>> (row,vector<Type> (col,Type(0)));
        }

        //value = con
        Matrix(int row,int col, Type con){
            this->col = col;
            this->row = row;
            mat = vector<vector<Type>> (row,vector<Type> (col,con));
        }
        //print matrix
        void beautifulPrint(){
            for(int i = 0 ; i < row ; i ++){
                for(int j = 0 ; j < col ; j ++){
                    cout<<mat[i][j]<<"  ";
                }
                cout<<endl;
            }   
        }
        //return type
        Type operator()(int r,int c){
            try{
                if( r > row - 1  || r < 0 || c > col - 1  || c < 0   ){
                throw "Matrix Error :index error : index beyond the dimension";
                }
            }catch(const char* msg){
                cout<<msg<<endl;
                exit(0);
            }
            return mat[r][c];
        }
        //return vector<type>
        vector<Type>& operator[](int r){
            try{
                if( r > row - 1  || r < 0  ){
                throw "Matrix Error :index error : index beyond the dimension";
                }
            }catch(const char* msg){
                cout<<msg<<endl;
                exit(0);
            }
            return mat[r];
        }
        // Transpose return Matrix
        Matrix<Type> transpose(){
            Matrix<Type> res(col,row);
            for(int i = 0 ; i < col ; i ++) for (int j = 0 ; j < row ; j ++) res[i][j] = mat[j][i];
            return res;
        }
};

//add dim(m1) == dim(m2)
template <class Type>
Matrix<Type> operator+(Matrix<Type> m1,Matrix<Type> m2){
    try{
        if(m1.row != m2.row || m1.col != m2.col){
        throw "Matrix Error : Dimension error with their row or col";
        }
    }catch(const char* msg){
        cout<<msg<<endl;
        exit(0);
    }
    Matrix<Type> res(m1.row,m1.col);
    for(int i = 0 ; i < res.row ; i ++) for (int j = 0 ; j < res.col ; j ++) res[i][j] = m1(i,j) + m2(i,j);
    return res;
}

//minus dim(m1) == dim(m2)
template <class Type>
Matrix<Type> operator-(Matrix<Type> m1,Matrix<Type> m2){
    try{
        if(m1.row != m2.row || m1.col != m2.col){
        throw "Matrix Error : Dimension error with their row or col";
        }
    }catch(const char* msg){
        cout<<msg<<endl;
        exit(0);
    }
    Matrix<Type> res(m1.row,m1.col);
    for(int i = 0 ; i < res.row ; i ++) for (int j = 0 ; j < res.col ; j ++) res[i][j] = m1(i,j) - m2(i,j);
    return res;
}

//mulity m1.col == m2.row
template <class Type>
Matrix<Type> operator*(Matrix<Type> m1,Matrix<Type> m2){
    try{
        if(m1.col != m2.row){
        throw "Matrix mulity Error : Dimension error with their row or col";
        }
    }catch(const char* msg){
        cout<<msg<<endl;
        exit(0);
    }

    Matrix<Type> res(m1.row,m2.col);
    for(int i = 0 ; i < res.row ; i ++) for(int j = 0 ; j < res.col ; j ++) for (int k = 0 ; k < m1.col ; k ++) res[i][j] = res[i][j] + m1(i,k)*m2(k,j);
    return res;
}

//Matrix Calculation : 
class MatrixCalculation{
    public:
    template <class Type>
    static Matrix<Type> dot(Matrix<Type> m1,Matrix<Type> m2){
        try{
            if(m1.row != m2.row){
            throw "Matrix dot Error : Dimension error with their row or col";
            }
        }catch(const char* msg){
            cout<<msg<<endl;
            exit(0);
        }
        return m1.transpose() * m2;
    }
    template <class Type>
    static Type dotv(Matrix<Type> m1,Matrix<Type> m2){
        try{
            if(m1.row != m2.row || m1.col != 1 || m2.col != 1){
            throw "Matrix dot Error : Dimension error with their row or col";
            }
        }catch(const char* msg){
            cout<<msg<<endl;
            exit(0);
        }
        Matrix<Type> res = m1.transpose() * m2;
        return res(0,0);
    }

    //nature : used for test
    template <class Type>
    static Matrix<Type> nature(int r , int c){
        Matrix<Type> res(r,c);
        for(int i = 0 ; i < r ; i ++) for(int j = 0; j < c ; j ++) res[i][j] = 1 + c * i + j;
        return res;
    }

    //eye(dimension) 
    template <class Type>
    static Matrix<Type> eye(int dimension){
        Matrix<Type> res(dimension,dimension,Type(0));
        for(int i = 0 ; i < dimension ; i ++) res[i][i] = Type(1);
        return res;
    }

    //diag : row col must have one is 1;
    template <class Type>
    static Matrix<Type> diag(Matrix<Type> m){
        try{
            if(m.col != 1 && m.row != 1){
                throw "Matrix diag Error : Dimension error with their row or col";
            }
        }catch(const char* msg){
            cout<<msg<<endl;
            exit(0);
        } 
        Matrix<Type> res;
        if(m.col == 1){
            res = Matrix<Type> (m.row,m.row);
            for(int i = 0 ; i < m.row ; i ++) res[i][i] = m(i,0);
        }else{
            res = Matrix<Type> (m.col,m.col);
            for(int i = 0 ; i < m.col ; i ++) res[i][i] = m(0,i);
        }
        return res;
    }
};