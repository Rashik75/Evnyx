#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <vector>
using namespace std;

void benzin() {
	int a[40], dni_ezdi, kolvo_zapravok, data, j = 0, sredzap, kmnach, km, kmvozv, min, max;
	double viezd, ostatok = 0, potracheno = 0, zapravka = 0, allzap, benz, summ = 0, koef, benznach, kmnado, kmnach1;
	cout << "Машина ездила дней: ";
	cin >> dni_ezdi;
	cout << endl;
	cout << "Остаток при выезде: ";
	cin >> viezd;
	cout << endl;
	benznach = viezd;
	vector <int> dni_zapr;
	vector <double> zapravleno;
	cout << "Введите количество заправок: ";
	cin >> kolvo_zapravok;
	cout << endl;
	for (int i = 0; i < kolvo_zapravok; i++) {
		cout << "Введите день " << i + 1 << "й заправки: ";
		cin >> data;
		dni_zapr.push_back(data);
		cout << "Введите " << i + 1 << "ю заправку: ";
		cin >> benz;
		zapravleno.push_back(benz);
		cout << endl;
		summ += benz;
	}

	sredzap = summ / dni_ezdi;

	cout << "Введите показания спидометра: ";
	cin >> kmnach;
	cout << endl;
	kmnach1 = kmnach;
	cout << "Введите коэффициент: ";
	cin >> koef;
	cout << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Рекомендуемые значения диапазона:" << endl;
	cout << "min = -4    max = 1" << endl;
	cout << "Введите min диапазона: ";
	cin >> min;
	cout << "Введите max диапазона: ";
	cin >> max;
	cout << "--------------------------------------------" << endl;

	for (int i = 0; i < dni_ezdi; i++) {
		if (j >= kolvo_zapravok) {
			j = kolvo_zapravok - 1;
		}
		if (i == (dni_zapr[j] - 1)) {
			zapravka = zapravleno[j];
			cout << endl;
			cout << "--------------------------------------------" << endl;
		}
		else {
			zapravka = 0;
		}


		viezd = zapravka + viezd - potracheno;
		potracheno = sredzap + min + rand() % (max - min + 1);
		ostatok = viezd - potracheno;

		km = potracheno / koef;
		if (potracheno / koef - km > 0.5) {
			km++;
		}

		cout << "День " << i + 1 << endl;
		cout << endl;
		cout << "Показания спидометра при выезде: " << kmnach << endl;
		cout << endl;
		cout << "Заправлено: " << zapravka << endl;
		if (i == (dni_zapr[j] - 1)) {
			cout << "Остаток при выезде: " << viezd - zapravka << endl;
			j++;
		}
		else {
			cout << "Остаток при выезде: " << viezd << endl;
		}
		cout << "Остаток при возвращении: " << ostatok << endl;
		cout << "Расход: " << potracheno << endl;
		cout << "Расход: " << potracheno << endl;
		cout << "Экономия: ---" << endl;
		cout << "Перерасход: ---" << endl;
		kmvozv = kmnach + km;
		kmnach = kmvozv;
		cout << endl;
		cout << "Показания спидометра при возвращении: " << kmvozv << endl;
		cout << "Километров проехано за день: " << km << endl;
		cout << "--------------------------------------------" << endl;
	}
	cout << "Километров должно быть, исходя из бензина: ";
	kmnado = kmnach1 + ((benznach + summ - ostatok) / koef);
	cout << kmnado;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	benzin();
	int stop;
	cin >> stop;
	return 0;
}