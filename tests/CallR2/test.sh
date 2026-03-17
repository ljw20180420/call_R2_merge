#!/bin/bash

# change to the directory of the script
cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# change to project directory
cd ../..

./build/fqtools call-R2 -R1 tests/CallR2/R1.fq -R2 tests/CallR2/R2.fq -delimiter " " -sta 0 -end 150
