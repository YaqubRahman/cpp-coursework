#ifndef TERM_H
#define TERM_H

#include <string>
#include <map>

class Term {
private:
    std::map<std::string, int> modules;

public:
    Term(int termCode);

    void addModuleMark(std::string moduleCode, float mark);

    const std::map<std::string, int>& getModules() const {
        return modules;
    }

};

#endif