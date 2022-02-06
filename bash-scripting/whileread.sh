#!/bin/bash

while IFS= read -r user pass uid gid gecos home shell; do
	echo "$user" | sed 's/:/ /g'
done < "$1"
