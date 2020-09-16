#include <vector>

namespace dailyalgorithms
{
    using std::vector;

    // Gnome sort or "stupid" sort O(n^2) complexity because of rare decrement
    template<typename T>
    void sort(vector<T>& container)
    {
        size_t i {0};
        while (i != container.size())
        {
            if (i == 0)
            {
                ++i;
            }
            else if(container[i - 1] <= container[i])
            {
                ++i;
            }
            else
            {
                std::swap(container[i], container[i - 1]);
                --i;
            }
            
        }
    }
}