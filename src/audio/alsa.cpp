
#include <cmath>
#include <audio/alsa.hpp>
#include <service.hpp>

namespace artica::audio {
    
    alsa_engine::alsa_engine(std::size_t sampling_rate, std::size_t buffer_time, std::size_t period_time)
        : m_sampling_rate{sampling_rate}, m_buffer_time{buffer_time}, m_period_time{period_time} {

        auto logger = service_logger::get();
        logger->info("Initializing audio engine for ALSA driver");
        logger->info(" |   device : default");
        logger->info(" |   format : SND_PCM_FORMAT_U8");
        logger->info(" |   access : SND_PCM_ACCESS_RW_INTERLEAVED");
        logger->info(" | channels : 1");
        logger->info(" |     rate : 44100");
        logger->info(" | resample : 1");
        logger->info(" |  latency : 50000");

        // Open handle to the playing default device
        snd_pcm_open(&m_device_handle, "default", SND_PCM_STREAM_PLAYBACK, 0);

        // Set the stream parameters
        snd_pcm_set_params(m_device_handle, 
            SND_PCM_FORMAT_U8, SND_PCM_ACCESS_RW_INTERLEAVED, 
            1, sampling_rate, 1, 50000);

        /*
        // Create async event for sample generation
        snd_async_handler_t* handler;
        if (snd_async_add_pcm_handler(&handler, m_device_handle, async_callback, nullptr) < 0) {
            // ERROR: Unable to register async callback handler
        }

        // Starts handler
        if (snd_pcm_state(m_device_handle) == SND_PCM_STATE_PREPARED) {
            if (snd_pcm_start(m_device_handle) < 0){
                // ERROR: Unable to start async callbacks
            }
        }
        */
    }


    void alsa_engine::submit(const std::vector<sample>& samples) {
        
        static unsigned char random[1024];
        static size_t current_sample = 0;

        // Fill the current 
        for (int i = 0; i < 1024; i++) {
            random[i] = 2 * sin(2.0 * M_PI * (current_sample + i) * 440.0 / 441000);
        }
        current_sample += 1024;

        snd_pcm_sframes_t frames;
        frames = snd_pcm_writei(m_device_handle, random, sizeof(random));
        if (frames < 0) {
            frames = snd_pcm_recover(m_device_handle, frames, 0);
        }
    }

    alsa_engine::~alsa_engine() {
        //auto logger = service_logger::get().lock();

        // Pass remaining samples to the device
        if (snd_pcm_drain(m_device_handle) < 0) {
            //logger->warning("Unable to drain ASLA device!");
        }
        snd_pcm_close(m_device_handle);
    }

} // namespace artica::audio
