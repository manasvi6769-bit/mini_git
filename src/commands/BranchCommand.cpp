#include "../../include/commands/BranchCommand.h"
#include "../../include/Repository.h"

#include <iostream>
#include <vector>

void BranchCommand::execute()
{
    Repository repository;

    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    std::vector<std::string> branches =
        repository.listBranches();

    std::string currentBranch =
        repository.getCurrentBranch();

    for(const auto& branch : branches)
    {
        if(branch == currentBranch)
            std::cout << "* ";
        else
            std::cout << "  ";

        std::cout << branch << '\n';
    }
}

void BranchCommand::execute(
        const std::string& branchName)
{
    Repository repository;

    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    if(repository.branchExists(branchName))
    {
        std::cout
            << "Branch already exists.\n";

        return;
    }

    if(repository.createBranch(branchName))
    {
        std::cout
            << "Created branch "
            << branchName
            << '\n';
    }
    else
    {
        std::cout
            << "Failed to create branch.\n";
    }
}
