#include "Polinom.h"

Polinom::Polinom(Monom* p, int size)
{
    int i = 0;
    while (i < size) {
        this->InsLast(p[i]);
        i++;
    }
}

void Polinom::AddMonom(Monom m) //+=
{
    if (isEmpty()) {
        InsLast(m);
    }
    else {
        if (m > pFirst->val) {
            InsFirst(m);
        }
        if (m < pLast->val) {
            InsLast(m);
        }
        for (Reset(); !IsEnd(); GoNext()) {
            if (m > GetCurr() || m == GetCurr()) {
                if (m > GetCurr()) {
                    TNode<Monom>* nw = new TNode<Monom>(m);
                    nw->next = pCurr;
                    pPrev->next = nw;
                }
                else {
                    double res = GetCurr().coeff + m.coeff;
                    if (res != 0) {
                        GetCurr().coeff = res;
                    }
                    else {
                        if (pCurr == pFirst) {
                            DelFirst();
                            pCurr = pCurr->next;
                        }
                        else {
                            TNode<Monom>* tmp = pCurr;
                            pPrev->next = pCurr->next;
                            pCurr = pCurr->next;
                            delete tmp;
                        }
                    }
                }
            }
        }
    }
}

bool Polinom::operator==(const Polinom& p) const
{
    return false;
}

Polinom& Polinom::operator=(const Polinom& p)
{

}

Polinom Polinom::operator+(Polinom& p)
{
    Polinom res(*this);
    for (p.Reset(); !p.IsEnd(); p.GoNext()) {
        Monom tmp = p.GetCurr();
        res.AddMonom(tmp);
    }
    return res;
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

istream& operator>>(istream& in, Polinom& p)
{
    
}
