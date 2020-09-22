#include <vector>

namespace dailyalgorithms
{
    using std::vector;

    template<typename T>
    void insertion_sort(vector<T>& container)
    {
        for (int i {1}; i < static_cast<int>(container.size()); ++i)
        {
            T key {container[i]};
            int j {i - 1};

            while (j >= 0 && container[j] > key)
            {
                container[j + 1] = container[j];
                --j;
            }

            container[j + 1] = key;
        }
    }
}
