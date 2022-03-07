#!/bin/bash

for file in atman farouk mouhcine yassine
do
    echo "$file"
    cat $file/progress
    echo -e "\n"
    echo "------------------------------------------------"
done


git ls-files | while read f; do git blame -w -M -C -C --line-porcelain "$f" | grep -I '^author '; done | sort -fr | uniq -ic | sort -n
