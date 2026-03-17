#!/bin/bash

# change to the directory of the script
cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# change to project directory
cd ../..

./build/call_r2_merge -R1 R1.fq -R2 R2.fq -source source.fq -delimiter " " -sta 0 -end 150
