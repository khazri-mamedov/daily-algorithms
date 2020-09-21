#include <vector>

namespace dailyalgorithms
{
    using std::vector;

    template<typename T>
    void cocktail_sort(vector<T>& container)
    {
        bool swapped {true};
        size_t start {0};
        size_t end {container.size() - 1};

        while (swapped)
        {
            for (size_t i {start}; i < end; ++i)
            {
                if (container[i] > container[i + 1])
                {
                    std::swap(container[i], container[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
            {
                return;
            }

            swapped = false;

            --end;

            for (size_t i = end - 1; i >= start && i != SIZE_MAX; --i)
            {
                if (container[i] > container[i + 1])
                {
                    std::swap(container[i], container[i + 1]);
                    swapped = true;
                }
            }

            ++start;
        }
    }
}
