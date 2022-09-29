#!/bin/bash

#Echo command
# echo "Hello World!"

#Variables
#Usually uppercase
#Letters, numbers, underscores
# NAME="Zaid"
# echo "My name is ${NAME}"

#User input
# read -p "Enter your school" SCHOOL
# echo "you go to $SCHOOL"

#Simple if statment
# read -p "what school you go to" SCHOOL
# if [ $SCHOOL == "NJIT" ]
# then
#     echo "you do indeed go to NJIT"
# elif [ $SCHOOL == "Rutgers" ]
# then
#     echo "you go to rutgers"
# else
#     echo "you dont go to NJIT"
# fi

#COMPARISON
# -eq true if values equal
# -new true if values not equal
# -gt greater than
# -ge greater than or equal to
# -lt less than
# -le less than or equal to

# File conditions
# -f true if there file exists
# -d true if the file is a directory

#Case statement (Switch)
# read -p "Are you 21 or over? Y/N " ANSWER
# case $ANSWER in
#     [yY] | [yY][eE][sS])
#         echo "You can drink beer"
#         ;;
#     [nN] | [nN][oO])
#         echo "Sorry you cant drink"
#         ;;
#     *)
#         echo "Please say yes or no"
# esac

# For loop
# NAMES="Brad Kevin Zaid Feras Rayan"
# for NAME in $NAMES
# do
#     echo "How are you $NAME"
# done

#While loop
# LINE=1
# while read -r CURRENT_LINE
# do
#     echo "$LINE: $CURRENT_LINE"
#     ((LINE++))
# done < "./new.txt"

#Function
function sayHello() {
    echo "Hey"
}
sayHello

#with parameters
function greet(){
    echo "Hey $1"
    echo "You are $2 years old"
}
greet Zaid 20