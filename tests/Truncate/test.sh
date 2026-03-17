#!/bin/bash

# change to the directory of the script
cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# change to project directory
cd ../..

./build/fqtools truncate < tests/Truncate/test.fq
./build/fqtools truncate -sta 10 -end 140 < tests/Truncate/test.fq
