#!/bin/bash

echo "Compiling MiniGit..."

clang++ -std=c++17 \
src/main.cpp \src/FileSystem.cpp \src/Repository.cpp \
src/Index.cpp \src/commands/InitCommand.cpp \src/commands/AddCommand.cpp \
src/commands/CommitCommand.cpp \src/commands/LogCommand.cpp \
src/commands/StatusCommand.cpp \src/commands/CheckoutCommand.cpp \
src/commands/BranchCommand.cpp \
-o minigit

if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
fi