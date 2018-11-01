#!/bin/sh

# cant have any spaceing between variable name and value
NAME="Lucas Ryan"

# when want to use variable prefix it with $
echo NAME: $NAME

# can unset/delete a variable
MY_FLOAT=7.3
echo MY_FLOAT: $MY_FLOAT
unset MY_FLOAT
echo MY_FLOAT: $MY_FLOAT

# can make a variable constant by using readonly keyword
INT_CONSTANT=17
echo INT_CONSTANT: $INT_CONSTANT

readonly INT_CONSTANT
# INT_CONSTANT=2 # throws an error

# special variables
echo "File Name: $0"
echo "Number of arguements given: $#"
