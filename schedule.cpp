#include "schedule.h" //import the schedule header, will need for time and parsing data 
#include <iostream>
#include <iomanip> //helps me to format the scehdule into a table/ think of it as a string builder
#include <fstream> //allows the program to enter and read the csv file
#include <sstream> //allows the program to read strings as if they were streams/cin, easier to read file
#include <vector>
#include <ctime> //brings the concept of time in to the programme
#include <algorithm>
#include <string>

using namespace std;

vector<ProgrammeSchedule> parseData(string EnterFile){ //using vectors to store the data from cvs file which is in the data structure in structure header
    vector<ProgrammeSchedule> schedules;
    ifstream csvFile(EnterFile); //open the csv file
    string line;

    while(getline(csvFile, line)) { //while the csvfile is open and readable the programme will read all lines in the file
        istringstream ss(line); // String stream 
        string ProgramID, Name, Duration, Genre, Channel; //Strings of the data that we are looking to store
        //if the String was found get the line and store it
        getline(ss, ProgramID, ',');
        getline(ss, Name, ',');
        getline(ss, Duration, ',');
        getline(ss, Genre, ',');
        getline(ss, Channel, ',');

        if (ProgramID.empty() && Name.empty() && Duration.empty() && Genre.empty() && Channel.empty()) {
            break; //if there is nothing in the string then the read csv while loop will break
        }

        ProgrammeSchedule program; //turning the data in the data structure from the schedule data into an object so that they can be used
        program.Name = Name;
        program.Duration = Duration;
        program.Genre = Genre;
        program.Channel = Channel;
        schedules.push_back(program); //put the object into the vector schedule
    }
    return schedules; //get the vector of the objects/data structure that contains the data that was received when getting the revelant lines 
}

//calculate end time based on start time and duration
tm calculateEndTime(const tm& startTime, const string& duration) {
    tm endTime = startTime;
    int mins = 0; //, hours = 0; //the time (hr and min) is automatically set to 0 and increase by each duration of a programme and commerical breaks
    sscanf(duration.c_str(), "%d mins", &mins); // get the minutes from the duration object of each programme
    endTime.tm_min += mins; // Add the minutes from the duration to the end time
    endTime.tm_hour += endTime.tm_min / 60; //Add the hours from the duration to the end time, including minutes past 60 (NOT WORKING PROPERLY)
    endTime.tm_min %= 60; //reset minutes if they exceed 60 back to 00
    return endTime;
}

// Function to create daily schedule (might create a weekly schedule)
void DailySchedule(string EnterFile) {
    vector<ProgrammeSchedule> schedules = parseData(EnterFile);
     
     // randomize the programme order
    srand(time(0)); // Seed the random number generator
    random_shuffle(schedules.begin(), schedules.end());

    // Start time for the first program
    tm currentTime = {0};
    currentTime.tm_hour = 6; // Start at 6 AM

    // display schedule 
    for (const auto& program : schedules) {
    tm endTime = calculateEndTime(currentTime, program.Duration);

           // Check if end time has passed 22:00, if so, break the loop
        if (endTime.tm_hour >= 22) {
            break;
        }

        // Print program details
        cout << "Channel: " << program.Channel << ", ";
        cout << "Program: " << program.Name << ", ";
        cout << "Start Time: " << setw(2) << setfill('0') << currentTime.tm_hour << ":"
             << setw(2) << setfill('0') << currentTime.tm_min << "\n";

        // Set current time for next program
        currentTime = endTime;

        // Add commercial break
        currentTime.tm_min += 5; // 5 min commercial break
        if (currentTime.tm_min >= 60) {
            currentTime.tm_hour += 1; //add 1 to the hour if the minutes passes 60 (might not be working properly)
            currentTime.tm_min -= 60; //if minutes passes 60 then reset the minutes
        }
    }
}

void DailySchedule2(string EnterFile) {
    vector<ProgrammeSchedule> schedules = parseData(EnterFile);
     
     // randomize the programme order
    srand(time(0)); // Seed the random number generator
    random_shuffle(schedules.begin(), schedules.end());

    // Start time for the first program
    tm currentTime = {0};
    currentTime.tm_hour = 6; // Start at 6 AM

            cout << "=================================================================================================== \n";
    cout << "Schedule 2 \n"; 

    // display schedule 
    for (const auto& program : schedules) {
    tm endTime = calculateEndTime(currentTime, program.Duration);

           // Check if end time has passed 22:00, if so, break the loop
        if (endTime.tm_hour >= 22) {
            break;
        }

        // Print program details

        cout << "Channel: " << program.Channel << ", ";
        cout << "Program: " << program.Name << ", ";
        cout << "Start Time: " << setw(2) << setfill('0') << currentTime.tm_hour << ":"
             << setw(2) << setfill('0') << currentTime.tm_min << "\n";

        // Set current time for next program
        currentTime = endTime;

        // Add commercial break
        currentTime.tm_min += 5; // 5 min commercial break
        if (currentTime.tm_min >= 60) {
            currentTime.tm_hour += 1; //add 1 to the hour if the minutes passes 60 (might not be working properly)
            currentTime.tm_min -= 60; //if minutes passes 60 then reset the minutes
        }
    }
}

