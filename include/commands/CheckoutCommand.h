#ifndef CHECKOUTCOMMAND_H
#define CHECKOUTCOMMAND_H

class CheckoutCommand
{
public:

    void execute(const std::string& target);

private:

    bool checkoutCommit(int commitNumber);

    void checkoutBranch(const std::string& branchName);

    bool isNumber(const std::string& str);
};

#endif
