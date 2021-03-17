
#include <iostream>

using namespace std;

int getSize()
{
    while (true)
    {
        cout << "Введите количество измерений i: ";
        int i;
        cin >> i;
        if ((cin.fail()) || (i < 2))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "i - число. \n";
            }
            else
            {
                cout << "i не может быть меньше 2. \n"; 
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return i;
        }
    }
}

double getValue()
{
    while (true)
    {
        double i;
        cin >> i;
        if ((cin.fail()) || (i < 0))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "E - число. \n";
            }
            else
            {
                cout << "Данное значение не может быть меньше 0. \n";
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return i;
        }
    }
}

double getProbability()
{
    while (true)
    {
        double i;
        cin >> i;
        if ((cin.fail()) || ((i >= 1) || ( i <= 0 )))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "P - число. \n";
            }
            else
            {
                cout << "Заметьте, что 0 < P < 1. \n";
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return i;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    int i = getSize();
    double *numbers = new double[i];

    for (int k = 0; k < i; k++)
    {
        cout << "Число e_" << k+1 << ": ";
        numbers[k] = getValue();
    }

    double *probabilities = new double[i];
    double prob_sum = 0;

    do {
        for (int k = 0; k < i; k++)
        {
            cout << "Вероятность P_" << k + 1 << ": ";
            probabilities[k] = getProbability();
            prob_sum += probabilities[k];
        }

        if (prob_sum != 1)
        {
            cout << "Ваша сумма вероятностей равна: " << prob_sum << ". Введите такие значения p, чтобы сумма вероятностей была равна 1 \n";
            prob_sum = 0;
        }
    } while (prob_sum != 1);

    double exceptation = 0;
    double exceptation_square = 0;

    for (int k = 0; k < i; k++)
    {
        exceptation += numbers[k] * probabilities[k];
        exceptation_square += numbers[k] * numbers[k] * probabilities[k];
    }

    cout << "Дисперсия заданной величины равна: " << exceptation_square - exceptation * exceptation;

    delete[] numbers;
    delete[] probabilities;

    return 0;
}
