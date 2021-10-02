#!/usr/bin/env bash

echo $@
rm merge.txt
touch merge.txt

IFS=$'\n'

for filename in $@
do
	echo "${filename%.*}:">>merge.txt
	cat "$filename" >> merge.txt
	echo " " >> merge.txt
done

cat merge.txt

