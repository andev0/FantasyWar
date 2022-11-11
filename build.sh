#!/bin/bash

# This script executes all the commands I use to build, static analyze and run the
# project.
#
# It must be executed from the root directory of the project.

set -e

# Creating the build directory if it doesn't exist.
mkdir -p build
cd build

if [[ $1 = "debug" ]]; then
    cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DBUILD_MODE=Debug
else
    cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DBUILD_MODE=Release
fi 

make -j7

echo -e "\n\e[93mStarting static check.\e[0m\n"

cppcheck --enable=all --inconclusive -q ../src

echo -e "\n\e[92mBuilt successfully.\e[0m\n"

# Asking while no correct answer is provided.
while :
do
    read -n1 -r -p "Are you want to launch the program? [Y/n] " key

    if [[ $key = "" ]] || [[ $key = "Y" ]] || [[ $key = "y" ]]; then
        ./FantasyWar
        break
    elif [[ $key = "N" ]] || [[ $key = "n" ]]; then
        break
    fi

    echo ""
done

# Leaving the build directory.
cd ..
