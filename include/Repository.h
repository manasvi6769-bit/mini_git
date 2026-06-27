#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>

class Repository
{
public:

    bool exists();

    int getNextCommitNumber();

    std::string getCommitPath(int commitNumber);

    int getLastCommitNumber();

    std::string getMetadataPath(int commitNumber);

    std::string getFilesPath(int commitNumber);

    std::string getIndexPath();

    std::string getRepositoryRoot();
};

#endif
