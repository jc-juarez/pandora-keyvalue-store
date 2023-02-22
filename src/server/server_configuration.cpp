// *************************************
// Pandora Key-Value Store
// Server
// 'server_configuration.cpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#include "../storage/filesystem_handler.h"
#include "../constants/paths.h"
#include "../constants/text.h"
#include "server_configuration.h"
#include "server_utilities.h"
#include "date_time.h"

#include <vector>

namespace pandora {

        // Constructor
        ServerConfiguration::ServerConfiguration(bool debug_mode_enabled, bool logs_enabled) {

            m_debug_mode_enabled = debug_mode_enabled;
            m_logs_enabled = logs_enabled;
            m_server_session_id = "";
            m_logs_file_path = "";

            // Generate Server Session Identifier
            GenerateServerSessionID();

        }

        void ServerConfiguration::GenerateServerSessionID() {

            // Server session ID (8 first digits correspond to date, 9 latter digits are randomly generated)
            // Date-Time Identifier
            DateTime date_time = GetServerUtilities()->GetDateTime();
            m_server_session_id.append(date_time.year + 
                                     date_time.month +
                                     date_time.day + "-");
            // Random identifier
            m_server_session_id.append(GetServerUtilities()->GetRandomString_Size9());

        }

        // Setter Methods

        void ServerConfiguration::SetDebugModeEnabled(bool debug_mode_enabled) { m_debug_mode_enabled = debug_mode_enabled; }

        void ServerConfiguration::SetLogsEnabled(bool logs_enabled) { m_logs_enabled = logs_enabled; }

        void ServerConfiguration::SetLogsFilePath(std::string logs_file_path) { m_logs_file_path = logs_file_path; }

        // Getter Methods

        ServerUtilities* ServerConfiguration::GetServerUtilities() const { return m_server_utilities; }

        bool ServerConfiguration::GetDebugModeEnabled() const { return m_debug_mode_enabled; }

        bool ServerConfiguration::GetLogsEnabled() const { return m_logs_enabled; }

        std::string ServerConfiguration::GetServerSessionID() const { return m_server_session_id; }

        std::string ServerConfiguration::GetLogsFilePath() const { return m_logs_file_path; }

        // Server Capabilities

        void ServerConfiguration::OverrideOptions(const std::vector<std::string> args) {

            if(args.empty()) return;

            // Options updates based on commands
            int option_command_index {0};
            int option_value_index {2};
            int minimum_command_size {3};

            for(const std::string& command : args) {

                // Care for malformed commands
                if(command.size() < minimum_command_size) continue;

                // Ignore keywords commands
                if(command == Text::pandora || command == Text::sudo) continue;

                char command_option {command[option_command_index]};
                std::string option_value {command.substr(option_value_index)};

                switch (command_option) {
                    case Text::debug_mode_enabled_option :
                        if(option_value == Text::off_option) SetDebugModeEnabled(false);
                        break;
                    case Text::logs_enabled_option :
                        if(option_value == Text::off_option) SetLogsEnabled(false);
                        break;
                }

            }

            // Create Logs file for Server Session if option selected
            if(GetLogsEnabled()) CreateLogsFile();
            
        }

        void ServerConfiguration::CreateLogsFile() {

            std::string logs_file_path {};
            logs_file_path.append(Paths::LogsDirectoryPath + "/pandoralog-" + GetServerSessionID() + ".txt");
            SetLogsFilePath(logs_file_path);
            FilesystemHandler::FileOperation(GetLogsFilePath(), FileOperationOption::Create);
            
        }

} // namespace pandora