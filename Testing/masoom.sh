#!/bin/bash

while true
do

echo 
echo "Input a number to choose from the Menu!:"
echo "1: List all files in the present working diredtory(sorted by time)"
echo "2: Display today's date and time"
echo "3: Display a calander for the current month"
echo "4: Display a list who is logged in"
echo "5: Create a backup for a file"
echo "6: Display disk usage for home directory"
echo "7: Diplay file system usage"
echo "8: Exit"

read CHOICE

    if [[ "${CHOICE}" =~ ^[0-8]$ ]]
    then
        case $CHOICE in
            1)
                ls -t;;
            2)
                date;;
            3)
                cal;;
            4)
                who;;
            5)
                echo "Enter the file you want to be backed up"
                read FILE
                if [ -f $FILE ]
                then
                    cp $FILE $FILE.bkp 
                else
                    echo "File does not exist"
                fi
                ;;

            6)
                df -h;;
            7)
                df -h;;
            8)
                exit 1
                ;;  
        esac
    else
        echo "Choice does not exist. Try again"
    fi
done

exit 1

