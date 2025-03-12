#pragma once
#include "/repos/mp2-lab5-polinom/Polinom/Polinom.h"
#include <vector>

class Visual {
	vector<Polinom> polinoms;
	int cnt = 0;
public:
	Visual();
	void Run();
	void Update(string message = "");
};