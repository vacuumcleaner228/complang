
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    double n=0;
    double factorial=1;
    cout << "Введите число n: ";
    cin >> n;
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
