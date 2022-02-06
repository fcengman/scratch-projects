#!/bin/bash

if [[ -p /dev/stdin ]]; then
	while IFS= read -r LINE; do
		echo "Line: $LINE"
	done
fi
