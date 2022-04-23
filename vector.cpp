#include <iostream>
#include "vector.h"
template<typename T>
void print(const Vector<T>& vector)
{
        for (size_t i = 0; i < vector.size(); ++i)
                cout << i << " ";
}
int main()
{
        Vector<int> vec;
        vec.pushback(49);
}

