#include <iostream>

using namespace std;

double getValue()
{
    while (true)
    {
        cout << "Введите число n: ";
        double n;
        cin >> n;
        if ((cin.fail()) || (n < 0))
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

double getFactorial (double n)
{
    double factorial = 1;

    if (n == 0)
    {
        return 1;
    } 
    else
    {
        do 
        {
            factorial *= n;
            n -= 2;
        } while (n > 1);

        return factorial;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    
    double n = getValue();

    cout << "Двойной факториал n равен: " << getFactorial(n);

    return 0;
}
