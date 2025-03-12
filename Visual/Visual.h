#pragma once
#include "../Polinom/Polinom.h"
#include <vector>


class Visual {
	vector<Polinom> polinoms;
	int polinom_count = 0;
public:
	Visual();
	void Run();
	void Update(string message = "");
};