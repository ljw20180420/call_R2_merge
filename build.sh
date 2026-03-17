#!/bin/bash

mkdir -p build
cd build
cmake -S ../src -DCMAKE_BUILD_TYPE=Release
make
