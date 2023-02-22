// *************************************
// Pandora Key-Value Store
// Constants
// 'paths.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef PATHS_H
#define PATHS_H

#include <string>

namespace pandora {

    class Paths {

        // Static class
        private:
            Paths() = delete;

        // Paths Constants
        public:
            static inline const std::string PipePath {"/tmp/pandora_pipe"};
            static inline const std::string LogsDirectoryPath {"/var/log/pandora"};
            static inline const std::string PandoraDirectoryPath {"/var/lib/pandora"};
            static inline const std::string ElementContainersDirectoryPath {"/var/lib/pandora/element-containers"};

    };

} // namespace pandora

#endif