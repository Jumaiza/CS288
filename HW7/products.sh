#!/bin/bash

if [ "$1" == "vividtest.txt" ]
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

        python3 parser.py vivid

        # rm -rf *.html
        # rm -rf *.xhtml
    fi
fi
