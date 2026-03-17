#!/bin/bash

# change to the directory of the script
cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# change to project directory
cd ../..

./build/fqtools list-suffix --path tests/ListSuffix --suffix ".fq"
./build/fqtools list-suffix --path tests/ListSuffix --suffix ".sam"
