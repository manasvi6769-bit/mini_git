MiniGit/
│
|--Project/
|.        |---hello.txt
|
├── include/
│   ├── commands/
│   ├── repository/
│   ├── objects/
│   ├── storage/
│   └── utils/
│
├── src/
│   ├── main.cpp
│   ├── commands/
│   ├── repository/
│   ├── objects/
│   ├── storage/
│   └── utils/
│
├── tests/
├── docs/
└── README.md

--------------------------------------------------
clang++ -std=c++17 \src/main.cpp \src/FileSystem.cpp \src/commands/InitCommand.cpp \-o minigit

find . -print

clang++ -std=c++17 src/main.cpp src/FileSystem.cpp src/commands/InitCommand.cpp src/commands/AddCommand.cpp src/commands/CommitCommand.cpp src/commands/StatusCommand.cpp -o minigit



clang++ -std=c++17 \
src/main.cpp \
src/FileSystem.cpp \
src/Repository.cpp \
src/Index.cpp \
src/commands/InitCommand.cpp \
src/commands/AddCommand.cpp \
src/commands/CommitCommand.cpp \
src/commands/LogCommand.cpp \
-o minigit



clang++ -std=c++17 \
src/main.cpp \
src/FileSystem.cpp \
src/Repository.cpp \
src/Index.cpp \
src/commands/InitCommand.cpp \
src/commands/AddCommand.cpp \
src/commands/CommitCommand.cpp \
src/commands/LogCommand.cpp \
src/commands/StatusCommand.cpp \
-o minigit