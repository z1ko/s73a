
#include <util/console.hpp>

#include <iostream>

namespace artica::util {
    
    void console_logger::info(const std::string& text) {
        std::cout << "[INFO] " << text << std::endl;
    }

    void console_logger::warning(const std::string& text) {
        std::cout << "[WARN] " << text << std::endl;
    }

    void console_logger::error(const std::string& text) {
        std::cout << "[ERRO] " << text << std::endl;
    }

} // namespace artica::util
