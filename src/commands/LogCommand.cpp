#include "../../include/commands/LogCommand.h"
#include "../../include/Repository.h"
#include "../../include/FileSystem.h"

#include <iostream>

void LogCommand::execute()
{
    Repository repository;
    FileSystem fileSystem;

    // Check if repository exists
    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    // Get latest commit
    int lastCommit = repository.getLastCommitNumber();

    if(lastCommit == 0)
    {
        std::cout << "No commits yet.\n";
        return;
    }

    // Print commits from newest to oldest
    for(int i = lastCommit; i >= 1; i--)
    {
        //std::cout << "Commit " << i << "\n";

        std::string metadata =
            fileSystem.readFile(repository.getMetadataPath(i));

        std::cout << metadata << "\n";
    }
}
