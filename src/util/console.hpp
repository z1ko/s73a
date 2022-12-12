#pragma once

#include <util/log.hpp>

namespace artica::util {
    
    /// @brief Implements a console logger
    class console_logger : public logger_interface {
    public:
        virtual ~console_logger() { }

        void info(const std::string& text) override;
        void warning(const std::string& text) override;
        void error(const std::string& text) override;
    };

} // namespace artica::util
