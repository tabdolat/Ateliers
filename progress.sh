#!/bin/bash

for file in atman farouk mouhcine yassine
do
    echo "$file"
    cat $file/progress
    echo -e "\n"
    echo "------------------------------------------------"
done
