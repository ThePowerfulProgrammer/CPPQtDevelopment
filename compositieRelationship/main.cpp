#include <iostream>
#include <string>
#include <vector>

class Employer; // Forward declaration of Employer class


class Position {
public:
    Position(const std::string& title, Employer* employer) : title(title), employer(employer) {}
    const std::string& getTitle() const { return title; }

private:
    std::string title;
    Employer* employer; // Pointer to the Employer that owns this Position
};

class Employer {
public:
    Employer(const std::string& name) : name(name) {}

    void addPosition(const std::string& title) {
        positions.push_back(Position(title, this)); // Pass the pointer to the Employer
    }

    const std::string& getName() const { return name; }
    const std::vector<Position>& getPositions() const { return positions; }

private:
    std::string name;
    std::vector<Position> positions;
};

int main() {
    Employer myCompany("ABC Corp");

    myCompany.addPosition("Software Engineer");
    myCompany.addPosition("Sales Manager");

    const std::vector<Position>& positions = myCompany.getPositions();

    std::cout << "Employer: " << myCompany.getName() << std::endl;
    std::cout << "Positions: " << std::endl;
    for (size_t i = 0; i < positions.size(); ++i) {
        std::cout << "- " << positions[i].getTitle() << std::endl;
    }

    return 0;
}