void DailySchedule3(string EnterFile) {
    vector<ProgrammeSchedule> schedules = parseData(EnterFile);
     
     // randomize the programme order
    srand(time(0)); // Seed the random number generator
    random_shuffle(schedules.begin(), schedules.end());

    // Start time for the first program
    tm currentTime = {0};
    currentTime.tm_hour = 6; // Start at 6 AM

    cout << "=================================================================================================== \n";
    cout << "Schedule 3 \n"; 

    // display schedule 
    for (const auto& program : schedules) {
    tm endTime = calculateEndTime(currentTime, program.Duration);

           // Check if end time has passed 22:00, if so, break the loop
        if (endTime.tm_hour >= 22) {
            break;
        }

        // Print program details
        cout << "Channel: " << program.Channel << ", ";
        cout << "Program: " << program.Name << ", ";
        cout << "Start Time: " << setw(2) << setfill('0') << currentTime.tm_hour << ":"
             << setw(2) << setfill('0') << currentTime.tm_min << "\n";

        // Set current time for next program
        currentTime = endTime;

        // Add commercial break
        currentTime.tm_min += 5; // 5 min commercial break
        if (currentTime.tm_min >= 60) {
            currentTime.tm_hour += 1; //add 1 to the hour if the minutes passes 60 (might not be working properly)
            currentTime.tm_min -= 60; //if minutes passes 60 then reset the minutes
        }
    }
}

void DailySchedule4(string EnterFile) {
    vector<ProgrammeSchedule> schedules = parseData(EnterFile);
     
     // randomize the programme order
    srand(time(0)); // Seed the random number generator
    random_shuffle(schedules.begin(), schedules.end());

    // Start time for the first program
    tm currentTime = {0};
    currentTime.tm_hour = 6; // Start at 6 AM

    cout << "=================================================================================================== \n";
    cout << "Schedule 4 \n"; 

    // display schedule 
    for (const auto& program : schedules) {
    tm endTime = calculateEndTime(currentTime, program.Duration);

           // Check if end time has passed 22:00, if so, break the loop
        if (endTime.tm_hour >= 22) {
            break;
        }

        // Print program details
        cout << "Channel: " << program.Channel << ", ";
        cout << "Program: " << program.Name << ", ";
        cout << "Start Time: " << setw(2) << setfill('0') << currentTime.tm_hour << ":"
             << setw(2) << setfill('0') << currentTime.tm_min << "\n";

        // Set current time for next program
        currentTime = endTime;

        // Add commercial break
        currentTime.tm_min += 5; // 5 min commercial break
        if (currentTime.tm_min >= 60) {
            currentTime.tm_hour += 1; //add 1 to the hour if the minutes passes 60 (might not be working properly)
            currentTime.tm_min -= 60; //if minutes passes 60 then reset the minutes
        }
    }
}

void DailySchedule5(string EnterFile) {
    vector<ProgrammeSchedule> schedules = parseData(EnterFile);
     
     // randomize the programme order
    srand(time(0)); // Seed the random number generator
    random_shuffle(schedules.begin(), schedules.end());

    // Start time for the first program
    tm currentTime = {0};
    currentTime.tm_hour = 6; // Start at 6 AM

    cout << "=================================================================================================== \n";
    cout << "Schedule 5 \n"; 

    // display schedule 
    for (const auto& program : schedules) {
    tm endTime = calculateEndTime(currentTime, program.Duration);

           // Check if end time has passed 22:00, if so, break the loop
        if (endTime.tm_hour >= 22) {
            break;
        }

        // Print program details
        cout << "Channel: " << program.Channel << ", ";
        cout << "Program: " << program.Name << ", ";
        cout << "Start Time: " << setw(2) << setfill('0') << currentTime.tm_hour << ":"
             << setw(2) << setfill('0') << currentTime.tm_min << "\n";

        // Set current time for next program
        currentTime = endTime;

        // Add commercial break
        currentTime.tm_min += 5; // 5 min commercial break
        if (currentTime.tm_min >= 60) {
            currentTime.tm_hour += 1; //add 1 to the hour if the minutes passes 60 (might not be working properly)
            currentTime.tm_min -= 60; //if minutes passes 60 then reset the minutes
        }
    }
}

int main() {
    // Example usage: Generate schedule and display it
    DailySchedule("ProgrammeFiles.csv");
    DailySchedule2("ProgrammeFiles.csv");
    DailySchedule3("ProgrammeFiles.csv");
    return 0;
}