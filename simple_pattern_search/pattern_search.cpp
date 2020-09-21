#include <string>
#include <exception>
#include <utility>

namespace dailyalgorithms
{
    using std::string;

    const std::pair<int, int> match_pattern(const string& text, const string& pattern)
    {
        const size_t p_size {pattern.size()};
        for (size_t i {0}; i < text.size(); ++i)
        {
            size_t j {0};

            for (; j < p_size; ++j)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }

            if (j == p_size)
            {
                return std::make_pair<int, int>(i, i + (p_size - 1));
            }
        }
        throw std::bad_exception {};
    }
}
