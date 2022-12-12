
#include <service.hpp>
#include <audio/alsa.hpp>
#include <util/console.hpp>

int main() {

    using namespace artica;

    // Set up logger service
    service_logger::provide(new util::console_logger{});
    auto logger = service_logger::get();
    
    logger->info("Welcome to the S73-Artica real time audio synthetizer");

    // Set up backend audio engine service
    auto engine = audio::alsa_engine{44100, 0, 0};
    for(int i = 0; i < 100; i++)
        engine.submit({});
    
    /**
     * Example of audio waves combinations
     * auto A = audio::wave{440.0};
     * auto C = audio::wave{480.0};
     * auto K = 6 * A + C;
     */

    return 0;
}
