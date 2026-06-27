#include "../include/Repository.h"
#include "../include/FileSystem.h"

#include <filesystem>

namespace fs = std::filesystem;

bool Repository::exists()
{
    FileSystem fileSystem;

    return fileSystem.directoryExists("Project/.mgit");
}

std::string Repository::getCommitPath(int commitNumber)
{
    return "Project/.mgit/commits/" + std::to_string(commitNumber);
}

std::string Repository::getMetadataPath(int commitNumber)
{
    return getCommitPath(commitNumber) + "/metadata.txt";
}
std::string Repository::getFilesPath(int commitNumber)
{
    return getCommitPath(commitNumber) + "/files";
}
std::string Repository::getIndexPath()
{
    return "Project/.mgit/index";
}
std::string Repository::getRepositoryRoot(){
    return "Project";
}


std::string Repository::getHeadPath()
{
    return getRepositoryRoot() + "/.mgit/HEAD";
}
std::string Repository::getCurrentBranch()
{
    FileSystem fileSystem;

    std::string head =
        fileSystem.readFile(getHeadPath());

    std::string prefix = "ref: refs/heads/";

    std::string branch = head.substr(prefix.size());

    if(!branch.empty() && branch.back() == '\n')
        branch.pop_back();

    return branch;
}

std::string Repository::getCurrentBranchPath()
{
    return getRepositoryRoot()
            + "/.mgit/refs/heads/"
            + getCurrentBranch();
}
int Repository::getCurrentCommit()
{
    FileSystem fileSystem;

    std::string value =
        fileSystem.readFile(getCurrentBranchPath());

    if(value.empty())
        return 0;

    return std::stoi(value);
}
void Repository::updateCurrentBranch(int commitNumber)
{
    FileSystem fileSystem;

    fileSystem.writeFile(
        getCurrentBranchPath(),
        std::to_string(commitNumber));
}

