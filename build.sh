#!/bin/bash

mkdir -p build
cd build
cmake -S .. -DCMAKE_BUILD_TYPE=Release
make
