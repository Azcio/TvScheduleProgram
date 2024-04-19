#include "channel.h"

ChannelManager::ChannelManager() : numChannels(10) {
    // Hardcoded list of channels
    std::string initChannels[10] = {"Disney", "Channel x", "Vevo", "SportsX", "high", "laugh central", "high", "Disney", "High", "Vevo"};
    for (int i = 0; i < numChannels; ++i) {
        channels[i] = initChannels[i];
    }
}

void ChannelManager::displayChannels() const {
    for (int i = 0; i < numChannels; ++i) {
        std::cout << channels[i] << std::endl;
    }
}
