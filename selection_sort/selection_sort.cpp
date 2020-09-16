#include <vector>

namespace dailyalgorithms
{
    using std::vector;

    template<typename T>
    void sort(vector<T>& container)
    {
        for (size_t i {0}; i < container.size() - 1; ++i)
        {
            size_t min_element {i};

            for (size_t j {i + 1}; j < container.size(); ++j)
            {
                if (container[j] < container[min_element])
                {
                    min_element = j;
                }
            }
            std::swap(container[min_element], container[i]);
        }
    }
}