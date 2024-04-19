#include "channel.h"
#include <iostream>

int main() {
    std::cout << "Welcome to Cloud TV\n";

    ChannelManager channelManager;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. See channel list\n";
        std::cout << "2. Exit the program\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            channelManager.displayChannels();
            break;
        case 2:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}
