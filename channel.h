#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>
#include <iostream>

class ChannelManager {
private:
    static const int MAX_CHANNELS = 10;  // Maximum number of channels
    std::string channels[MAX_CHANNELS];  // Static array to store channels
    int numChannels;  // Actual number of channels

public:
    ChannelManager();  // Constructor to initialize the channel list
    void displayChannels() const;
    int getChannelCount() const { return numChannels; }  // Getter for the number of channels
    std::string* getChannels() { return channels; }  // Getter for the channels array
};

#endif // CHANNEL_H
