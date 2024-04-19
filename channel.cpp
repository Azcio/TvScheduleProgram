#include "channel.h"
#include "schedule.h"
#include <iostream>
#include <string>
using namespace std;


ChannelManager::ChannelManager() : numChannels(6) {
    // Hardcoded list of channels
    std::string initChannels[6] = {"Disney", "Channel x", "Vevo", "SportsX", "high", "laugh central"};
    for (int i = 0; i < numChannels; ++i) {
        channels[i] = initChannels[i];
    }
}

void ChannelManager::displayChannels() const {
    for (int i = 0; i < numChannels; ++i) {
        std::cout << channels[i] << std::endl;
    }
}

// void ChannelManager::selectChannel()  {
//     string userInput;
//     cout << "Please enter one of the channel names from the list:" << endl;
//     getline(cin, userInput);

//     for (int i = 0; i < numChannels; ++i) {
//         if (channels[i] == userInput) {
//             cout << "You have selected: " << channels[i] << endl;
//             // Handle different channel inputs
//             if (userInput == "Disney") {
//                 DailySchedule(EnterFile);
//             } else if (userInput == "Channel x") {
//                 DailySchedule2(EnterFile);
//             } else if (userInput == "Vevo") {
//                 DailySchedule3(EnterFile);
//             }else if (userInput == "SportsX") {
//                 DailySchedule2(EnterFile);
//             } else if (userInput == "high") {
//                 DailySchedule3(EnterFile);
//             } else if (userInput == "laugh central") {
//                 DailySchedule3(EnterFile);
//             }
           
//             return;  // Exit the function after selection
//         }
//     }

//     cout << "Channel not found. Please try again." << endl;
// }