#include <iostream>

using namespace std;

double getValue()
{
    while (true) 
    {
        cout << "Введите число n: ";
        double n;
        cin >> n;
        if ((cin.fail()) || (n<0))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "n - число. \n";
            }
            else cout << "n не может быть меньше 0. \n";
        }
        else
        {
            cin.ignore(32767, '\n');
            return n;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    double factorial = 1;
    double n = getValue();
    if (n == 0) {
        cout << "Факториал n равен: 1";
        return 0;
    }
    do {
        factorial *= n;
        n -= 2;
    } while (n > 1);
    cout << "Факториал n равен: " << factorial;
    return 0;
}