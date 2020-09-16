#ifndef SHOT_H
#define SHOT_H

#include "probability.h"
#include <vector>

namespace dailyalgorithms
{
    class Shot
    {
        public:
        Shot(std::vector<Probability*>&);
        Probability* calculate_damage();
        void change_probabilities(Probability*);

        private:
        std::vector<Probability*> shots;
    };
}

#endif // SHOT_H
