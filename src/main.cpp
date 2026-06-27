#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


#include "../include/commands/AddCommand.h"
#include "../include/commands/CommitCommand.h"
#include "../include/commands/InitCommand.h"
#include "../include/commands/LogCommand.h"
#include "../include/commands/StatusCommand.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: minigit <command>\n";
        return 1;
    }

    std::string command = argv[1];

    if(command == "init")
    {
        if(argc != 2)
        {
            std::cout << "Usage: minigit init\n";
            return 1;
        }

        InitCommand init;
        init.execute();
    }
    else if(command=="add")
    {
        if(argc!=3)
        {
            std::cout<<"Usage: add <file>\n";
            return 1;
        }

        AddCommand add;

        add.execute(argv[2]);
    }
    else if(command =="commit")
    {
        if(argc!=3)
        {
            std::cout<<"Usage: commit <message>\n";
            return 1;
        }
        CommitCommand commit;
        commit.execute(argv[2]);
    }
    else if(command=="log")
    {
        if(argc!=2)
        {
            std::cout<<"Usage: minigit log\n";
            return 1;
        }

        LogCommand log;

        log.execute();
    }
    else if(command == "status")
    {
        if(argc != 2)
        {
            std::cout << "Usage: minigit status\n";
            return 1;
        }

        StatusCommand status;
        status.execute();
    }
    else
    {
        std::cout << "Unknown command: "<< command<< '\n';

        return 1;
    }

    return 0;

}
