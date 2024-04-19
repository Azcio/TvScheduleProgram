#include <iostream>
#include <fstream> //Allows header files to be used/reads other files
#include <vector>
#include "schedule.cpp"

using namespace std;

string EnterFile;

// User enters their choice in the menu
int choice;
// data
vector<ProgrammeSchedule> schedules;

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

// Verify that the file path is entered
void checkInputFilePath()
{
    cout << "Check the input file path? Default eg: './ProgrammeFiles.csv' (y/n) > ";
    char input;
    cin >> input;
    if (input == 'y' || input == 'Y')
    {
        cin >> EnterFile;
    }
    else
    {
        EnterFile = "./ProgrammeFiles.csv";
    }
    // open the inputted file
    ifstream inputFile(EnterFile);
    if (inputFile.is_open())
    {
        cout << "The file " << EnterFile << " can be read \n";
        // TODO : Initialize channels，Call functions to initialize channels
        schedules = parseData(EnterFile);
    }
    else
    {
        cout << "The File " << EnterFile << " cannot be read \n";
    }
}

int main()
{
    cout << "Welcome to cloud\n";
    // check to see if the file can be opened
    checkInputFilePath();
    do
    {
        // Output menu
        menu();
        cin >> choice;
        cout << "\n";
        // call the function that the user chose
        switch (choice)
        {
        case 1:
            // Calling function to see channel list
            DailySchedule(schedules);
            break;
        case 2:
            // TODO Calling function to switch to channel
            cout << "Calling function to switch to channel" << endl;
            break;
        case 3:
            // TODO Calling function to see favorites
            cout << "Calling function to see favorites" << endl;
            break;
        case 0:
            // Exit the program
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again" << endl;
        }
    } while (choice != 0);
}