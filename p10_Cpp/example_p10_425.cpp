/* Sparse array - infinite array that includes some non-zero elements,
 * more less than zero elements.
 * Provide() search the element by index and returns value field reference.
 * If there's no element with such index, element will be created.
 * Remove() will delete element by index.
 */

#include <stdio.h>

class SparseArrayInt {
    struct Item {
        int index;
        int val;
        Item *next;
    };
    Item *first;
public:
    SparseArrayInt() : first(0) {} // create 1st element = NULL
    ~SparseArrayInt();

    class Interm {
        friend class SparseArrayInt;
        SparseArrayInt *master;
        int idx;
        Interm(SparseArrayInt *a_master, int ind) : master(a_master), idx(ind) {}
        int& Provide();
        void Remove();
    public:
        operator int(); // cast operator
        int operator=(int x);
        int operator+=(int x);
        int operator++();
        int operator++(int);
    }

    friend class Interm;
    Interm operator[](int idx) { return Interm(this, idx); }
    int operator[](int idx) const;
    /* const method is other, even when they have same parameters.
     * In this case, const method is for reading.
     */
private:
    SparseArrayInt(const SparseArrayInt&) {} // refuse copy Infinite array
    void operator=(const SparseArrayInt&) {} // refuse assignment.
};


SparseArrayInt::~SparseArrayInt()
{
    while(first) {
        Item *tmp = first;
        first = tmp->next; // first = first->next is the same?
        delete(tmp);
    }
}

int SparseArrayInt::operator[](int idx) const
{
    Item *tmp;
    for (tmp = first; tmp; tmp = tmp->next)
        if( tmp->index == idx )
            return tmp->val;
    return 0;
}

// Intermediate class methods, main functionality of our array:

int SparseArrayInt::Interm::operator=(int x)
{
    if (x == 0)
        Remove();
    else
        Provide() = x; // Provide() is l-value, because it's type of int&.
    return x;
}

int SparseArrayInt::Interm::operator+=(int x)
{

}




int& SparseArrayInt::Interm::Provide()
{
    Item *tmp; // Type of first is Item*. Type of master if SparseArrayInt*
    for (tmp = master->first; tmp; tmp = tmp->next)
        if (tmp->idx == idx) // compare idx from Item and idx from Interm,
                             // which was received from operator[].
            return tmp->val; // this line returns object type int or int&?
//    if object not found by index:
    tmp = new Item;
    tmp->idx = idx;
    tmp->next = master->first;
    master->first = tmp;
    return tmp->val;
}

void SparseArrayInt::Interm::Remove()
{
    Item **tmp; // pointer-to-pointer technique for clear linked list element.
    for (tmp = &(master->first); *tmp; tmp = &(*tmp)->next) {
        if ((*tmp)->idx == idx) {
            Item *to_delete = *tmp;
            *tmp = (*tmp)->next;
            delete to_delete;
            return;
        }
    }
}









