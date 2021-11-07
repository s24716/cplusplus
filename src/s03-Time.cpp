#include <iostream>
#include <sstream>
#include <string>
#include "../include/s42/Time.h"

auto Time::next_hour() -> void {
    if ( hour < 23 ){
        hour ++;
    } else {
        hour = 0;
    }
}

auto Time::next_minute() -> void {
    if ( minute < 59 ){
        minute++;
    } else {
        minute = 0;
        next_hour();
    }
};
auto Time::next_second() -> void {
    if ( second < 59 ){
        second++;
    } else {
        second =0;
        next_minute();
    }
};

auto Time::to_string() const -> std::string{
    
    std::string hours = std::to_string(hour);
    std::string minutes = std::to_string(minute);
    std::string seconds = std::to_string(second);
    

    if (hour < 10){
        hours = '0' + hours;
    }
    if (minute < 10){
        minutes = '0' + minutes;
    } 
    if (second < 10){
        seconds = '0' + seconds;
    }

    //code above was made to transform 0:0:0 format to 00:00:00 =]

    auto result = std::ostringstream{};
    result << "Aktualny czas : " 
        << hours << " : " 
        << minutes << " : "
        << seconds;
    return result.str();
};

auto main() -> int {
    auto time = Time{};
    time.hour = 23;
    time.minute = 59;
    time.second = 59;

    std::cout<<time.to_string() << "\n";

    time.next_second();

    std::cout<<time.to_string() << "\n";

    time.next_minute();

    std::cout<<time.to_string() << "\n";

}