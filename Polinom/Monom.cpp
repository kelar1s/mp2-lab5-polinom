#include "Monom.h"

bool Monom::operator<(const Monom& oth)
{
    if (this->x != oth.x) return this->x < oth.x;
    if (this->y != oth.y) return this->y < oth.y;
    return this->z < oth.z;
}

bool Monom::operator>(const Monom& oth)
{
    return !(this->operator<(oth));
}

bool Monom::operator==(const Monom& oth) const {
    return this->x == oth.x && this->y == oth.y && this->z == oth.z;
}

bool Monom::operator!=(const Monom& oth) const {
    return !(*this == oth);
}

ostream& operator<<(ostream& out, const Monom& oth)
{
    out << oth.coeff;
    if (oth.x != 0) cout << "*x^" << oth.x;
    if (oth.y != 0) cout << "*y^" << oth.y;
    if (oth.z != 0) cout << "*z^" << oth.z;
    return out;
}

istream& operator>>(istream& in, Monom& oth)
{
    in >> oth.coeff >> oth.x >> oth.y >> oth.z;
    return in;
}
