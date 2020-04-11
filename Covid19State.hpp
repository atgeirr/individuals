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

#include <PersonProperty.hpp>

namespace individuals
{

class Covid19State : public PersonProperty
{
public:
    enum class InfectionStage { Uninfected, Infected, Immune };
    enum class SymptomStage { NoSymptoms, Symptoms };
    virtual void stepDay(const int day) override;
    virtual bool died() const override;
private:
    int time_of_infection_ = -1;
    InfectionStage infection_stage_;
    SymptomStage symptom_stage_;
    bool died_ = false;

    static constexpr double infection_chance_ = 0.01;
    static constexpr int symptomless_days_ = 10;
    static constexpr int min_symptom_days_ = 5;
    static constexpr double well_chance_ = 0.1;
    static constexpr double die_chance_ = 0.01;
    static constexpr double immune_chance_ = 1.0;
};

} // namespace individuals
