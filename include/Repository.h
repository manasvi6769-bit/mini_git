#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>

class Repository
{
public:

    bool exists();


    std::string getCommitPath(int commitNumber);


    std::string getMetadataPath(int commitNumber);

    std::string getFilesPath(int commitNumber);

    std::string getIndexPath();

    std::string getRepositoryRoot();

    std::string getHeadPath();

    std::string getCurrentBranch();

    std::string getCurrentBranchPath();

    int getCurrentCommit();

    void updateCurrentBranch(int commitNumber);

    bool branchExists(const std::string& branchName);

    std::string getBranchPath(const std::string& branchName);

    bool createBranch(const std::string& branchName);

    void switchBranch(const std::string& branchName);

    std::vector<std::string> listBranches();

    int getBranchCommit(const std::string& branchName);
};

#endif
