// *************************************
// Pandora Key-Value Store
// Server
// 'date_time.hpp'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>

struct DateTime {

    std::string year {};
    std::string month {};
    std::string day {};
    std::string hours {};
    std::string minutes {};
    std::string seconds {};

};

#endif