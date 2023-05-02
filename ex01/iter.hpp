#include <iostream>

template <typename T>
void iter(T array[], size_t size, void (*function)(T const &))
{
    for(size_t index = 0; index != size; index++)
    {
        function(array[index]);
    }
}

template <typename T>
void func(T const & array)
{
    std::cout << array << std::endl;
}
