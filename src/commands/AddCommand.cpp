#include "../../include/commands/AddCommand.h"
#include "../../include/Index.h"
#include "../../include/FileSystem.h"

#include <iostream>
#include<string>

void AddCommand::execute(const std::string& relativePath)
{
    FileSystem fs;

    if(!fs.directoryExists("Project/.mgit"))
    {
        std::cout << "Not a MiniGit repository.\n";
        return;
    }

    Index index;

    if(index.addFile(relativePath))
    {
        std::cout<< "Added "<< relativePath<< " to staging area.\n";
    }
    else
    {
        std::cout<< "File not found.\n";
    }
}