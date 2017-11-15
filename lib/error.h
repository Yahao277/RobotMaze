#pragma once

#include <stdexcept>
#include <sstream>
#include <string>

class custom_error : public std::runtime_error {
public:
    custom_error(const std::string& message, const std::string& target, int line)
        : std::runtime_error("L:"+static_cast<std::ostringstream*>( &(std::ostringstream() << line) )->str() + " "+target+" "+message){};
    custom_error(const std::string& message, int line)
        : std::runtime_error("L:"+static_cast<std::ostringstream*>( &(std::ostringstream() << line) )->str() +" "+message){};
    custom_error(const std::string& message, const std::string& target)
        : std::runtime_error(target+" "+message){};
    custom_error(const std::string& message)
        : std::runtime_error(message){};

};
