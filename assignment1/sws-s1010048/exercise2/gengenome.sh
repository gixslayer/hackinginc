#!/bin/bash

genome=ACGT

for i in {1..500}; do
    for j in {1..100}; do 
        echo -n ${genome:$RANDOM % 4 | bc:1}
    done
    echo ''
done
