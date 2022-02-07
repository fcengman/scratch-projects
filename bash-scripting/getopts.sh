#!/bin/bash

while getopts ":a:" opt; do
	case $opt in
		a) echo "You passed the -a option with the $OPTARG argument" >&2 ;;
		:) echo "Option -$opt requires an argument" >&2; exit 1 ;;
		\?) echo "Invalid option: -$opt" >&2 ;;
	esac
done
shift $((OPTIND-1))
echo '$1 is' "$1"
