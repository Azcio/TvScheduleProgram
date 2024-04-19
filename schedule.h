#include <iostream>
#include <vector>
#include <string>
#include <ctime> //add the concept of time in the program
using namespace std;

#ifndef SCHEDULE_H
#define SCHEDULE_H

//const string EnterFile = "Programme-files.csv";

//Data structure will contain the data about a programme that is in the csv file that is relevant to schedule
struct ProgrammeSchedule {
    string ProgramID;
    string Name;
    string Duration;
    string Genre;
    string Channel;
};

struct CommercialBreak {
    tm startTime; // Start time of the commercial break
    tm endTime;   // End time of the commercial break
};

class scheduleManager {
    public:
void DailySchedule(const string& EnterFile);
void DailySchedule2(const string& EnterFile);
void DailySchedule3(const string& EnterFile);
void DailySchedule4(const string& EnterFile);
void DailySchedule5(const string& EnterFile);
void DailySchedule6(const string& EnterFile);
};

#endif 
