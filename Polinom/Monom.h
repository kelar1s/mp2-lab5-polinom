#pragma once
#include <iostream>
using namespace std;

struct Monom {
	double coeff;
	int x, y, z;
public:
	Monom(double _coeff = 0, int _x = 0, int _y = 0, int _z = 0) : coeff(_coeff), x(_x), y(_y), z(_z) {}
	bool operator<(const Monom& oth);
	bool operator>(const Monom& oth);
	bool operator==(const Monom& oth) const;
	bool operator!=(const Monom& oth) const;
	friend ostream& operator<<(ostream& out, const Monom& oth);
	friend istream& operator>>(istream& in, Monom& oth);
};