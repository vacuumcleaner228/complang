
#include <iostream>
using namespace std;

class Myclass
{
public:
    long int result;
    long int factorial;

    void getFactorial()
    {
        if (factorial == 0)
        {
            cout << "Факториал n равен: 1" << endl;
        }
        else
        {
            do
            {
                result *= factorial;
                factorial -= 2;
            } while (factorial > 1);

            cout << "Факториал n равен: " << result;
        }
    }
    
};

long int getValue()
{
    while (true)
    {
        cout << "Введите число n: ";
        long int n;
        cin >> n;
        if ((cin.fail()) || (n < 0))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "n - число. \n";
            }
            else
            {
                cout << "n не может быть меньше 0. \n";
            }
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

    Myclass n;

    n.factorial = getValue();
    n.result = 1;
    n.getFactorial();

    return 0;
}
