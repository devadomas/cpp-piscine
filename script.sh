#!/bin/bash

# Parameters
if [ "$#" -ne 2 ]; then
    echo "usage: ./compare.sh ../vogsphere-cpp/d01 days/day-01"
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

		# Check if file exists
		if [ ! -f $vogsphereFile ]; then
			printf "\e[91m|-- ${vogsphereFile##*/} : file not found\e[0m\n"

		# Make a diff on files
		elif diff $file $vogsphereFile >/dev/null; then
			printf "\e[92m|-- ${vogsphereFile##*/} : ok\e[0m\n"
		else
			printf "\e[91m|-- ${vogsphereFile##*/} : difference found\e[0m\n"			
		fi

	done

	echo ""

done

# Check git status
CURPWD=$(printenv PWD)

printf "\e[1m\e[94mGIT status\e[0m\e[21m\n\n"
cd $1
if git status | grep -q "Changes not staged for commit:"; then
	printf "\e[91m|-- $1 : Changes not staged for commit\e[0m\n"
elif git status | grep -q "Changes to be committed:"; then
	printf "\e[91m|-- $1 : Changes to be committed\e[0m\n"
elif git status | grep -q "to publish your local commits"; then
	printf "\e[91m|-- $1 : Changes to be published\e[0m\n"
else
	printf "\e[92m|-- $1 : Branch is up-to-date\e[0m\n"
fi
cd $CURPWD
cd $2
if git status | grep -q "Changes not staged for commit:"; then
	printf "\e[91m|-- $2 : Changes not staged for commit\e[0m\n"
elif git status | grep -q "Changes to be committed:"; then
	printf "\e[91m|-- $2 : Changes to be committed\e[0m\n"
elif git status | grep -q "to publish your local commits"; then
	printf "\e[91m|-- $2 : Changes to be published\e[0m\n"
else
	printf "\e[92m|-- $2 : Branch is up-to-date\e[0m\n"
fi
cd $CURPWD

