#pragma once

#include <memory>
#include <type_traits>

#include <util/log.hpp>
#include <util/console.hpp>

#include <audio/engine.hpp>

namespace artica {
    
    /// @brief Class used to allow access to common components 
    template<typename T>
    class service {
    public:
        /// @brief Get the runtime instance
        static T* get() {
            static T instance;
            return &instance;
        }
    };

    using service_logger = artica::service<artica::util::console_logger>;

} // namespace artica