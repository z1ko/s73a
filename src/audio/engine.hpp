#pragma once

#include <cstdint>
#include <vector>

namespace artica::audio {
    
    /// @brief Type used to describe an audio sample
    using sample = unsigned int;

    /// @brief Interface for all audio engine implementations
    class engine_interface {
    public:
        virtual ~engine_interface() = default;
        virtual void submit(const std::vector<sample>& samples) = 0;
    };

} // namespace artica::audio