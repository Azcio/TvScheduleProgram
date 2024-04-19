#include <iostream>
#include <string>
#include <fstream> //Allows header files to be used/reads other files
#include <sstream>
#include "channel.h"
#include "schedule.h"
using namespace std;


int getValidChoice() {
    string input;
    int choice;

    while (true) {
        getline(cin, input);  // Get the entire line as a string
        stringstream stream(input);  // Use stringstream for conversion
        if (stream >> choice && !(stream >> input)) {  // Check for a valid integer and no additional characters
            return choice;
        }
        cout << "Invalid input. Please enter a number from the menu options.\n";
    }
}

void menu() {
    cout << "|-------------------------|\n";
    cout << "| ****     Menu      **** |\n";
    cout << "|-------------------------|\n";
    // Options of actions
    cout << "| 1. See channel list     |\n";
    cout << "| 2. Switch to channel    |\n";
    cout << "| 3. See favorites        |\n";
    cout << "| 0. Exit the program     |\n";
    cout << "|-------------------------|\n";
    cout << "Enter your choice > ";
}

int main() {
    cout << "Welcome to Cloud TV \n";

    cout << "Please enter the program file: \n";
    string EnterFile;
   getline(cin, EnterFile);

         //open the inputted file
    ifstream inputFile(EnterFile);

//check to see if the file can be opened
    if (inputFile.is_open())
{
    cout << "The file " << EnterFile << " can be read \n";
} else {
    cout << " The File " << EnterFile << " cannot be read \n";
}

    ChannelManager channelManager;
    scheduleManager callSchedules;

string userInput;
    int choice;

    do {
        menu();  // Display the menu
        choice = getValidChoice();  // Get a valid choice from the user

        switch (choice) {
        case 1:
            channelManager.displayChannels();
            break;
        case 2:
            cout << "Switch to channel functionality is not implemented yet.\n";
            channelManager.displayChannels();

            cout << "Enter the channel that you want to select \n";
    
getline(cin, userInput);

if(userInput == "Disney"){
    callSchedules.DailySchedule(EnterFile);
    break;
}else if(userInput == "Channel x"){
    callSchedules.DailySchedule2(EnterFile);
    break;
}else if(userInput == "Vevo"){
    callSchedules.DailySchedule3(EnterFile);
    break;
}else if(userInput == "SportsX"){
    callSchedules.DailySchedule4(EnterFile);
    break;
}else if(userInput == "high"){
    callSchedules.DailySchedule5(EnterFile);
    break;
}else if(userInput == "laugh central"){
    callSchedules.DailySchedule6(EnterFile);
    break;
}
            break;
        case 3:
            cout << "See favorites functionality is not implemented yet.\n";
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Please enter a valid choice.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
