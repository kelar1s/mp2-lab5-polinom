#pragma once
#include "TList.h"
#include "Monom.h"

class Polinom : public TList<Monom> {
public:
    Polinom() : TList<Monom>() {}
    Polinom(Monom* p, int size);
    
    void AddMonom(Monom m);

	bool operator==(const Polinom& p) const;
	
	Polinom& operator=(const Polinom& p);
	Polinom operator+(Polinom& p);
	Polinom operator-(Polinom& p);
	Polinom operator*(double coef);
	Polinom operator*(Polinom& p);
	Polinom operator*(Monom m);

	friend ostream& operator<<(ostream& out, Polinom& p);
	friend istream& operator>>(istream& in, Polinom& p);
};


