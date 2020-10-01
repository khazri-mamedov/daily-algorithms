#include <vector>
#include <algorithm>

namespace dailyalgorithms
{
    // O(nlogn) complexity
    std::vector<int> find_missing(std::vector<int>& numbers, int low, int high)
    {
        std::sort(numbers.begin(), numbers.end());

        auto iter = std::find(numbers.begin(), numbers.end(), low);
        int index = std::distance(numbers.begin(), iter);

        int i = index;
        int j = low;
        std::vector<int> range;
        while (i < numbers.size() && j <= high)
        {
            if (numbers[i] != j)
            {
                range.push_back(j);
            }
            else
            {
                ++i;
            }
            ++j;
        }
        return range;
    }
}
