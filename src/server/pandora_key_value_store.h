// *************************************
// Pandora Key-Value Store
// Server
// 'pandora_key_value_store.hpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef PANDORA_KEY_VALUE_STORE_H
#define PANDORA_KEY_VALUE_STORE_H

#include <unordered_map>
#include <memory>
#include <string>

/*
Notes:
- Mutexes will now be moved to Element Container Manager and Element Manager
- Managers will only be used by the request handler
- Validations will be carried out by managers
- query is an object that has all query data and is able to retrieve it
*/

namespace pandora {

    class ServerConfiguration;

    class PandoraKeyValueStore {

        // Constructor
        public:
            PandoraKeyValueStore(ServerConfiguration*);

        /*
        // Properties
        private:
            
            // Dependencies
            ServerConfiguration* server_configuration;
            ServerUtilities server_utilities;
            RequestHandler query_handler;
            ElementManager element_manager;
            std::shared_ptr<AstraCachingEngine> astra_engine;
            std::unordered_map<std::string, ElementContainer> m_element_containers
             

            */

        // Query ReceiveQuery();


        // Run { while(true) Query query = ReceiveQuery(); query_handler.handle(query); }   

    };

    } // namespace pandora

#endif