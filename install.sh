#!/bin/bash
export LIBRARY_PATH=${HOME}/42/malloc/malloc
export LD_LIBRARY_PATH=${HOME}/42/malloc/malloc

make -C ./malloc/ re
