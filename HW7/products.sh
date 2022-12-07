#!/bin/bash

if [ "$1" == "vivid.txt" ] && [ "$2" == "lmp.txt" ]
then
    if [ -f $1 ]
    then
        lines=$(cat $1)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py vivid $xhtmlFileName
            rm -rf *.xhtml
        done
    fi

    if [ -f $2 ]
    then
        lines=$(cat $2)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py lmp $xhtmlFileName
            rm -rf *.xhtml
        done
    fi
fi

if [ "$2" == "vivid.txt" ] && [ "$1" == "lmp.txt"]
then
    if [ -f $1 ]
    then
        lines=$(cat $1)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py lmp $xhtmlFileName
            rm -rf *.xhtml
        done
    fi

    if [ -f $2 ]
    then
        lines=$(cat $2)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py vivid $xhtmlFileName
            rm -rf *.xhtml
        done
    fi
fi
