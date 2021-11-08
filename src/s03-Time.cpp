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
}
auto Time::next_second() -> void {
    if ( second < 59 ){
        second++;
    } else {
        second =0;
        next_minute();
    }
}
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
}



auto Time::to_string(Time::Time_of_day pora) const -> std::string{
	
	switch (pora) {
		case Time_of_day::rano:
			return "Rano";
		case Time_of_day::dzien:
			return "Dzien";
		case Time_of_day::wieczor:
			return "Wieczor";
		case Time_of_day::noc:
			return "Noc";
		default: 
			throw "Cos poszlo nie tak";
	}
}
auto Time::time_of_day() const -> Time_of_day { 
	if ((hour > 4) && (hour <= 8)){
		return Time::Time_of_day::rano;
	} else if ((hour > 8) && (hour <= 17)){
		return Time::Time_of_day::dzien;
	} else if ((hour > 17) && (hour <= 22)){
		return Time::Time_of_day::wieczor;
	} else {	
		return Time::Time_of_day::noc;
	}
}

 auto Time::operator+ (Time const& o) const -> Time {
		int h = hour;
		int m = minute;
		int s = second;

		s += o.second;
		if(s>59){ s-= 60; m++;};
		m += o.minute;
		if(m>59){ m-= 60; h++;};
		h += o.hour;
		if(h>23){h-=24;};
		return Time(h, m, s);
	
	
 }


 auto Time::operator< (Time const& o) const -> bool {
        if(hour < o.hour)
            return true;
        if(hour != o.hour)
            return false;
        if(minute < o.minute)
            return true;
        if(minute != o.minute)
            return false;
        if(second < o.second)
            return true;
        if(second != o.minute)
            return false;
        return false;
    }

 auto Time::operator> (Time const& o) const -> bool {
        if(hour > o.hour)
            return true;
        if(hour != o.hour)
            return false;
        if(minute > o.minute)
            return true;
        if(minute != o.minute)
            return false;
        if(second > o.second)
            return true;
        if(second != o.minute)
            return false;
        return false;
    }

 auto Time::operator== (Time const& o) const -> bool {
        return (hour==o.hour && minute==o.minute&&second==o.second);
    }

 auto Time::operator!= (Time const& o) const -> bool {
        return !(hour==o.hour && minute==o.minute&&second==o.second);
    }


auto main() -> int {
    auto time = Time(23, 59, 59);


    std::cout<<time.to_string() << "\n";

    time.next_second();

    std::cout<<time.to_string() << "\n";

    time.next_minute();

    std::cout<<time.to_string() << "\n";

	std::cout<<time.to_string(time.time_of_day()) << "\n";

}
