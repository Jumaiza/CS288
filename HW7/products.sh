#!/bin/bash

if [ "$1" == "vivid.txt" ] && [ "$2" == "lmp.txt" ]
then
    lines=$(cat $1)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -maxdepth 1 -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -f *.html
        xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
        python3 parser.py vivid $xhtmlFileName insert
        rm -f *.xhtml
    done
    lines=$(cat $2)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -maxdepth 1 -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -f *.html
        xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
        python3 parser.py lmp $xhtmlFileName insert
        rm -f *.xhtml
    done

    SLEEP_TIME=15s
    while true; do

        echo "Sleeping for 6 hours...."
        sleep $SLEEP_TIME

        lines=$(cat $1)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -maxdepth 1 -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -f *.html
            xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
            python3 parser.py vivid $xhtmlFileName update
            rm -f *.xhtml
        done
        lines=$(cat $2)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -maxdepth 1 -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -f *.html
            xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
            python3 parser.py lmp $xhtmlFileName update
            rm -f *.xhtml
        done
    done

fi

if [ "$2" == "vivid.txt" ] && [ "$1" == "lmp.txt" ]
then
    lines=$(cat $1)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -maxdepth 1 -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -f *.html
        xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
        python3 parser.py lmp $xhtmlFileName insert
        rm -f *.xhtml
    done
    lines=$(cat $2)
    for website in $lines
    do
        wget $website
        htmlFileName=`find . -maxdepth 1 -name "*.html"`
        java -jar tagsoup-1.2.1.jar --files $htmlFileName
        rm -f *.html
        xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
        python3 parser.py vivid $xhtmlFileName insert
        rm -f *.xhtml
    done

    SLEEP_TIME=15s
    while true; do

        echo "Sleeping for 6 hours...."
        sleep $SLEEP_TIME

        lines=$(cat $1)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -maxdepth 1 -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -f *.html
            xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
            python3 parser.py lmp $xhtmlFileName update
            rm -f *.xhtml
        done
        lines=$(cat $2)
        for website in $lines
        do
            wget $website
            htmlFileName=`find . -maxdepth 1 -name "*.html"`
            java -jar tagsoup-1.2.1.jar --files $htmlFileName
            rm -f *.html
            xhtmlFileName=`find . -maxdepth 1 -name "*.xhtml"`
            python3 parser.py vivid $xhtmlFileName update
            rm -f *.xhtml
        done
    done
fi

