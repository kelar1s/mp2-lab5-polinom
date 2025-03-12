#include "Polinom.h"

Polinom::Polinom(Monom* p, int size)
{
    int i = 0;
    while (i < size) {
        this->InsLast(p[i]);
        i++;
    }
}

void Polinom::AddMonom(Monom m) {
    if (isEmpty()) {
        InsLast(m);
    }
    else {
        if (pFirst->val < m) {
            InsFirst(m);
            return;
        }
        if (m < pLast->val) {
            InsLast(m);
            return;
        }
        for (Reset(); !IsEnd(); GoNext()) {
            if (GetCurr() < m) {
                TNode<Monom>* add = new TNode<Monom>(m);
                add->next = pCurr;
                pPrev->next = add;
                sz++;
                return;
            }
            if (GetCurr() == m) {
                double c = pCurr->val.coeff + m.coeff;
                if (c != 0) {
                    pCurr->val.coeff = c;
                }
                else {
                    if (pCurr == pFirst) {
                        DelFirst();
                    }
                    else if (pCurr == pLast) {
                        pPrev->next = nullptr;
                        pLast = pPrev;
                        sz--;
                        delete pCurr;
                    }
                    else {
                        TNode<Monom>* tmp = pCurr;
                        pPrev->next = pCurr->next;
                        sz--;
                        delete tmp;
                    }
                }
                return;
            }
        }
    }
}

bool Polinom::operator==(const Polinom& p) const {
    if (this == &p) return true;
    if (sz != p.sz) return false;

    TNode<Monom>* tmp1 = pFirst;
    TNode<Monom>* tmp2 = p.pFirst;

    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->val != tmp2->val) {
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return tmp1 == nullptr && tmp2 == nullptr;
}

Polinom& Polinom::operator=(const Polinom& p)
{
    if (this == &p) return *this;
    TList<Monom>::operator=(p); 
    return *this;
}

Polinom Polinom::operator+(Polinom& p)
{
    /*Polinom res(*this);
    for (p.Reset(); !p.IsEnd(); p.GoNext()) {
        Monom tmp = p.GetCurr();
        res.AddMonom(tmp);
    }
    return res;*/

    Polinom result(*this);
    result.Reset();
    p.Reset();

    while (!result.IsEnd() && !p.IsEnd()) {
        Monom result_curr = result.GetCurr();
        Monom p_curr = p.GetCurr();

        if (result_curr == p_curr) {
            double c = result_curr.coeff + p_curr.coeff;
            if (c == 0) {
                result.DelCurr();
            }
            else {
                result.GetCurr().coeff = c;
                result.GoNext();
            }
            p.GoNext();
        }
        else if (result_curr < p_curr) {
            result.InsCurr(p_curr);
            p.GoNext();
        }
        else {
            result.GoNext();
        }
    }

    while (!p.IsEnd()) {
        result.InsLast(p.GetCurr());
        p.GoNext();
    }

    return result;
}

Polinom Polinom::operator-(Polinom& p)
{
    Polinom result;
    Polinom negative_p = p * (-1);
    result = *this + negative_p;
    return result;
}

Polinom Polinom::operator*(double coef)
{
    Polinom result(*this);
    if (coef == 0.0) {
        result.Clear();
    } 
    else {
        for (result.Reset(); !result.IsEnd(); result.GoNext()) {
            result.GetCurr().coeff *= coef;
        }
    }
    return result;
}

Polinom Polinom::operator*(Polinom& p)
{
    Polinom res, multer(*this);
    if (p.sz == 0) return res;
    for (p.Reset(); !(p.IsEnd()); (p.GoNext())) {
        Polinom tmp = (*this * p.GetCurr());
        res = (res + tmp);
    }
    return res;
}

Polinom Polinom::operator*(Monom m)
{
    Polinom res;
    if (m.coeff == 0.0) return res;
    for (Reset(); !IsEnd(); GoNext()) {
        Monom tmp;
        tmp.coeff = GetCurr().coeff * m.coeff;
        tmp.x = m.x + GetCurr().x;
        tmp.y = m.y + GetCurr().y;
        tmp.z = m.z + GetCurr().z;
        res.AddMonom(tmp);
    }
    return res;
}

ostream& operator<<(ostream& out, Polinom& p)
{
    if (p.isEmpty()) {
        out << "0";
        return out;
    }
    p.Reset();
    out << p.GetCurr();
    p.GoNext();
    for (; !p.IsEnd(); p.GoNext()) {
        out << (p.GetCurr().coeff >= 1 ? " + " : " ") << p.GetCurr();
    }
    return out;
}

istream& operator>>(istream& in, Polinom& p) {
    p.Clear();
    string input;
    double coeff;
    int x, y, z;

    cout << "\033[33mEnter monoms (coeff x y z). Enter 'done' to finish!\033[0m" << endl;

    while (true) {
        cout << "\033[33mcoeff x y z: \033[0m";
        in >> input;

        if (input == "done") break;

        try {
            coeff = stod(input);
        }
        catch (...) {
            cout << "\033[31mInvalid input. Please enter a number or 'done'.\033[0m" << endl;
            continue;
        }
        in >> x >> y >> z;
        Monom m(coeff, x, y, z);
        p.InsLast(m);
    }
    return in;
}