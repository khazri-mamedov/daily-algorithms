#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>
#include "shot.h"

dailyalgorithms::Shot::Shot(std::vector<Probability*>& shots): shots(shots) {}

dailyalgorithms::Probability* dailyalgorithms::Shot::calculate_damage()
{
    static std::default_random_engine dre (std::chrono::steady_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<double> uid {0, 1};

    int total {0};
    for (auto& shot : shots)
    {
        total += shot->base;
    }

    double value {uid(dre) * total};

    for (auto& shot : shots)
    {
        if (shot->base > value)
        {
            return shot;
        }
        value -= shot->base;
    }
    return nullptr;
}

void dailyalgorithms::Shot::change_probabilities(Probability* optimistic_shot)
{
    for (auto& shot : shots)
    {
        if (shot == optimistic_shot)
        {
            shot->base = shot->initial_base;
            continue;
        }
        shot->base = shot->base + shot->step;
    }
}
