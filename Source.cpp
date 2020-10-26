﻿#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

//Функция проверки.
int Cin(long min, long max) {
	long a;
	//Проверяем рациональность числа и ввод лишних символов 
	while (!(cin >> a) || (cin.peek() != '\n')){
		cin.clear();
		while (cin.get() != '\n');
		cout << "Явно присутствуют некорректные для данного типа символы. Проверьте корректность." << endl;
	}

	//Исключение нуля
	if (a == 0) {
		cout << "Введите число отличное от нуля" << endl;
		a = Cin(min, max);
	}
	//Верхний предел
	if (a > max) {
		cout << "Число выходит за промежуток. По условию a =< " << max << " и а >= " << min << endl;
			a = Cin(min, max);
	}
	//Нижний Предел
	if (a < min) {
		cout << "Число выходит за промежуток. По условию a =< "<< max << " и а >= "<< min << endl;
		a = Cin(min, max);
	}
	//Исключение отрицательных чисел
	if (a < 0) {
		cout << "Вы ввели (" << a << ") Возьмем все-таки положительное, то есть " << abs(a) << endl;
		a = abs(a);
	}

	return a;
}

int main() {
	cout << endl;
	setlocale(LC_ALL, "rus");
	int min = -2147483647, max = pow(10, 9);
	int s;
	cout << "Введите № задания:\n 1 - 'СПИННЕРЫ'\n 2 - 'СНОВА СПИННЕРЫ'\n 3 - 'НЕ ПРО СПИННЕРЫ'\n 4 - 'ПЛАЦКАРТНЫЙ ВАГОН'\n 5 - 'КИОНОТЕАТР'\n 6 - Завершение программы\nНомер -  ";
	s = Cin(-6, 6);
	switch (s){
	case 6:
		break;
	case 1://____________________________________________________________________Первая программа
				cout << endl;
				int a, b, c;

				cout << "Введите стоимость основания " << endl;
				a = Cin(min, max);

				cout << "Введите стоимость одной лопасти " << endl;
				b = Cin(min, max);

				cout << "Введите максимальную стоимость, которую готов заплатить покупатель " << endl;
				c = Cin(min, max);

				if (a > c) {
					cout << "Стоимость основания УЖЕ превышает цену, которую готов заплатить покупатель " << endl;
				}
				else {
					cout << "Максимальное количество лопастей равно " << (c - a) / b << endl;
				}

				main();
		break;
	case 2://____________________________________________________________________Вторая программа
				cout << endl;
				int M, tri, CHETbIPE;
				cout << "Введите количество лопастей " << endl;
				M = Cin(min, max);

				CHETbIPE = 0;
				tri = 0;

				if (M > 4) {
					while (M >= 4) {
						M -= 4;
						CHETbIPE++;
					}
				}
				if (M >= 3) {
					while (M >= 3) {
						M -= 3;
						tri++;
					}
				}

				cout << "Количество спиннеров с 3-я лопостями " << tri << endl;
				cout << "Количество спиннеров с 4-я лопостями " << CHETbIPE << endl;

				main();
		break;
	case 3://____________________________________________________________________Третья программа
				cout << endl;
				int A, B;

				cout << "Введите длинну " << endl; A = Cin(-75000, 75000);

				cout << "Введите ширину " << endl; B = Cin(-75000, 75000);
				//Упрощая формулы расчета, можно прийти к данному выражению:
				cout << (A + 1) * (B + 1) * A * B / 4 << endl;

				main();
		break;
	case 4://____________________________________________________________________Чеетвертая программа
				cout << endl;

				char arr[55]; int x, y;
				//Заполняем массив единицами
				for (int i = 0; i <= 54; i++) {
					arr[i] = '1';
				}
				cout << "Введите количество свободных мест" << endl; x = Cin(-54, 54);
				for (int i = 0; i < x; i++) {
					cout << "—— Ввeдите номер свободного места " << endl; y = Cin(-54, 54);
					//Проверка на ввод одного и того же места
					if (arr[y] == '0') {
						cout << "Вы уже вводили номер этого места. Введите корректный номер." << endl;
						i--;
					}
					else {
						arr[y] = '0';//Если место свободно меняем единицу на ноль 
					}
				}

				//Считываем данные из получившегося в итоге массива
				if ((arr[1] == '0') & (arr[2] == '0') & (arr[3] == '0') & (arr[4] == '0') & (arr[53] == '0') & (arr[54] == '0')) {
					cout << "Свободно 1-е купе" << endl;
				}
				else {
					cout << "1-е купе не свободно" << endl;
				}
				if ((arr[5] == '0') & (arr[6] == '0') & (arr[7] == '0') & (arr[8] == '0') & (arr[52] == '0') & (arr[51] == '0')) {
					cout << "Свободно 2-е купе" << endl;
				}
				else {
					cout << "2-е купе не свободно" << endl;
				}
				if ((arr[12] == '0') & (arr[9] == '0') & (arr[10] == '0') & (arr[11] == '0') & (arr[50] == '0') & (arr[49] == '0')) {
					cout << "Свободно 3-е купе" << endl;
				}
				else {
					cout << "3-е купе не свободно" << endl;
				}
				if ((arr[16] == '0') & (arr[13] == '0') & (arr[14] == '0') & (arr[15] == '0') & (arr[47] == '0') & (arr[48] == '0')) {
					cout << "Свободно 4-е купе" << endl;
				}
				else {
					cout << "4-е купе не свободно" << endl;
				}
				if ((arr[20] == '0') & (arr[17] == '0') & (arr[18] == '0') & (arr[19] == '0') & (arr[46] == '0') & (arr[45] == '0')) {
					cout << "Свободно 5-е купе" << endl;
				}
				else {
					cout << "5-е купе не свободно" << endl;
				}
				if ((arr[24] == '0') & (arr[21] == '0') & (arr[22] == '0') & (arr[23] == '0') & (arr[43] == '0') & (arr[44] == '0')) {
					cout << "Свободно 6-е купе" << endl;
				}
				else {
					cout << "6-е купе не свободно" << endl;
				}
				if ((arr[25] == '0') & (arr[26] == '0') & (arr[27] == '0') & (arr[28] == '0') & (arr[42] == '0') & (arr[41] == '0')) {
					cout << "Свободно 7-е купе" << endl;
				}
				else {
					cout << "7-е купе не свободно" << endl;
				}
				if ((arr[29] == '0') & (arr[30] == '0') & (arr[31] == '0') & (arr[32] == '0') & (arr[39] == '0') & (arr[40] == '0')) {
					cout << "Свободно 8-е купе" << endl;
				}
				else {
					cout << "8-е купе не свободно" << endl;
				}
				if ((arr[33] == '0') & (arr[34] == '0') & (arr[35] == '0') & (arr[36] == '0') & (arr[38] == '0') & (arr[37] == '0')) {
					cout << "Свободно 9-е купе" << endl;
				}
				else {
					cout << "9-е купе не свободно" << endl;
				}

				main();
		break;
	case 5://____________________________________________________________________Пятая программа
				cout << endl;
				int n, k, q, Q;
				cout << "Введите количество детей" << endl; k = Cin(-2147483647, pow(10, 9));

				cout << "Введите количество мест" << endl; n = Cin(k, pow(10, 9));

				//Можно заметить, что длины участков сокращаются в два раза, а количество участков такой длины увеличивается в два раза. Отсюда:
				while (k != 1) {
					n = (n - (k % 2)) / 2;
					k = k / 2;
					q = (n - 1) / 2; Q = n / 2;
				}
				cout << q <<" "<< Q << endl;

				if (k == 1) {
					cout << (n - 1) / 2 << " " << n / 2 << endl;
				}

				main();
		break;
	default:
		break;
	}
	
}