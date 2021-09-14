#!/bin/bash

gcc ex2.c

./a.out &
sleep 2
pstree
wait $(jobs -p)