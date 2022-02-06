#!/bin/bash

declare -a passarray
mapfile passarray < "$1"

echo ${passarray[0]}
