/*
 * This file is part of the EDS: Event-aided Direct Sparse Odometry
 * (https://rpg.ifi.uzh.ch/eds.html)
 *
 * This file is modified and part of the MC-VEO
 * (https://cslinzhang.github.io/MC-VEO/)
 * 
 * Copyright (c) 2022 Javier Hidalgo-Carrió, Robotics and Perception
 * Group (RPG) University of Zurich.
 *
 * MC-VEO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * MC-VEO is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MC-VEO_TYPES_HPP
#define MC-VEO_TYPES_HPP


#include <mc-veo/tracking/Config.hpp>
#include <mc-veo/mapping/Config.hpp>
#include <mc-veo/bundles/Config.hpp>
#include <mc-veo/utils/Config.hpp>

#include <base/Time.hpp>
#include <base/samples/RigidBodyState.hpp>

/* If you need to define types specific to your oroGen components, define them
 * here. Required headers must be included explicitly
 *
 * However, it is common that you will only import types from your library, in
 * which case you do not need this file
 */

namespace mc-veo {

    struct DataLoaderConfig
    {
        bool motion_compensation;
        size_t num_events;
        double overlap;
    };

    struct MC-VEOConfiguration
    {
        DataLoaderConfig data_loader;
        ::mc-veo::tracking::Config tracker;
        ::mc-veo::mapping::Config mapping;
        ::mc-veo::bundles::Config bundles;
        ::mc-veo::recorder::Config recorder;
    };

    struct VectorKFs
    {
        ::base::Time time;
        std::vector<base::samples::RigidBodyState> kfs;
    };

    struct EventFrameVector
    {
        ::base::Time time;
        std::vector<double> data;
    };

    struct ModelFrameVector
    {
        ::base::Time time;
        std::vector<double> data;
    };

    typedef mc-veo::tracking::TrackerInfo TrackerInfo;
    typedef mc-veo::bundles::PBAInfo PBAInfo;
}

#endif

