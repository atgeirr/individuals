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

#include <Covid19State.hpp>
#include <Person.hpp>
#include <Population.hpp>
#include <Rng.hpp>

#include <iomanip>
#include <iostream>

int main()
{
    const std::size_t num = 10000;
    individuals::Population pop(num);
    const int days = 365;
    for (int day = 0; day < days; ++day) {
        pop.stepDay(day);
        std::cout << "After day " << std::setw(5) << day << " remaining population is " << std::setw(10) << pop.size() << std::endl;
    }
}
