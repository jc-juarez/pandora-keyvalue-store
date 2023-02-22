// *************************************
// Pandora Key-Value Store
// Storage
// 'filesystem_handler.cpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#include "filesystem_handler.h"

#include <filesystem>
#include <fstream>
#include <vector>
#include <ios>

namespace pandora {

    namespace storage {

        void FilesystemHandler::CreateDirectory(const std::string& path) {

            try {

                std::filesystem::create_directories(path);

            } catch(...) {

                std::string error {};
                error.append("Pandora could not create the " + path + " directory.");
                throw std::runtime_error(error);

            }

        }

        void FilesystemHandler::FileOperation(const std::string& file_path, FileOperationOption file_operation_option, const std::string content) {

            std::ofstream outfile;

            if(file_operation_option == FileOperationOption::Create) {
                outfile.open(file_path);
                return;
            }

            outfile.open(file_path, std::ios_base::app);

            outfile << content;

        }

    }

} // namespace pandora