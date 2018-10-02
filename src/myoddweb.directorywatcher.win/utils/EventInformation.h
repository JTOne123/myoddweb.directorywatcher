﻿//This file is part of Myoddweb.Directorywatcher.
//
//    Myoddweb.Directorywatcher is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Myoddweb.Directorywatcher is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Myoddweb.Directorywatcher.  If not, see<https://www.gnu.org/licenses/gpl-3.0.en.html>.
#pragma once
#include <string>

enum EventAction
{
  Error,      // there was a general error.
  Added     = 1000,
  Removed,
  Touched,    //  small changed, timestamp, attribute etc...
  RenamedOld,
  RenamedNew
};

struct EventInformation
{
  /**
   * \brief this is the monitor id.
   */
  __int64 id;

  /**
   * \brief the time in Ms when this event was recorded.
   */
  __int64 timeMs;

  /**
   * \brief the action we are recording
   */
  EventAction action;

  /**
   * \brief the filename/folder that was updated. 
   */
  std::wstring name;
};