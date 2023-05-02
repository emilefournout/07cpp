template <typename T>
void swap (T & first, T & second)
{
    T saver;
    saver = first;
    first = second;
    second = saver;
}

template <typename T>
T   min (T & first, T & second)
{
    return (first < second ? first : second);
}

template <typename T>
T   max(T & first, T & second)
{
    return (first > second ? first : second);
}
