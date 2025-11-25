#include "Term.hpp"
#include <string>
#include <map>

Term::Term(int termCode): termCode(termCode) {
}

void Term::addModuleMark(std::string moduleCode, int mark) {
    modules[moduleCode] = mark;    
}

const std::map<std::string, int>& Term::getModules() const{
    return modules;
}

int Term::getTermCode() const {
    return termCode;
}