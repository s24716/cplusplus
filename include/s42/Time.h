#include <iostream>
#include <string>

struct Time {
    int hour = {0};
    int minute = {0};
    int second = {0};

	enum Time_of_day {
		rano,
		dzien,
		wieczor,
		noc
	};
	Time(int, int, int);
    auto to_string() const -> std::string;
    auto to_string(Time_of_day) const -> std::string;
    auto time_of_day() const -> Time_of_day;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;	
	auto operator + ( Time const &) const -> Time;
	auto operator - ( Time const &) const -> Time;
	auto operator < ( Time const &) const -> bool;
	auto operator > ( Time const &) const -> bool;
	auto operator == ( Time const &) const -> bool;
	auto operator != ( Time const &) const -> bool;



};
