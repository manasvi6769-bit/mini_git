#include "../include/Repository.h"
#include "../include/FileSystem.h"

#include <filesystem>

namespace fs = std::filesystem;

bool Repository::exists()
{
    FileSystem fileSystem;

    return fileSystem.directoryExists("Project/.mgit");
}
int Repository::getNextCommitNumber()
{
    int count = 0;

    for(const auto& entry :fs::directory_iterator("Project/.mgit/commits"))
    {
        if(entry.is_directory())
            count++;
    }

    return count + 1;
}
std::string Repository::getCommitPath(int commitNumber)
{
    return "Project/.mgit/commits/" + std::to_string(commitNumber);
}
int Repository::getLastCommitNumber()
{
    int lastCommit = 0;

    for(const auto& entry :
        std::filesystem::directory_iterator("Project/.mgit/commits"))
    {
        if(entry.is_directory())
        {
            int number =
                std::stoi(entry.path().filename().string());

            if(number > lastCommit)
                lastCommit = number;
        }
    }

    return lastCommit;
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

