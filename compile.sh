#!/bin/bash
src=$1

if [ $# == 1 ]
then
	gcc $src -o ${src:0:$((${#src}-2))}.o -liupimglib -liup
else
	gcc $src -g -o ${src:0:$((${#src}-2))}debug.o -liupimglib -liup
fi

