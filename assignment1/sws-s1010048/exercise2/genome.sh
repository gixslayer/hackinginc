#!/bin/sh

cat $1 | tr -d '\n' | grep -o $2 | wc -l
