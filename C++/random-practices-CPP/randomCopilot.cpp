#include <unordered_map>
#include <string>
#include <iostream>

int main() {
    // Create an unordered_map of three strings (that represent students)
    // and doubles (that represent their grades)
    std::unordered_map<std::string, double> studentGrades;

    // Add some student-grade pairs to the map
    studentGrades["John"] = 88.5;
    studentGrades["Sarah"] = 92.3;
    studentGrades["Peter"] = 78.9;

    // Retrieve and print each grade
    for (const auto &pair : studentGrades) {
        std::cout << pair.first << "'s grade: " << pair.second << std::endl;
    }

    return 0;
}