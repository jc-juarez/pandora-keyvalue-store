// *************************************
// Pandora Key-Value Store
// Server
// 'server_configuration.hpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef SERVER_CONFIGURATION_H
#define SERVER_CONFIGURATION_H

#include <string>
#include <vector>

namespace pandora {

    class ServerUtilities;

    class ServerConfiguration {

        // Constructor
        public:
            ServerConfiguration(bool, bool);

        // Properties
        private:
            ServerUtilities* m_server_utilities;
            bool m_debug_mode_enabled;
            bool m_logs_enabled;
            std::string m_server_session_id;
            std::string m_logs_file_path;

        // Setter Methods
        public:
            void SetDebugModeEnabled(bool);
            void SetLogsEnabled(bool);
            void SetLogsFilePath(std::string);

        // Getter Methods
        public:
            ServerUtilities* GetServerUtilities() const;
            bool GetDebugModeEnabled() const;
            bool GetLogsEnabled() const;
            std::string GetServerSessionID() const;
            std::string GetLogsFilePath() const;

        // Private Methods
        private:
            void GenerateServerSessionID();

        // Server Configuration
        public:
            void OverrideOptions(const std::vector<std::string>);
            void CreateLogsFile();
            
    };

} // namespace pandora

#endif