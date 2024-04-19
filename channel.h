#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>
#include <vector>

class ChannelManager {
private:
    std::vector<std::string> channels;  // Using vector to store channels

public:
    ChannelManager();  // Constructor to initialize the channel list
    void displayChannels() const;
};

#endif // CHANNEL_H
