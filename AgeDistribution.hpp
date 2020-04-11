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

namespace individuals
{

    class AgeDistribution
    {
    public:
        AgeDistribution()
        {
            std::vector<double> age_brackets = { 0.0, 25.0, 35.0, 45.0, 70.0, 80.0, 95.0 };
            std::vector<double> weights = { 1.59, 0.75, 0.7, 1.67, 0.44, 0.23 };
            distr_ = std::piecewise_constant_distribution<double>(age_brackets.begin(),
                                                                  age_brackets.end(),
                                                                  weights.begin());
        }
        template <class Generator>
        double operator()(Generator& g)
        {
            return distr_(g);
        }
    private:
        std::piecewise_constant_distribution<double> distr_;
    };

} // namespace individuals
