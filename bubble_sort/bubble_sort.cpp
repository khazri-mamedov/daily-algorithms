#include <vector>

namespace dailyalgorithms
{
    using std::vector;

    // O(n^2) complexity
    template<typename T>
    void sort(vector<T>& container)
    {
        for (size_t i {0}; i != container.size() - 1; ++i)
        {
            for (size_t j {0}; j != container.size() - i - 1; ++j)
            {
                if (container[j] > container[j + 1])
                {
                    std::swap(container[j], container[j + 1]);
                }
            }
        }
    }
}