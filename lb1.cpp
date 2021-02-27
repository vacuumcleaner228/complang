#include <iostream>

using namespace std;

int main() {
	double S;
	double S0;
	double V;
	double t;
	setlocale(LC_ALL, "RUS");
	do {
		cout << "Введите время t: ";
		cin >> t;
		if (cin.fail()) {
			cout << "Ошибка ввода: t - число.\n";
			cin.clear();
			cin.ignore(32767, '\n');
			fflush(stdin);
		}
		else

			if (t <= 0)
			{
				cout << "Ошибка ввода: t строго больше 0.\n";
				cin.clear();
				fflush(stdin);
			}
	} while (t <= 0);

	do {
		cout << "Введите скорость V: ";
		cin >> V;
		if (cin.fail())
		{
			cout << "Ошибка ввода: V - число.\n";
			cin.clear();
			cin.ignore(32767, '\n');
			fflush(stdin);
		}
		else

			if (V <= 0)
			{
				cout << "Ошибка ввода: V строго больше 0.\n";
				cin.clear();
				fflush(stdin);
			}
	} while (V <= 0);


	S0 = (3 * V * t) / 2;

	S = (V * t) + (((V / t) * t * t) / 2);

	cout << "Значение по формуле 3Vt/2:" << S0;
	cout << "\n";
	cout << "Значение по формуле Vt+a^2t:" << S;

}