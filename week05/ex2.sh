#!/bin/sh

while [ -f "file.lock" ]; do
    sleep 1
done

touch file.lock

contents="$(cat file)"
i="$(echo $contents| awk '{print $NF}')"
i=$((i+1))

echo "$contents $i" > file

rm file.lock
