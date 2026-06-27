#include "../include/Index.h"
#include "../include/FileSystem.h"

#include <filesystem>
#include<iostream>
#include<string>


namespace fs = std::filesystem;

bool Index::addFile(const std::string& relativePath)
{
    FileSystem fileSystem;

    std::string source =
        "Project/" + relativePath;

    if(!fileSystem.fileExists(source))
        return false;

    std::string destination =
        "Project/.mgit/index/" + relativePath;

    return fileSystem.copyFile(source, destination);
}

