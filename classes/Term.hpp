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
    // Constructor
    Term(int termCode);

    // Getter function to get the modules
    const std::map<std::string, int>& getModules() const;

    // Getter function to get the term code
    int getTermCode() const;

    // Getter function to get the term average
    float getTermAverage() const;

    // Setter function to add the module marks
    void addModuleMark(std::string moduleCode, int mark);

    // Setter function to set the term average
    void setTermAverage(float value);


};

#endif