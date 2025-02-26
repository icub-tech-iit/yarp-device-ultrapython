/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#pragma once

#include <yarp/os/LogStream.h>

#include <string>

#include <yarp/os/LogComponent.h>

YARP_DECLARE_LOG_COMPONENT(ULTRAPYTHONSTAT)

// For FPS statistics purpouse
class Statistics
{
   public:
	explicit Statistics(const std::string &info, double exposure);
	void add();
	double getFps() const;
	void setExposure(double value);

   private:
	std::string info_;
	double exposure_{0};
	double timeStart_{0};
	double latestFps_{0};
	unsigned int frameCounter_{0};
	static constexpr double statPeriod_{5.0};
};
