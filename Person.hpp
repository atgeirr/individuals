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

#include <memory>
#include <vector>

namespace individuals
{


// class PersonProperty;


class Person
{
public:
    explicit Person(const std::size_t id)
        : id_(id)
    {}
    // void addProp(std::shared_ptr<PersonProperty>&& prop)
    // {
    //     props_.push_back(std::move(prop));
    // }
    void stepDay(const int day)
    {
        // for (const auto prop : props_) {
        //     prop->stepDay(day);
        // }
        cv19_state_.stepDay(day);
    }
    bool died() const
    {
        // for (const auto prop : props_) {
        //     if (prop->died()) {
        //         return true;
        //     }
        // }
        if (cv19_state_.died()) {
            return true;
        }
        return false;
    }
private:
    std::size_t id_;
    std::size_t age_in_days_;
    Covid19State cv19_state_;
    // std::vector<std::shared_ptr<PersonProperty>> props_;
};

} // namespace individuals
