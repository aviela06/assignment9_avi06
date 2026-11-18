#include <iostream>
#include "generic_array.h"

int main()
{
    GenericArray<int> int_array;
    for (int i = 1; i <= 11; i++) // add numbers 1 to 11
    {
        int_array.addElement(i);
    }

    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is " << int_array.max() << "\t" << int_array.min() << std::endl;

    int *sliced_array = int_array.slice(5, 10); // elements 5 through 10
    if (sliced_array != nullptr) // only print if the slice worked
    {
        std::cout << "sliced array: ";
        for (int i = 0; i < 6; i++)
        {
            std::cout << sliced_array[i] << " ";
        }
        std::cout << std::endl;
        delete[] sliced_array; // free the slice
    }

    return 0;
}
