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
};

#endif
