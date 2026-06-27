#include "../../include/commands/CheckoutCommand.h"
#include "../../include/Repository.h"
#include "../../include/FileSystem.h"

#include <iostream>

void CheckoutCommand::execute(int commitNumber)
{
    Repository repository;
    FileSystem fileSystem;

    // Repository exists?
    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    // Commit exists?
    if(!fileSystem.directoryExists(
            repository.getCommitPath(commitNumber)))
    {
        std::cout << "Commit does not exist.\n";
        return;
    }

    // Remove current working tree
    if(!fileSystem.clearDirectory(
            repository.getRepositoryRoot(),
            true))
    {
        std::cout << "Failed to clear working directory.\n";
        return;
    }
    std::vector<std::string> files =
        fileSystem.listFiles(
            repository.getFilesPath(commitNumber));

    for(const auto& file : files)
    {
        if(!fileSystem.copyFile(
                repository.getFilesPath(commitNumber)
                + "/"
                + file,

                repository.getRepositoryRoot()
                + "/"
                + file))
        {
            std::cout
                << "Failed to restore "
                << file
                << '\n';

            return;
        }
    }
        if(!fileSystem.clearDirectory(
            repository.getIndexPath()))
    {
        std::cout
            << "Failed to clear index.\n";

        return;
    }
        for(const auto& file : files)
    {
        if(!fileSystem.copyFile(
                repository.getFilesPath(commitNumber)
                + "/"
                + file,

                repository.getIndexPath()
                + "/"
                + file))
        {
            std::cout
                << "Failed to update index.\n";

            return;
        }
    }
        std::cout
        << "Checked out commit "
        << commitNumber
        << '\n';
}