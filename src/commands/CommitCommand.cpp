#include "../../include/commands/CommitCommand.h"
#include "../../include/Repository.h"
#include "../../include/FileSystem.h"

#include <iostream>
#include <vector>

void CommitCommand::execute(const std::string& message)
{
    Repository repository;
    FileSystem fileSystem;

    // Check repository
    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    // Check staging area
    if(fileSystem.isDirectoryEmpty("Project/.mgit/index"))
    {
        std::cout << "Nothing to commit.\n";
        return;
    }

    // Next commit number
    int parentCommit =repository.getCurrentCommit();
    int commitNumber =parentCommit + 1;
    // Commit path
    std::string commitPath =repository.getCommitPath(commitNumber);

    // Create directories
    fileSystem.createDirectory(commitPath);
    fileSystem.createDirectory(commitPath + "/files");

    // Get staged files
    std::vector<std::string> files =fileSystem.listFiles("Project/.mgit/index");

    // Copy each staged file
    for(const auto& file : files)
    {
        if(!fileSystem.copyFile("Project/.mgit/index/" + file,commitPath + "/files/" + file))
        {
            std::cout << "Failed to copy " << file << '\n';
            return;
        }
    }

    // Save commit message
    std::string metadata =
    "Commit: " + std::to_string(commitNumber) + "\n" +
    "Parent: " + std::to_string(parentCommit) + "\n" +
    "Message: " + message;
    
    fileSystem.createFile(commitPath + "/metadata.txt",metadata);
    repository.updateCurrentBranch(commitNumber);

    std::cout<< "Committed as Commit "<< commitNumber<< "\n";
}
