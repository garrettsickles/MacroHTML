#!/bin/bash

echo "================ MacroHTML ==============="
echo "  Generate HTML using the C Preprocessor  "
echo "=========================================="

# Check for all the sources
for source in "$@"; do
	# Check if the file exists
	if [[ ! -f "$source" ]]; then
		echo "Error: Could not find $source"
		exit
	else
		echo "Found supplied source: $source"
	fi
done
		#gcc -E $var | sed '/^#/ d' | sed '/^\s*$/d' | tr -d '\n' > test.html

# If there are no arguements, use templates (*.html.h) in current directory
if [ "$#" -eq 1 ]; then
	echo "No source supplied"
	echo "Looking for sources..."

	# for each file in the directory
	for source in "."/*; do
		# Check for correct extension
		if [[ $source =~ \.html.h ]]; then
			echo "Found source: $source"
			base="${source/.html.h}"
			gcc -E $source | sed '/^#/ d' | sed '/^\s*$/d' | tr -d '\n' > $base.html
		fi
	done


# If the sources were provided
else
	# Check for all the sources
	for source in "$@"; do
		base="${source/.html.h}"
		gcc -E $source | sed '/^#/ d' | sed '/^\s*$/d' | tr -d '\n' > $base.html
	done
fi		
