#include <vector>
#include <unordered_set>

namespace dailyalgorithms
{
    // Find triplet with provided sum
    std::tuple<int, int, int> find_triplet_sum(std::vector<int> numbers, int sum)
    {
        for (size_t i = 0; i != numbers.size() - 2; ++i)
        {
            std::unordered_set<int> pair;
            int current_sum = sum - numbers[i];
            for (size_t j = i + 1; j < numbers.size(); ++j)
            {
                if (pair.find(current_sum - numbers[j]) != pair.end())
                {
                    return std::tuple<int, int, int>{numbers[i], numbers[j], (current_sum - numbers[j])};
                }
                pair.insert(numbers[j]);
            }
        }
        return std::tuple<int, int, int>{};
    }
}