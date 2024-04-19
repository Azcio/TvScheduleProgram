#include <iostream>
#include <fstream>
#include "channel.h"

using namespace std;

// User enters their choice in the menu
int choice;

void menu()
{
    cout << "|-------------------------|\n";
    cout << "| ****     Menu      **** |\n";
    cout << "|-------------------------|\n";
    // options of actions
    cout << "| 1. See channel list     |\n";
    cout << "| 2. Switch to channel    |\n";
    cout << "| 3. See favorites        |\n";
    cout << "| 0. Exit the program     |\n";
    cout << "|-------------------------|\n";
    cout << "Enter your choice > ";
}

int main() {
    cout << "Welcome to Cloud TV\n";

    ChannelManager channelManager;

    do {
        menu();  // Display the menu
        cin >> choice;
        cin.ignore();  // Clear out any extra input

        switch (choice) {
        case 1:
            channelManager.displayChannels();
            break;
        case 2:
            cout << "Functionality to switch to a channel will be implemented here.\n";
            break;
        case 3:
            cout << "Functionality to see favorites will be implemented here.\n";
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
