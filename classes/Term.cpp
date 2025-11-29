#include "Term.hpp"
#include <string>
#include <map>

// Constructor
Term::Term(int termCode): termCode(termCode) {
}

// Getter function to get the modules
const std::map<std::string, int>& Term::getModules() const{
    return modules;
}

// Getter function to get the term code
int Term::getTermCode() const {
    return termCode;
}

// Getter function to get the term average
float Term::getTermAverage() const{
    return termAverage;
}

// Setter function to add the module marks
void Term::addModuleMark(std::string moduleCode, int mark) {
    modules[moduleCode] = mark;
}

// Setter function to set the term average
void Term::setTermAverage(float value)
{
    this->termAverage=value;
}