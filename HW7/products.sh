#!/bin/bash

if [ "$1" == "vividracingCopy.txt" ]
then
    if [ -f $1 ]
    then
        lines=$(cat $1)
        for website in $lines
        do
            wget $website
        done
        for file in `find . -name "*.html"`
        do
            java -jar tagsoup-1.2.1.jar --files $file
        done
    fi
fi
