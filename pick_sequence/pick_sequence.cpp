#include <vector>
#include <algorithm>

namespace dailyalgorithms
{
    // Length of subarray with <= 1 elements abs value
    int ubnormal_seq(std::vector<int> numbers)
    {
        std::sort(numbers.begin(), numbers.end());
        int count {0};
        int max {0};

        for (size_t i {0}; i != numbers.size(); ++i)
        {
            for (size_t j {i}; j != numbers.size(); ++j)
            {
                if (numbers[j] - numbers[i] <= 1)
                {
                    ++count;
                }
            }
            if (count > max)
            {
                max = count;
            }
            count = 0;
        }
        return max;
    }
}