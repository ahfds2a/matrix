#include<iostream>

using namespace std;

class Matrix{
public:
    Matrix();
    void initialiazeSize(int rows, int cols);
    void initialiazeValues();
    int** values;
    int getRows();
    int getCols();
    void printValues();
private:
    int rows_;
    int cols_;
};

Matrix::Matrix()
{
    values = 0;
    rows_  = 0;
    cols_  = 0;
}

void Matrix::initialiazeSize(int rows, int cols)
{
    rows_ = rows;
    cols_ = cols;
    if ( (rows_ <= 0) || (cols_ <= 0) ){
        cout << "Wrong values!" << endl;
        return;
    }
    values = new int*[rows_];
    for(int i = 0; i < rows_; ++i)
        values[i] = new int[cols_];
}

void Matrix::initialiazeValues()
{
    for( int i = 0; i < rows_; ++i)
        for( int j = 0; j < cols_; ++j)
            cin >> values[i][j];
}

int Matrix::getRows()
{
    return rows_;
}

int Matrix::getCols()
{
    return cols_;
}

void Matrix::printValues()
{
    cout << endl;
    for( int i = 0; i < rows_; ++i){
        for( int j = 0; j < cols_; ++j)
            cout << values[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

class MatrixMultiply{
public:
    MatrixMultiply();
private:
    Matrix matrixA;
    Matrix matrixB;
    Matrix matrixOut;
    void compute();
};

MatrixMultiply::MatrixMultiply()
{
    int rows;
    int cols;

    cout << "Enter size of first matrix. Example 2 2 :" << endl;
    cin >> rows >> cols;
    matrixA.initialiazeSize(rows, cols);

    cout << "Enter size of second matrix. Example 2 2 :" << endl;
	cin >> rows >> cols;
	matrixB.initialiazeSize(rows, cols);

	if( matrixA.getCols() == matrixB.getRows() )
        matrixOut.initialiazeSize( matrixA.getRows(), matrixB.getCols() );
    else
        cout << "Columns of first matrix don't match with rows of second matrix. Try Again" << endl;

    cout << "Enter first matrix in the line. Example a11 a12 a21 a22 :" << endl;
    matrixA.initialiazeValues();
    matrixA.printValues();

	cout << "Enter second matrix in the line. Example a11 a12 a21 a22 :" << endl;
    matrixB.initialiazeValues();
    matrixB.printValues();

    compute();
    cout << "Multiplied matrix is:" << endl;
    matrixOut.printValues();
}

void MatrixMultiply::compute()
{
    for( int i = 0; i < matrixA.getRows(); ++i){
        for( int j = 0; j < matrixB.getCols(); ++j){
            matrixOut.values[i][j] = 0;
            for(int k = 0; k < matrixA.getCols(); ++k)
                matrixOut.values[i][j] += matrixA.values[i][k] * matrixB.values[k][j];
        }
    }
}

int main()
{
    MatrixMultiply matrixMultiply;

	return 0;
}
