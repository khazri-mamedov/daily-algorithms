#include <vector>
#include <stdexcept>

// O(logn) complexity
int binarySearch(const std::vector<int>& numbers, int first, int last, int toFind)
{
    if (last >= first)
    {
        int middle {first + (last - first) / 2};
        if (numbers[middle] == toFind)
        {
            return middle;
        }

        if (numbers[middle] > toFind)
        {
            return binarySearch(numbers, first, middle - 1, toFind);
        }

        return binarySearch(numbers, middle + 1, last, toFind);
    }
    throw std::invalid_argument {"Number isn't found!"};
}