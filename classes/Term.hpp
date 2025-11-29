#ifndef TERM_H
#define TERM_H

#include <string>
#include <map>

class Term {
private:
    int termCode;
    std::map<std::string, int> modules;
    float termAverage;


public:
    Term(int termCode);

    void addModuleMark(std::string moduleCode, int mark);

    const std::map<std::string, int>& getModules() const;

    int getTermCode() const;

    void setTermAverage(float value);

    float getTermAverage() const;


};

#endif