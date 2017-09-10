#!/bin/bash

if [ ! -f 'calc' ]; then
    ./build.sh
fi

if [ -f 'calc' ]; then
    if [ -d '/usr/local/bin/' ]; then
        cp 'calc' '/usr/local/bin/'
    fi
fi

if [ -d '/usr/local/share/man/man1/' ]; then
    cp 'calc.1' '/usr/local/share/man/man1/'
    mandb -q
fi
