#pragma once

#include <iostream>

namespace artica::util {
    
    /// @brief Interface for all logger implementations
    class logger_interface {
    public:
        virtual ~logger_interface() = default;

        virtual void info(const std::string& text) = 0;
        virtual void warning(const std::string& text) = 0;
        virtual void error(const std::string& text) = 0;
    };

} // namespace artica::util