#include <iostream>
#include <string>


struct Student {
    std::string name;
    std::string last_name;
    std::string index;
    unsigned short acctual_semestr { 1 };
    float grades_average { 0.0 };


    auto to_string() const -> std::string;
};
