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

#include <Covid19State.hpp>
#include <Person.hpp>

namespace individuals
{


class Population
{
public:
    explicit Population(const std::size_t size)
    {
        persons_.reserve(size);
        for (std::size_t id = 0; id < size; ++id) {
            persons_.emplace_back(id);
            // persons_.back().addProp(std::make_shared<Covid19State>());
        }

    }
    void stepDay(const int day)
    {
        for (auto& p : persons_) {
            p.stepDay(day);
        }
        auto isdead = [](const Person& p) { return p.died(); };
        persons_.erase(std::remove_if(persons_.begin(), persons_.end(), isdead), persons_.end());
    }
    std::size_t size() const
    {
        return persons_.size();
    }
private:
    std::vector<Person> persons_;
};

} // namespace individuals
