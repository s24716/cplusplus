#include <iostream>
#include <string>

struct Time {
    int hour = {0};
    int minute = {0};
    int second = {0};

    auto to_string() const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;
};