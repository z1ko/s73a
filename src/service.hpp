#pragma once

#include <memory>
#include <type_traits>

#include <util/log.hpp>
#include <audio/engine.hpp>

namespace artica {
    
    /// @brief Class used to allow access to common components 
    template<typename T>
    class service {

        /// Last provided instance of the service
        inline static T* m_instance = nullptr; 

    public:
        /// @brief Provide a runtime instance of the service 
        static void provide(T* instance) {
            m_instance = instance;
        }

        /// @brief Get the runtime instance of the service
        static T* get() {
            return m_instance;
        }
    };

    /// @brief Service for logger implementation
    using service_logger = service<util::logger_interface>;
    /// @brief Service for the real time audio engine implementation
    using service_audio_engine = service<audio::engine_interface>;

} // namespace artica