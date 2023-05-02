#include <iostream>

template<typename T>
class Array
{
    private:
        int * _array;
        size_t _size;

    public:
        Array( void )
        {
            std::cout << "Default constructor called" << std::endl;
            this->_size = 0;
            this->_array = new T[0];
        }
        Array( Array & array)
        {
            std::cout << "Copy constructor called" << std::endl;
            this->_size = array.size();
            this->_array = new T[this->_size];
            for (size_t index = 0; index != this->_size; index++)
            {
                this->_array[index] = array[index];
            }
        }
        Array & operator= (Array & array)
        {
            std::cout << "Copy operator called" << std::endl;
            if (this != &array)
            {
                this->_size = array->size();
                this->_array = new T[this->_size];
                for (size_t index = 0; index != this->_size; index++)
                {
                    this->_array[index] = array[index];
                }
            }
            return (*this);
        }
        Array (unsigned int size)
        {
            std::cout << "Size constructor called" << std::endl;
            this->_size = size;
            this->_array = new T[size];
        }
        ~Array( void )
        {
            delete[] this->_array;
            std::cout << "Default destructor called" << std::endl;
        }
        size_t size ( void ) const{return (this->_size);}
        class IndexGreaterThanSizeException : public std::exception
        {
            public:
                virtual const char * what ( void ) const throw()
                {
                    return ("The index greater than the size of the array");
                }
        };
        T & operator[] (unsigned int index) const
        {
            if (index >= this->size())
                throw (Array::IndexGreaterThanSizeException());
            return (this->_array[index]);
        }
};

template <typename T>
std::ostream& operator<<(std::ostream& outstream, const Array<T>& array)
{
    for (size_t index = 0; index != array.size(); index++){outstream << array[index] << std::endl;}
    return (outstream);
}
