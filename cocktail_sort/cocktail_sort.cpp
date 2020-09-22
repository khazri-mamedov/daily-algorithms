#include <vector>

namespace dailyalgorithms
{
    using std::vector;

    template<typename T>
    void cocktail_sort(vector<T>& container)
    {
        bool swapped {true};
        long start {0};
        long end {static_cast<long>(container.size() - 1)};

        while (swapped)
        {
            for (long i {start}; i < end; ++i)
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

            for (long i {end - 1}; i >= start; --i)
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
