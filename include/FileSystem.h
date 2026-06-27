#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class FileSystem
{
public:
    bool createDirectory(const std::string& path);

    bool createFile(const std::string& path,const std::string& content = "");

    bool directoryExists(const std::string& path);

    bool fileExists(const std::string& path);

    bool copyFile(const std::string& source,const std::string& destination);

    std::vector<std::string> listFiles(const std::string& path,bool ignoreGit =false);

    bool isDirectoryEmpty(const std::string& path);

    std::string readFile(const std::string& path);

    bool areFilesEqual(const std::string& file1,const std::string& file2);

    
};

#endif
