#include <iostream>
#include <math.h>

using namespace std;

class MyClass
{
public:
    double x;
    double y;

    void getAlgebraicForm()
    {
        cout << "\nКомплексное число z в алгебраической форме: " << x <<" + i("<< y << ")" << endl;
    }

    void getTrigonometricForm()
    {
        double p = abs(sqrt(x * x + y * y));
        cout << "Тригонометрическая форма числа z:\n";
        cout << "z = " << p << "(" << cos(x / p) << " + i(" << sin(y / p) << "))";
    }
};


double getValue(char n)
{
    while (true)
    {
        double value;
        cout << "Введите число " << n << ": ";
        cin >> value;
        if (cin.fail())
        {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << n <<" - число. \n";
        }
        else
        {
            cin.ignore(32767, '\n');
            return value;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    MyClass m;

    char n = 'x';
    m.x = getValue(n);
    char t = 'y';
    m.y = getValue(t);
    m.getAlgebraicForm();
    m.getTrigonometricForm();
    return 0;
}

