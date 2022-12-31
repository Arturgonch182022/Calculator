//
// Created by artur on 28.12.2022.
//

#include "Date_Calculation.h"
typedef struct Date{
    int day;
    int month;
    int year;

    Date(int d, int m, int y):day(d), month(m), year(y)
    {
    }

    bool operator== (const Date& rhs)
    {
        return day==rhs.day && month==rhs.month && year==rhs.year;
    }
}Date;

std::vector<int> splitBy(std::string input, char delimiter)
{
    std::vector<int> output;
    int startDayIndex = 0;
    int endIndex = 0;
    int length = input.length();
    while(input.find(delimiter, startDayIndex)!=std::string::npos)
    {
        endIndex = input.find(delimiter, startDayIndex);
        output.push_back(stoi(input.substr(startDayIndex,endIndex)));
        startDayIndex = endIndex+1;

    }

    output.push_back(stoi(input.substr(startDayIndex,length)));
    return output;
}

int NextMonth(int currentMonth)
{
    if(currentMonth == 12) return 1;
    return currentMonth+1;
}

int NextYear(int month, int currentYear)
{

    return month==1?currentYear+1:currentYear;
}

bool isLeapYear(int year)
{
    if(year%4!=0) return false;
    else if(year%100!=0) return true;
    else if(year%400!=0) return false;
    else return true;
}

int DaysInMonth(int month, int year)
{
    std::vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear(year)) days[1] = 29;
    return days[month-1];

}

bool errorCheck(Date start, Date end)
{

    if(start.year>end.year) return true;
    else if(start.month>end.month && start.year==end.year) return true;
    else if(start.day>end.day && start.month==end.month && start.year==end.year) return true;
    return false;
}
int start(std::string firstDate, std::string endDate)
{
    std::vector<int> initDate = splitBy(firstDate, '/');
    std::vector<int> finDate = splitBy(endDate, '/');
    Date startDay(initDate[0], initDate[1], initDate[2]);
    Date endDay(finDate[0], finDate[1], finDate[2]);
    if(errorCheck(startDay,endDay)) return -1;
    int count = 0;
    int days = DaysInMonth(startDay.month, startDay.year);

    while((startDay==endDay)!=1)
    {
        while(startDay.day<days)
        {
            startDay.day = startDay.day + 1;
            count++;
            if((startDay==endDay)==1)
            {
                return count;
            }
        }
        count++;
        startDay.day = 1;
        startDay.month = NextMonth(startDay.month);
        startDay.year = NextYear(startDay.month,startDay.year);
        days = DaysInMonth(startDay.month, startDay.year);
    }
    return count;

}

void Date_Calculation(){
    cout << "Enter date in format DD/MM/YYYY\n";
    std::string startDayDate;
    std::string endDate;
    cout << "Enter first date\n";
    cin >> startDayDate;
    cout << "Enter second date\n";
    cin >> endDate;
    int result = start(startDayDate, endDate);
    cout << result << "\n";

}