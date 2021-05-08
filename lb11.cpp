#include <iostream>

using namespace std;

double getDouble();
long long int fact(int number);

class Matrix {
public:
    Matrix operator+(Matrix matrix);
    Matrix operator-(Matrix matrix);
    Matrix operator*(int number);
    Matrix operator*(Matrix matrix);
    Matrix operator/(int number);
    Matrix(int sizeX, int sizeY);
    Matrix();
    void enterData();
    void print();
    int getSizeX();
    int getSizeY();
    double** getData();
protected:
    int sizeX, sizeY;
    double** data;
};

Matrix Matrix::operator+(Matrix matrix)
{
    Matrix sum(sizeX, sizeY);
    if (sizeX == matrix.sizeX && sizeY == matrix.sizeY) {
        for (int i = 0; i < sizeX; i++)
            for (int j = 0; j < sizeY; j++)
                sum.data[i][j] = data[i][j] + matrix.data[i][j];
    }
    else {
        for (int i = 0; i < sizeX; i++)
            for (int j = 0; j < sizeY; i++)
                sum.data[i][j] = 0;
    }
    //sum.getData();
    return sum;
}

Matrix Matrix::operator-(Matrix matrix)
{
    Matrix sub(sizeX, sizeY);
    if (sizeX == matrix.sizeX && sizeY == matrix.sizeY) {
        for (int i = 0; i < sizeX; i++)
            for (int j = 0; j < sizeY; j++)
                sub.data[i][j] = data[i][j] - matrix.data[i][j];
    }
    else {
        for (int i = 0; i < sizeX; i++)
            for (int j = 0; j < sizeY; i++)
                sub.data[i][j] = 0;
    }
    //sub.getData();
    return sub;
}

Matrix Matrix::operator*(int number)
{
    Matrix multi(sizeX, sizeY);
    for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
            multi.data[i][j] = data[i][j] * number;
    //multi.getData();
    return multi;
}

Matrix Matrix::operator*(Matrix matrix)
{
    Matrix multi(this->sizeX, matrix.sizeY);
    if (this->sizeY == matrix.sizeX) {
        for (int i = 0; i < this->sizeX; i++)
            for (int j = 0; j < matrix.sizeY; j++) {
                for (int k = 0; k < matrix.sizeX; k++)
                    multi.data[i][j] += this->data[i][k] * matrix.data[k][j];
            }
    }
    else {
        for (int i = 0; i < this->sizeX; i++)
            for (int j = 0; j < matrix.sizeY; j++)
                multi.data[i][j] = 0;
    }
    //multi.getData();
    return multi;
}

Matrix Matrix::operator/(int number)
{
    Matrix div(sizeX, sizeY);
    for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
            div.data[i][j] = data[i][j] / (double)number;
    //div.getData();
    return div;
}

Matrix::Matrix(int sizeX, int sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->data = new double* [sizeX];
    for (int i = 0; i < sizeX; i++) {
        data[i] = new double[sizeY];
        for (int j = 0; j < sizeY; j++)
            data[i][j] = 0;
    }
}

Matrix::Matrix()
{
    sizeX = 0;
    sizeY = 0;
    data = new double* [1];
    data[0] = new double[1];
    data[0][0] = 0;
}

void Matrix::enterData()
{
    for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++) {
            data[i][j] = getDouble();
        }
}

int Matrix::getSizeX()
{
    return sizeX;
}

int Matrix::getSizeY()
{
    return sizeY;
}

double** Matrix::getData()
{
    return data;
}

void Matrix::print()
{
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

class squareMatrix : public Matrix {
public:
    squareMatrix(int size);
    squareMatrix();
    squareMatrix(Matrix matrix);
    static squareMatrix powMatrix(squareMatrix matrix, int power);
    static squareMatrix sinA(squareMatrix matrix);
};

squareMatrix::squareMatrix(int size) {
    this->sizeX = size;
    this->sizeY = size;
    this->data = new double* [sizeX];
    for (int i = 0; i < sizeX; i++) {
        data[i] = new double[sizeY];
        for (int j = 0; j < sizeY; j++)
            data[i][j] = 0;
    }
}

squareMatrix::squareMatrix()
{
}

squareMatrix::squareMatrix(Matrix matrix)
{
    this->sizeX = matrix.getSizeX();
    this->sizeY = matrix.getSizeY();
    this->data = matrix.getData();
}

squareMatrix squareMatrix::powMatrix(squareMatrix matrix, int power)
{
    squareMatrix result;
    if (power <= 0)
        return result;
    else {
        result = matrix;
        for (int i = 1; i < power; i++) {
            result = result * matrix;
        }
    }
    return result;
}

squareMatrix squareMatrix::sinA(squareMatrix matrix)
{
    squareMatrix result(matrix.getSizeX());
    for (int i = 0; i < 7; i++) {
        squareMatrix temp = squareMatrix::powMatrix(matrix, 2 * i + 1);
        temp = temp * pow(-1, i);
        long long int factorial = fact(2 * i + 1);
        temp = temp / factorial;
        result = result + temp;
    }
    return result;
}


int main() {
    setlocale(LC_ALL, "ru");
    cout << "Введите размер квадратной матрицы: ";
    int size;
    cin >> size;
    squareMatrix matrix(size);
    cout << "Введите матрицу: " << endl;
    matrix.enterData();

    cout << endl << endl;
    cout << "Sin(A) = " << endl;
    squareMatrix result = squareMatrix::sinA(matrix);
    result.print();
}

double getDouble()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        return number;
    }
}

long long int fact(int number)
{
    if (number <= 0)
        return 0;
    else if (number == 1)
        return 1;
    else
        return number * fact(number - 1);
}
