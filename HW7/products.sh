#!/bin/bash

if [ "$1" == "vivid.txt" ] && [ "$2" == "lmp.txt" ]
then
    lines=$(cat $1)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -rf *.html
        xhtmlFileName=`find . -name "*.xhtml"`
        python3 parser.py vivid $xhtmlFileName insert
        rm -rf *.xhtml
    done
    lines=$(cat $2)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -rf *.html
        xhtmlFileName=`find . -name "*.xhtml"`
        python3 parser.py lmp $xhtmlFileName insert
        rm -rf *.xhtml
    done

    SLEEP_TIME=15s
    while true; do

        sleep $SLEEP_TIME

        lines=$(cat $1)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py vivid $xhtmlFileName update
            rm -rf *.xhtml
        done
        lines=$(cat $2)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py lmp $xhtmlFileName update
            rm -rf *.xhtml
        done
    done

fi

if [ "$2" == "vivid.txt" ] && [ "$1" == "lmp.txt"]
then
    lines=$(cat $1)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -rf *.html
        xhtmlFileName=`find . -name "*.xhtml"`
        python3 parser.py lmp $xhtmlFileName insert
        rm -rf *.xhtml
    done
    lines=$(cat $2)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -rf *.html
        xhtmlFileName=`find . -name "*.xhtml"`
        python3 parser.py vivid $xhtmlFileName insert
        rm -rf *.xhtml
    done

    SLEEP_TIME=15s
    while true; do

        sleep $SLEEP_TIME

        lines=$(cat $1)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py lmp $xhtmlFileName update
            rm -rf *.xhtml
        done
        lines=$(cat $2)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -rf *.html
            xhtmlFileName=`find . -name "*.xhtml"`
            python3 parser.py vivid $xhtmlFileName update
            rm -rf *.xhtml
        done
    done
fi

