#!/bin/bash
read -r var
for file in `find . -path "*"`
do
    if [[ -f $file ]]
    then
        output=`cat -n $file | grep "$var"`
        if [[ $output ]]
        then
            echo "In $file:"
            cat -n $file | grep "$var"
        fi
    fi
done