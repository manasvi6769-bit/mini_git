#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

#include "../../include/commands/InitCommand.h"
#include "../../include/FileSystem.h"



void InitCommand::execute()
{
    FileSystem fs;
    if(fs.directoryExists("Project/.mgit")){
        std::cout << "Repository already exists.\n";
        return;
    }
    fs.createDirectory("Project/.mgit");

    fs.createDirectory("Project/.mgit/objects");
    fs.createDirectory("Project/.mgit/commits");
    fs.createDirectory("Project/.mgit/refs");
    fs.createDirectory("Project/.mgit/refs/heads");

    fs.createDirectory("Project/.mgit/index");

    fs.createFile("Project/.mgit/config");

    fs.createFile("Project/.mgit/HEAD",
                  "ref: refs/heads/main");

    fs.createFile("Project/.mgit/refs/heads/main",
                  "0");

    std::cout << "Initialized empty MiniGit repository.\n";
}
