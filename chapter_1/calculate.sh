#!/usr/bin/env bash

sum="0"
num="1"

while(($num<= 100))
do
	sum=$((${sum}+${num}))
	num=$((${num}+1))
done

echo $sum
 
