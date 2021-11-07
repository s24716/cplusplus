#include <iostream>
#include <string>
#include <sstream>
#include "../include/s42/Student.h"

auto Student::to_string() const -> std::string {
    auto result = std::ostringstream{};
        result << "Imię i nazwisko: "<< name
            << " " << last_name << "\n"
            << "Index ucznia: " << index << "\n"
            << "Aktualny semestr " << acctual_semestr << "\n"
            << "Srednia ocen: " << grades_average;

        return result.str();

}
auto main() -> int {
    auto student = Student{};
    student.name = "Jakub";
    student.last_name = "Jan";
    student.index = "s00001";
    student.acctual_semestr = 1;
    student.grades_average = 4.5;
    std::cout << student.to_string() << "\n";

    return 0;
}
