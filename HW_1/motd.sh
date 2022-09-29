#!/bin/bash

MESSAGE=$1
TIMES=$2
MESSAGELENGTH=${#MESSAGE}

#Check if paramters dont exist or TIMES is less than 1 then exit
if [ -z $MESSAGE ] || [ -z $TIMES ]
then
    exit 1
elif [ $TIMES -lt 1 ]
then
    exit 1
fi

#top bar
echo -n "**"
for ((i=0; i<$MESSAGELENGTH; i++))
do
    echo -n "*"
done
echo "**"

#message
for ((i=0; i<$TIMES; i++))
do
    echo -n "* "
    echo -n $MESSAGE
    echo " *"
done

#bottom bar
echo -n "**"
for ((i=0; i<$MESSAGELENGTH; i++))
do
    echo -n "*"
done
echo "**"