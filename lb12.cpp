#include <iostream>
#include <math.h>

using namespace std;

double getDouble();
int getInt();

double exponent(double minZ);
long long int factorial(int x);

const double pi = 3.1415;

class Complex {
public:
    void setOneForm();
    void printComplexNumber();
    Complex exponentComplex();
private:
    void tranform();
    double a, b; // expForm
    double absb, phi; // trigForm
    bool isExpForm = false;
    bool isTrigForm = false;
};

void Complex::setOneForm() {
    cout << "Choise form of Complex number" << endl << "1 - Exp" << endl << "2 - Trig" << endl;
    int type;
    while (true) {
        type = getInt();
        if (type == 1 || type == 2)
            break;
        else
            cout << "Wrong input, please enter 1 or 2:";
    }
    switch (type) {
    case 1:
        cout << "Exp form is a + b * i" << endl;;
        cout << "Enter a: ";
        a = getDouble();
        cout << "Enter b: ";
        b = getDouble();
        isExpForm = true;
        tranform();
        break;
    case 2:
        cout << "Trig form is |b| * (cos(phi) + i * sin(phi)" << endl;
        cout << "Enter |b|: ";
        absb = getDouble();
        cout << "Enter phi: ";
        phi = getDouble();
        isTrigForm = true;
        tranform();
        break;
    default:
        break;
    }
}

void Complex::printComplexNumber() {
    cout << "Exp form: " << a << " + " << b << " * i" << endl;
    cout << "Trig form: " << absb << " * (cos(" << phi << ") + i * sin(" << phi << ")" << endl;
}

Complex Complex::exponentComplex()
{
    Complex result;
    result.a = exponent(a);
    result.b = exponent(b);
    result.isExpForm = true;
    result.tranform();
    return result;
}

void Complex::tranform()
{
    if (isExpForm) {
        absb = sqrt(pow(a, 2) + pow(b, 2));
        double cos = acos(a / absb);
        double sin = asin(b / absb);
        double rawPhi = abs(sin);
        if (sin > 0 && cos > 0)
            phi = rawPhi;
        else if (sin < 0 && cos>0)
            phi = -rawPhi;
        else if (sin < 0 && cos < 0)
            phi = -pi + rawPhi;
        else if (sin > 0 && cos < 0)
            phi = pi - rawPhi;
        else
            phi = rawPhi;
    }
    else if (isTrigForm) {
        a = cos(phi) * absb;
        b = sin(phi) * absb;
    }
}


int main() {
    Complex number;
    number.setOneForm();
    system("cls");
    cout << "You entered complex number: " << endl;
    number.printComplexNumber();
    Complex exponentComplexNumber;
    exponentComplexNumber = number.exponentComplex();
    cout << endl << "Exp(ComplexNumber): " << endl;
    exponentComplexNumber.printComplexNumber();
    return 0;
}

double getDouble() {
    while (true) {
        double number;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Do input again." << endl;
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

int getInt() {
    while (true) {
        int number;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Do input again." << endl;
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

double exponent(double minZ) {
    double z = -minZ;
    double temp, result = 0;
    for (int i = 0; i < 20; i++) {
        long long int fact = factorial(i);
        temp = pow(-1, i) * pow(z, i) / fact;
        result += temp;
    }
    return result;
}

long long int factorial(int x)
{
    if (x < 0)
        return 0;
    if (x == 0 || x == 1)
        return 1;
    if (x > 1)
        return x * factorial(x - 1);
}