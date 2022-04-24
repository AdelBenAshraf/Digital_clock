#include <iostream>

using namespace std;

void DigitalClockIntToStr(int seconds, char time[11]);
int DigitalClockStrToInt(const char time[11]);

int main()
{
    char time[11];
    DigitalClockIntToStr(0, time);
    cout<<time<<endl; //This should output “12:00:00am”

    DigitalClockIntToStr(60, time);
    cout<<time<<endl; //This should output “12:01:00am”

    DigitalClockIntToStr(3600, time);
    cout<<time<<endl; //This should output “01:00:00am”

    DigitalClockIntToStr(43199, time);
    cout<<time<<endl; //This should output “11:59:59am”

    DigitalClockIntToStr(43200, time);
    cout<<time<<endl; //This should output “12:00:00pm”

    DigitalClockIntToStr(86399, time);
    cout<<time<<endl; //This should output “11:59:59pm”

    DigitalClockIntToStr(86400, time);
    cout<<time<<endl; //This should output “invalid”


    cout<< DigitalClockStrToInt("12:00:00am")<<endl;
    //This should output 0

    cout<< DigitalClockStrToInt("12:01:00am")<<endl;
    //This should output 60

    cout<< DigitalClockStrToInt("01:00:00am") << endl;
    //This should output 3600

    cout<< DigitalClockStrToInt("11:59:59am ")<<endl;
    //This should output 43199

    cout<< DigitalClockStrToInt("12:00:00pm ")<<endl;
    //This should output 43200

    cout<< DigitalClockStrToInt("11:59:59pm ")<<endl;
    //This should output 86399

    return 0;
}


void DigitalClockIntToStr(int seconds, char time[11])
{
    if (seconds >= 86400)
    {
        string inv = "invalid";
        for (int i = 0; i < 9; i++)
        {
            time[i] = inv[i];
        }
        return;
    }else
    {
        string am_or_pm;
        int temp_seconds;
        int hours;
        int minutes;
        if (seconds <= 43199)
        {
            am_or_pm = "am";
        } else
        {
            am_or_pm = "pm";

        }
        if (seconds >= 0 && seconds <3600)
        {
            temp_seconds = seconds;
            hours = 12;
            minutes = temp_seconds/60;
            temp_seconds = temp_seconds - minutes*60;
        }
        else if (am_or_pm == "am" || (seconds >= 43200 && seconds < 46800))
        {
            temp_seconds = seconds;
            hours = temp_seconds/3600;
            temp_seconds = temp_seconds - hours*3600;
            minutes = temp_seconds/60;
            temp_seconds = temp_seconds - minutes*60;
        } else
        {
            temp_seconds = seconds;
            hours = temp_seconds/3600;
            temp_seconds = temp_seconds - hours*3600;
            minutes = temp_seconds/60;
            temp_seconds = temp_seconds - minutes*60;
            hours = hours - 12;
        }
        //converting hours into characters
        time[0] = char ((hours - hours % 10) / 10 + 48);
        time[1] = char (hours % 10 + 48);
        time[2] = ':';
        //converting minutes into characters
        time[3] = char ((minutes - minutes % 10) / 10 + 48);
        time[4] = char ((minutes % 10 + 48));
        time[5] = ':';
        //converting seconds into characters
        time[6] = char ((temp_seconds - temp_seconds % 10) / 10 + 48);
        time[7] = char ((temp_seconds % 10 + 48));
        time[8] = am_or_pm[0];
        time[9] = am_or_pm[1];
    }
}



int DigitalClockStrToInt(const char time[11])
{
    int seconds;
    seconds = (((int (time[0] - 48)) * 10)* 3600) + ((int (time[1] - 48))* 3600) +
              (((int (time[3] - 48)) * 10)* 60) + ((int (time[4] - 48))* 60) +
              (((int (time[6] - 48)) * 10)) + ((int (time[7] - 48)));
    if (time[8] == 'a' && seconds >= 43200 && seconds <= 46800)
    {
        return seconds - 43200;
    } else if (time[8] == 'a')
    {
        return seconds;
    } else if (time[8] == 'p' && seconds >= 43200 && seconds <= 46800)
    {
        return seconds;
    } else
    {
        return seconds + 43200;
    }
}











