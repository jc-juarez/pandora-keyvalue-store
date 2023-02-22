// *************************************
// Pandora Key-Value Store
// Storage
// 'filesystem_handler.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef FILESYSTEM_HANDLER_H
#define FILESYSTEM_HANDLER_H

#include "../constants/options.h"

#include <string>

namespace pandora {

    class FilesystemHandler {

        // Static class
        private:
            FilesystemHandler() = delete;

        // Filesystem operations
        public:
            static void CreateDirectory(const std::string&);
            static void FileOperation(const std::string&, FileOperationOption, const std::string = "");
        
    };

} // namespace pandora

#endif