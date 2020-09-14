#include <system_error>

namespace dailyalgorithms
{
    // Instead of custom overflow checking, use list init for number
    int first_digit(int number)
    {
        if (number < 0)
        {
            throw std::invalid_argument("Number must be > 0");
        }
        while(number > 10)
        {
            number = number / 10; 
        }
        return number;
    }
}