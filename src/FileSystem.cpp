#include "../include/FileSystem.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


namespace fs = std::filesystem;

bool FileSystem::createDirectory(const std::string& path)
{
    return fs::create_directories(path);
}

bool FileSystem::createFile(const std::string& path,
                            const std::string& content)
{
    std::ofstream file(path);

    if (!file.is_open())
        return false;

    file << content;

    file.close();

    return true;
}
bool FileSystem::directoryExists(const std::string& path)
{
    return fs::exists(path) &&
           fs::is_directory(path);
}

bool FileSystem::fileExists(const std::string& path)
{
    return fs::exists(path) &&
           fs::is_regular_file(path);
}

bool FileSystem::copyFile(const std::string& source,const std::string& destination)
{
    try
    {
        fs::create_directories(fs::path(destination).parent_path());

        fs::copy_file(source,destination,fs::copy_options::overwrite_existing);

        return true;
    }
    catch(const fs::filesystem_error&)
    {
        return false;
    }
}
std::vector<std::string> FileSystem::listFiles(const std::string& root,bool ignoreGit )
{
    std::vector<std::string> files;

    for(const auto& entry :fs::recursive_directory_iterator(root))
    {
        if(!entry.is_regular_file())
            continue;

        std::string relative =fs::relative(entry.path(), root).string();

        // Skip everything inside .git when requested
        if(ignoreGit)
        {
            if(relative.rfind(".git", 0) == 0)
                continue;
        }

        files.push_back(relative);
    }

    return files;
}
bool FileSystem::isDirectoryEmpty(const std::string& path)
{
    return std::filesystem::is_empty(path);
}
std::string FileSystem::readFile(const std::string& path)
{
    std::ifstream file(path);

    std::string line;
    std::string content;

    while(std::getline(file,line))
    {
        content += line + "\n";
    }

    return content;
}

bool FileSystem::areFilesEqual(const std::string& file1,const std::string& file2)
{
    return readFile(file1) == readFile(file2);
}

bool FileSystem::clearDirectory(const std::string& path,
                                bool ignoreMiniGit)
{
    try
    {
        for(const auto& entry : fs::directory_iterator(path))
        {
            // Ignore .mgit if requested
            if(ignoreMiniGit &&
               entry.path().filename() == ".mgit")
            {
                continue;
            }

            fs::remove_all(entry.path());
        }

        return true;
    }
    catch(...)
    {
        return false;
    }
}
bool FileSystem::writeFile(const std::string& path,const std::string& content)
{
    std::ofstream file(path);

    if(!file)
        return false;

    file << content;

    return true;
}

