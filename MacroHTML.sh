#!/bin/bash

# Check for all the sources
for source in "$@"; do
	# Check if the file exists
	if [[ ! -f "$source" ]]; then
		echo "Error: Could not find $source"
		exit
	fi
done
		#gcc -E $var | sed '/^#/ d' | sed '/^\s*$/d' | tr -d '\n' > test.html

# If there are no arguements, use templates (*.html.h) in current directory
if [ "$#" -eq 1 ]; then
	echo "Looking for sources..."

	# for each file in the directory
	for source in "."/*; do
		# Check for correct extension
		if [[ $source =~ \.html.h ]]; then
			echo "Found source $source"
			base="${source/.html.h}"
			gcc -E $source | sed '/^#/ d' | sed '/^\s*$/d' | tr -d '\n' > $base.html
		fi
	done


# If the sources were provided
else
	# Check for all the sources
	for source in "$@"; do
		echo "Found source $source"
		base="${source/.html.h}"
		gcc -E $source | sed '/^#/ d' | sed '/^\s*$/d' | tr -d '\n' > $base.html
	done
fi		
