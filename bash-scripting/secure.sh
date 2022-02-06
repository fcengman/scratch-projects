#! /bin/bash


whois $1 > whois-$1.txt
dig $1 > dig-$1.txt

while whois-$1.txt= read -r LINE; do
	echo "$LINE"
done < whois-$1.txt