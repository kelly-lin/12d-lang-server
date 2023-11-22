#!/bin/bash
# Extract function calls and descriptions from the 4dm programming manual.

if [ -z "$1" ]; then
    echo "please provide path to 4dm documentation file in positional argument 1"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "file $1 does not exist"
    exit 1
fi

awk '/^Name$/ {p=1}; 
     /^ID/ {p=0; print $0; print "\n"}; 
     {if (p==1) print $0}' "$1"
