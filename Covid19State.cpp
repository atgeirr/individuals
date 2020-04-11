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

#include <Rng.hpp>

namespace individuals
{

void
Covid19State::stepDay(const int day)
{
    switch (infection_stage_) {
    case InfectionStage::Uninfected:
        if (Rng::get() < infection_chance_) {
            infection_stage_ = InfectionStage::Infected;
            time_of_infection_ = day;
        }
        break;
    case InfectionStage::Infected:
        switch (symptom_stage_) {
        case SymptomStage::NoSymptoms:
            if (day - time_of_infection_ > symptomless_days_) {
                symptom_stage_ = SymptomStage::Symptoms;
            }
            break;
        case SymptomStage::Symptoms:
            if (Rng::get() < die_chance_) {
                died_ = true;
            } else if (day - time_of_infection_ > symptomless_days_ + min_symptom_days_) {
                if (Rng::get() < well_chance_) {
                    symptom_stage_ = SymptomStage::NoSymptoms;
                    if (Rng::get() < immune_chance_) {
                        infection_stage_ = InfectionStage::Immune;
                    } else {
                        infection_stage_ = InfectionStage::Uninfected;
                    }
                }
            }
            break;
        }
        break;
    case InfectionStage::Immune:
        // Do nothing.
        break;
    }
}
bool
Covid19State::died() const
{
    return died_;
}

} // namespace individuals
