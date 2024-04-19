#include "channel.h"
#include <iostream>

ChannelManager::ChannelManager() {
    // Hardcoded list of channels
    channels = {"Disney", "Channel x", "Vevo", "SportsX", "high", "laugh central", "high", "Disney", "High", "Vevo"};
}

void ChannelManager::displayChannels() const {
    for (const auto& channel : channels) {
        std::cout << channel << std::endl;
    }
}
