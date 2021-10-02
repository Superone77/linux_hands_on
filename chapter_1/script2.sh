#!/usr/bin/env bash

echo $@

rm /tmp/dir.txt
rm /tmp/files.txt

touch /tmp/dir.txt
touch /tmp/files.txt

for filename in `ls -F $@`
do
	if [[ $filename =~(.*\/$) ]]
	then
		echo $filename>>/tmp/dir.txt
	else
		echo $filename>>/tmp/files.txt
	fi
done

cat /tmp/dir.txt
cat /tmp/files.txt
