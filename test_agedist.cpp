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

#include <AgeDistribution.hpp>

#include <iomanip>
#include <iostream>
#include <map>

int main()
{
    // Make a random number generator.
    std::mt19937_64 gen;
    uint64_t seed = 12345;
    std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed >> 32)};
    gen.seed(ss);

    // The distribution function.
    individuals::AgeDistribution adist;

    // Draw 'num' ages from the distribution, assign to brackets.
    const std::size_t num = 100000;
    std::map<int, int> hist;
    for (int i = 0; i < num; ++i) {
        const double age = adist(gen);
        const int bracket = std::floor(age/5.0);
        ++hist[bracket];
    }

    // Visualize brackets.
    const int num_brackets = hist.size();
    const double average_per_bracket = double(num) / double(num_brackets);
    const double factor = 20.0 / average_per_bracket;
    for (const auto& elem : hist) {
        const int reps = factor * elem.second;
        for (int i = 0; i < reps; ++i) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
