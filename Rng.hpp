/*
  Copyright 2020 Atgeirr F Rasmussen

  This file is part of the individuals package.

  individuals is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  individuals is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with individuals.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <random>
#include <chrono>

namespace individuals
{

class Rng
{
public:
    static Rng& instance()
    {
        static Rng rng;
        return rng;
    }
    static double get()
    {
        return instance().getImpl();
    }

private:
    std::mt19937_64 rng_;
    std::uniform_real_distribution<double> unif_;

    Rng()
        : unif_(0.0, 1.0)
    {
        // initialize the random number generator with time-dependent seed
        // uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        uint64_t timeSeed = 12345;
        std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
        rng_.seed(ss);
    }

    double getImpl()
    {
        return unif_(rng_);
    }
};

} // namespace individuals
