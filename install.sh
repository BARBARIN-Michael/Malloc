#!/bin/bash
export LIBRARY_PATH=${PWD}/malloc
export LD_LIBRARY_PATH=${PWD}/malloc

make -C ./malloc/ re
