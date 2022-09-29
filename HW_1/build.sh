#!/bin/bash

if [ "$SUFFIXES" == "" ]
then
    SUFFIXES=".c"
fi
if [ "$CC" == "" ]
then
    CC="gcc"
fi
if [ "$CFLAGS" == "" ]
then
    CFLAGS="-Wall -Werror"
fi


for suffix in $SUFFIXES
do
    for file in *$suffix
    do
        if [ -f $file ]
        then
            executable=`basename $file $suffix`
            $CC $CFLAGS -o $executable $file

            if ! [[ $? -eq 0 ]]
            then
                exit 1
            fi

            if [ "$VERBOSE" != "" ] 
            then
                echo $CC $CFLAGS -o $executable $file
            fi       
        fi
    done
done