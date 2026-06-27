#ifndef BRANCHCOMMAND_H
#define BRANCHCOMMAND_H

#include <string>

class BranchCommand
{
public:

    void execute();

    void execute(const std::string& branchName);

};

#endif
