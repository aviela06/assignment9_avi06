#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <iostream>

template <typename T>
class GenericArray
{
private:
    T *data;     // the array, of whatever type T is
    int length;  // how many elements it holds

public:
    GenericArray() // default constructor
    {
        data = nullptr; // no array yet
        length = 0;     // empty
    }

    ~GenericArray() // destructor
    {
        delete[] data; // free the array
    }

    void addElement(T element) // add to the end
    {
        T *new_data = new T[length + 1]; // new array, one bigger
        for (int i = 0; i < length; i++) // copy old elements
        {
            new_data[i] = data[i];
        }
        new_data[length] = element; // new element in the last slot
        delete[] data;    // free the old array
        data = new_data;  // point at the new array
        length++;         // one more element
    }

    T at(int index) // value at a position
    {
        return data[index];
    }

    int size() // number of elements
    {
        return length;
    }

    T sum() // add up every element
    {
        T total = 0; // running total
        for (int i = 0; i < length; i++)
        {
            total += data[i]; // add this element
        }
        return total;
    }

    T max() // largest element
    {
        T biggest = data[0]; // start with the first element
        for (int i = 1; i < length; i++)
        {
            if (data[i] > biggest) // found a bigger one
            {
                biggest = data[i];
            }
        }
        return biggest;
    }

    T min() // smallest element
    {
        T smallest = data[0]; // start with the first element
        for (int i = 1; i < length; i++)
        {
            if (data[i] < smallest) // found a smaller one
            {
                smallest = data[i];
            }
        }
        return smallest;
    }

    T *slice(int begin, int end) // new array from begin to end
    {
        if (begin < 0 || end >= length || begin > end) // check bounds
        {
            std::cout << "invalid slice\n";
            return nullptr;
        }
        T *piece = new T[end - begin + 1]; // new array for the slice
        for (int i = 0; i < end - begin + 1; i++)
        {
            piece[i] = data[begin + i]; // copy from the original
        }
        return piece;
    }
};

#endif
