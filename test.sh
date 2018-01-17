#!/bin/bash

echo $1

if [ -z $1 ]
then
    make
elif [ $1 -gt 3 ]
then
    make
else
    make re
fi

clang main.c libftprintf.a

if [ -z $1 ]
then
    ./a.out
elif [ $1 -ge 3 ]
then
    ./a.out | cat -e
else
    ./a.out
fi