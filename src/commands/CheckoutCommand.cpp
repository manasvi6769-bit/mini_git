#include "../../include/commands/CheckoutCommand.h"
#include "../../include/Repository.h"
#include "../../include/FileSystem.h"

#include <iostream>


bool CheckoutCommand::isNumber(const std::string& str)
{
    if(str.empty())
        return false;

    for(char c : str)
    {
        if(!std::isdigit(c))
            return false;
    }

    return true;
}
bool CheckoutCommand::checkoutCommit(int commitNumber)
{
    Repository repository;
    FileSystem fileSystem;

    // Repository exists?
    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return false;
    }

    // Commit exists?
    if(!fileSystem.directoryExists(
            repository.getCommitPath(commitNumber)))
    {
        std::cout << "Commit does not exist.\n";
        return false;
    }

    // Remove current working tree
    if(!fileSystem.clearDirectory(
            repository.getRepositoryRoot(),
            true))
    {
        std::cout << "Failed to clear working directory.\n";
        return false;
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

            return false;
        }
    }
        if(!fileSystem.clearDirectory(
            repository.getIndexPath()))
    {
        std::cout
            << "Failed to clear index.\n";

        return false;
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

            return false;
        }
    }
        std::cout
        << "Checked out commit "
        << commitNumber
        << '\n';

        return true;
}

void CheckoutCommand::checkoutBranch(
        const std::string& branchName)
{
    Repository repository;

    if(!repository.branchExists(branchName))
    {
        std::cout << "Branch does not exist.\n";
        return;
    }

    int commit =
        repository.getBranchCommit(branchName);

    if(checkoutCommit(commit))
    {
        repository.switchBranch(branchName);

        std::cout
            << "Switched to branch "
            << branchName
            << '\n';
    }
}

void CheckoutCommand::execute(
        const std::string& target)
{
    if(isNumber(target))
    {
        checkoutCommit(std::stoi(target));
    }
    else
    {
        checkoutBranch(target);
    }
}

std::vector<std::string> Repository::listBranches()
{
    FileSystem fileSystem;

    return fileSystem.listDirectory(
        getRepositoryRoot()
        + "/.mgit/refs/heads");
}
