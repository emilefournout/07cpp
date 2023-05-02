#include "iter.hpp"

int main(int argc, char * argv[])
{
    iter<char*>(argv, argc, func);
    int array [3] = {2, 3, 1};
    iter<int>(array, 3, func);
}
