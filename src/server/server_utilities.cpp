// *************************************
// Pandora Key-Value Store
// Server
// 'server_utilities.cpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#include "../storage/filesystem_handler.h"
#include "../constants/numerics.h"
#include "../constants/paths.h"
#include "server_utilities.h"

#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <chrono>
#include <ctime>

namespace pandora {

        ServerUtilities::ServerUtilities() {

            // Initialize Seed and Uniform Distribution for random numbers generation
            m_seed = std::mt19937(m_random());
            m_range_9 = std::uniform_int_distribution<int>(Numerics::RandomSize9LowerLimit, Numerics::RandomSize9UpperLimit);

        }
        
        DateTime ServerUtilities::GetDateTime() {

            int two_digits {2};
            int initial_position {0};

            time_t now = time(0);
            tm *ltm = localtime(&now);
            
            DateTime dt;
            dt.year = std::to_string(1900 + ltm->tm_year);
            dt.month = std::to_string(1 + ltm->tm_mon);
            dt.day = std::to_string(ltm->tm_mday);
            dt.hours = std::to_string(ltm->tm_hour);
            dt.minutes = std::to_string(ltm->tm_min);
            dt.seconds = std::to_string(ltm->tm_sec);

            // Care for two digits for all data
            if(dt.month.size() < two_digits) dt.month.insert(initial_position, "0");
            if(dt.day.size() < two_digits) dt.day.insert(initial_position, "0");
            if(dt.hours.size() < two_digits) dt.hours.insert(initial_position, "0");
            if(dt.minutes.size() < two_digits) dt.minutes.insert(initial_position, "0");
            if(dt.seconds.size() < two_digits) dt.seconds.insert(initial_position, "0");

            return dt;

        }

        void ServerUtilities::CreateBaseDirectories() {

            // Create Pandora Storage Server directory
            FilesystemHandler::CreateDirectory(Paths::PandoraDirectoryPath);
            // Create logs directory
            FilesystemHandler::CreateDirectory(Paths::LogsDirectoryPath);
            // Create element containers storage directory
            FilesystemHandler::CreateDirectory(Paths::ElementContainersDirectoryPath);

        }

        std::string ServerUtilities::GetRandomString_Size9() { return std::to_string(m_range_9(m_seed)); }

        std::string ServerUtilities::GetDateTimeString() {

            // DateTime as string
            std::string date_time_string {};
            DateTime date_time = GetDateTime();
            date_time_string.append(date_time.month + "/" +
                                    date_time.day + "/" + 
                                    date_time.year + " " +
                                    date_time.hours + ":" +
                                    date_time.minutes + ":" +
                                    date_time.seconds);
            return date_time_string;

        }

        std::string ServerUtilities::GetEllapsedMillisecondsString(std::chrono::time_point<std::chrono::high_resolution_clock>& start,
                                                  std::chrono::time_point<std::chrono::high_resolution_clock>& stop) {

            // Convert to nanoseconds duration
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            
            double ellapsed_milliseconds = static_cast<double>(duration.count()) / Numerics::MillisecondsDivision;

            std::stringstream ellapsed_milliseconds_sstream {};
            ellapsed_milliseconds_sstream << ellapsed_milliseconds;

            return ellapsed_milliseconds_sstream.str();

        }

    

} // namespace pandora