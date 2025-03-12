#include "Visual.h"
#include "../Polinom/Polinom.cpp"
#include "../Polinom/Monom.h"
#include "../Polinom/Monom.cpp"
#include <chrono>
#include <thread>

Visual::Visual() {
	Monom m1[3] = { Monom(9, 9, 9, 9), Monom(8, 8, 8, 8), Monom(7, 7, 7, 7) };
	Monom m2[3] = { Monom(10, 10, 10, 10), Monom(-9, 9, 9, 9), Monom(5, 7, 7, 7) };
	Monom m3[1] = { Monom(2, 2, 2, 2) };

	Polinom p1(m1, 3), p2(m2, 3), p3(m3, 1);

	polinoms.push_back(p1);
	polinoms.push_back(p2);
	polinoms.push_back(p3);
}

void Visual::Run() {
    Update();
    char key = 'a';
    while (key != 'q') {
        cin >> key;
        Polinom res;
        int number1, number2;
        switch (key) {
        case '1': // Сложение полиномов
            cin >> number1 >> number2;
            if (number1 >= polinoms.size() || number2 >= polinoms.size()) {
                Update("what?");
            }
            else {
                try {
                    res = polinoms[number1] + polinoms[number2];
                    polinoms.push_back(res);
                    polinom_count++;
                    Update();
                }
                catch (...) {
                    Update("what?");
                }
            }
            break;

        case '2': // Вычитание полиномов
            cin >> number1 >> number2;
            if (number1 >= polinoms.size() || number2 >= polinoms.size()) {
                Update("what?");
            }
            else {
                try {
                    res = polinoms[number1] - polinoms[number2];
                    polinoms.push_back(res);
                    polinom_count++;
                    Update();
                }
                catch (...) {
                    Update("what?");
                }
            }
            break;

        case '3': // Умножение полиномов
            cin >> number1 >> number2;
            if (number1 >= polinoms.size() || number2 >= polinoms.size()) {
                Update("what?");
            }
            else {
                try {
                    res = polinoms[number1] * polinoms[number2];
                    polinoms.push_back(res);
                    polinom_count++;
                    Update();
                }
                catch (...) {
                    Update("what?");
                }
            }
            break;

        case '4': // Умножение полинома на число
            int number, c;
            cin >> number >> c;
            if (number >= polinoms.size()) {
                Update("what?");
            }
            else {
                try {
                    res = polinoms[number] * c;
                    polinoms.push_back(res);
                    polinom_count++;
                    Update();
                }
                catch (...) {
                    Update("what?");
                }
            }
            break;

        case '5': // Ввод
            try {
                cin >> res;
                polinoms.push_back(res);
                polinom_count++;
                Update();
            }
            catch (...) {
                Update("what?");
            }
            break;

        default:
            Update("what?");
            break;
        }
    }
    Update("Quitting...");
    this_thread::sleep_for(chrono::seconds(1));
    exit(0);
}

void Visual::Update(string message) {
    system("cls");

    cout << "Polinoms count: " << polinoms.size() << endl;
    cout << "Operations are done: " << polinom_count << endl;

    cout << endl << "Polinoms: "<< endl << endl;

    for (int i = 0; i < polinoms.size(); i++) {
        cout << "      " << "\033[33m" << i << ") " << polinoms[i] << "\033[0m" << endl;
    }

    // Меню операций
    cout << endl << "Choose operation:" << endl << endl;
    cout << "      " <<"1: Polinoms add" << endl;
    cout << "      " << "2: Polinoms subtract" << endl;
    cout << "      " << "3: Polinoms multiply" << endl;
    cout << "      " << "4: Polinoms multiply by const" << endl;
    cout << "      " << "5: Polinoms input" << endl;
    cout << "      " << "q: Quit" << endl << endl;

    if (message != "") {
        cout << "\033[31m" << message << "\033[0m" << endl;
    }
}