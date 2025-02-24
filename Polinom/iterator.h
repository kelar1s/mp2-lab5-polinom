#pragma once
#include <iterator>

template <typename ValueType> class TList;

template<typename ValueType>
class TListIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
    friend class TList<ValueType>;
private:
    typename TList<ValueType>::TNode* pCurr;
    TListIterator(typename TList<ValueType>::TNode* p);
public:
    TListIterator(const TListIterator& it);

    bool operator!=(TListIterator const& other) const;
    bool operator==(TListIterator const& other) const;
    typename TListIterator<ValueType>::reference operator*() const;
    TListIterator& operator++();
    /*size_t operator-(TListIterator const& other) const
    {
        return pCurr - other.pCurr;
    }*/
};

template<typename ValueType>
TListIterator<ValueType>::TListIterator(typename TList<ValueType>::TNode* p) : pCurr(p)
{

}

template<typename ValueType>
TListIterator<ValueType>::TListIterator(const TListIterator& it) : pCurr(it.pCurr)
{

}

template<typename ValueType>
bool TListIterator<ValueType>::operator!=(TListIterator const& other) const
{
    return pCurr != other.pCurr;
}

template<typename ValueType>
bool TListIterator<ValueType>::operator==(TListIterator const& other) const
{
    return pCurr == other.pCurr;
}

template<typename ValueType>
typename TListIterator<ValueType>::reference TListIterator<ValueType>::operator*() const
{
    if (!pCurr) {
        throw -1;
    }
    return pCurr->value;
}

template<typename ValueType>
TListIterator<ValueType>& TListIterator<ValueType>::operator++()
{
    if (pCurr) {
        pCurr = pCurr->next;
    }
    return *this;
}