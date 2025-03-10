#pragma once
#include "TList.h"
#include "Monom.h"
#include <stdexcept>
#include <sstream>
#include <string>

class Polinom : public TList<Monom> {
public:
    Polinom() : TList<Monom>() {}
    Polinom(Monom* p, int size);
    
    void AddMonom(Monom m);

	bool operator==(const Polinom& p) const;
	bool operator!=(const Polinom& p) { return !(*this == p); };
	
	Polinom& operator=(const Polinom& p);
	Polinom operator+(Polinom& p);
	Polinom operator-(Polinom& p);
	Polinom operator*(double coef);
	Polinom operator*(Polinom& p);
	Polinom operator*(Monom m);

	friend ostream& operator<<(ostream& out, Polinom& p);
	friend istream& operator>>(istream& in, Polinom& p);
};


