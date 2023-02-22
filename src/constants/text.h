// *************************************
// Pandora Key-Value Store
// Constants
// 'text.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef TEXT_H
#define TEXT_H

#include <string>

namespace pandora {

    class Text {

        // Static class
        private:
            Text() = delete;

        // Text Constants
        public:
            static inline constexpr char port_number_option {'p'};
            static inline constexpr char debug_mode_enabled_option {'d'};
            static inline constexpr char logs_enabled_option {'l'};
            static inline const std::string pandora {"pandora"};
            static inline const std::string sudo {"sudo"};
            static inline const std::string not_found_string {""};
            static inline const std::string off_option {"off"};
            static inline const std::string http_put {"PUT"};
            static inline const std::string http_post {"POST"};
            static inline const std::string http_get {"GET"};
            static inline const std::string http_delete {"DELETE"};
            static inline const std::string element_container_name {"element_container_name"};
            static inline const std::string element_id {"element_id"};
            static inline const std::string element_value {"element_value"};
            static inline const std::string storage {"storage"};
            static inline const std::string data {"data"};
            static inline const std::string shard {"shard"};
            static inline const std::string shards {"shards"};

    };

} // namespace pandora

#endif