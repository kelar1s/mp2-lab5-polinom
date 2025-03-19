#pragma once
#include "../Polinom/Polinom.h"
#include <vector>


class Visual {
	vector<Polinom> polinoms;
	int operations_count = 0;
public:
	
	Visual();
	void Run();
	void Update(string message = "");
	
	void Clear() {
		polinoms.clear();
		operations_count = 0;
	}
	void Restart() {
		if (operations_count != 0) {
			for (int i = 0; i < operations_count; i++) {
				polinoms.pop_back();
			}
			operations_count = 0;
		}
	}
};