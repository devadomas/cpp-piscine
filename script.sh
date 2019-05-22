#!/bin/bash

# Parameters
if [ "$#" -ne 2 ]; then
    echo "Please enter 2 parameters."
    exit
fi

# Clear screen
printf '\033[2J'
printf '\033[2H'

# Loop through directories given in first parameter
for directory in $1/*/ ; do

    printf "\e[1m\e[94m$directory\e[0m\e[21m\n\n"

    # Loop through directories given in second parameter
    for file in $directory*; do

        vogsphereFile="${file/$1/$2}"
        if [ ! -f $vogsphereFile ]; then
            printf "\e[91m|-- ${vogsphereFile##*/} : file not found\e[0m\n"
        elif diff $file $vogsphereFile >/dev/null; then
            printf "\e[92m|-- ${vogsphereFile##*/} : ok\e[0m\n"
        else
            printf "\e[91m|-- ${vogsphereFile##*/} : difference found\e[0m\n"
        fi

    done

    echo ""

done
