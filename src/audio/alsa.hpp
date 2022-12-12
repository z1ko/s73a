#pragma once

#include <alsa/asoundlib.h>
#include <audio/engine.hpp>

namespace artica::audio {
    
    /// @brief Audio engine for the ALSA driver
    class alsa_engine : public engine_interface {

        snd_pcm_t* m_device_handle;

        const std::size_t m_sampling_rate;
        const std::size_t m_buffer_time;
        const std::size_t m_period_time;

    public:
        /// @brief Constructs a new engine using the ALSA driver 
        alsa_engine(std::size_t sampling_rate, std::size_t buffer_time, std::size_t period_time);
        virtual ~alsa_engine();

        void submit(const std::vector<sample>& samples) override; 
    };

} // namespace artica::audio
