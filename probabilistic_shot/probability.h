#ifndef PROBABILITY_H
#define PROBABILITY_H

namespace dailyalgorithms
{
    struct Probability
    {
        bool operator==(const Probability*) const;

        double base;
        int initial_base;
        int step;
        int damage;
    };
}

#endif // PROBABILITY_H
