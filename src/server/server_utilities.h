// *************************************
// Pandora Key-Value Store
// Server
// 'server_utilities.hpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

/*
ADD LATER

void ConsoleLog(const std::string);
            void AppendLog(const std::string, std::stringstream&);
            void DebugLog(const std::string, std::stringstream&);
            void LogToFile(pandora::utilities::TransactionData&);
            void LogToFileThread(const std::string);
            void LogQueryStartedFinished(int, pandora::utilities::TransactionData&, const std::string = "");
            void LogInfo(pandora::utilities::TransactionData&);
            void LogError(int, pandora::utilities::TransactionData&); ////// THIS WILL BE RENAMED TO THROW_ERROR    
*/

#ifndef SERVER_UTILITIES_H
#define SERVER_UTILITIES_H

#include "date_time.h"

#include <random>
#include <string>
#include <chrono>

namespace pandora {

    class ServerUtilities {

        // Constructor
        public:
            ServerUtilities();

        // Properties
        private:
            std::random_device m_random;
            std::mt19937 m_seed;
            std::uniform_int_distribution<int> m_range_9;

        // Server Utilities
        public:
            void CreateBaseDirectories();
            DateTime GetDateTime();
            std::string GetRandomString_Size9();
            std::string GenerateQueryID();
            std::string GetDateTimeString();
            std::string GetEllapsedMillisecondsString(std::chrono::time_point<std::chrono::high_resolution_clock>&,
                                                    std::chrono::time_point<std::chrono::high_resolution_clock>&);

    };

}

#endif
