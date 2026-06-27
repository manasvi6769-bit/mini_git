#include "../../include/commands/StatusCommand.h"
#include "../../include/Repository.h"
#include "../../include/FileSystem.h"

#include <iostream>
#include <unordered_set>

void StatusCommand::execute()
{
    Repository repository;
    FileSystem fileSystem;

    if(!repository.exists())
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    // Working directory
    std::vector<std::string> workingFiles =
        fileSystem.listFiles(repository.getRepositoryRoot(), true);

    // Staging area
    std::vector<std::string> stagedFiles =
        fileSystem.listFiles(repository.getIndexPath());

    // Last commit
    int lastCommit = repository.getLastCommitNumber();

    std::vector<std::string> committedFiles;

    if(lastCommit != 0)
    {
        committedFiles =
            fileSystem.listFiles(repository.getFilesPath(lastCommit));
    }

    // Convert to hash sets
    std::unordered_set<std::string> workingSet(
        workingFiles.begin(),
        workingFiles.end());

    std::unordered_set<std::string> stagedSet(
        stagedFiles.begin(),
        stagedFiles.end());

    std::unordered_set<std::string> committedSet(
        committedFiles.begin(),
        committedFiles.end());

    bool clean = true;

    /*
    ------------------------------------
            Untracked Files
    ------------------------------------
    */

    for(const auto& file : workingFiles)
    {
        if(stagedSet.find(file) == stagedSet.end())
        {
            std::cout << "Untracked : "<< file<< '\n';

            clean = false;
        }
    }

    /*
    ------------------------------------
            Deleted Files
    ------------------------------------
    */

    for(const auto& file : stagedFiles)
    {
        if(workingSet.find(file) == workingSet.end())
        {
            std::cout << "Deleted   : "<< file<< '\n';

            clean = false;
        }
    }

    /*
    ------------------------------------
            Modified Files
    ------------------------------------
    */

    for(const auto& file : stagedFiles)
    {
        if(workingSet.find(file) == workingSet.end())
            continue;

        std::string workingPath =
            repository.getRepositoryRoot()
            + "/"
            + file;

        std::string stagedPath =
            repository.getIndexPath()
            + "/"
            + file;

        if(!fileSystem.areFilesEqual(
                workingPath,
                stagedPath))
        {
            std::cout << "Modified  : "<< file<< '\n';

            clean = false;
        }
    }

    /*
    ------------------------------------
            Staged Files
    ------------------------------------
    */

    if(lastCommit == 0)
    {
        for(const auto& file : stagedFiles)
        {
            std::cout << "Staged    : "<< file<< '\n';

            clean = false;
        }
    }
    else
    {
        for(const auto& file : stagedFiles)
        {
            std::string stagedPath =
                repository.getIndexPath()
                + "/"
                + file;

            std::string committedPath =
                repository.getFilesPath(lastCommit)
                + "/"
                + file;

            if(committedSet.find(file) == committedSet.end())
            {
                std::cout << "Staged    : "<< file<< '\n';

                clean = false;

                continue;
            }

            if(!fileSystem.areFilesEqual(
                    stagedPath,
                    committedPath))
            {
                std::cout << "Staged    : "<< file<< '\n';

                clean = false;
            }
        }
    }

    if(clean)
    {
        std::cout << "Working tree clean.\n";
    }
}
