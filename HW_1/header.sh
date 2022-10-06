#!/bin/bash

for file in `find . -name "*.py"`
do
    firstLine=`head -n 1 $file`
    firstThreeChars=${firstLine:0:3}

    if [ "$firstThreeChars" != "\"\"\"" ] && [ "$firstThreeChars" != "'''" ]
    then
        username=`whoami`
        courseSection="CS288 005"
        currentDate=`date +"%m/%d/%Y"`
        fileNameOnly=`basename $file`
        echo -e "\"\"\"\n$username\n$courseSection\n$currentDate\n$fileNameOnly\n\"\"\"\n`cat $file`" > $file
    fi
done