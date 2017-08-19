#!/bin/bash

if [ ! -f 'calc' ]; then
    ./build.sh
fi

if [ -f 'calc' ]; then
    if [ -d '/usr/local/bin/' ]; then
        sudo cp 'calc' '/usr/local/bin/'
    fi
fi

if [ -d '/usr/local/share/man/man1/' ]; then
    sudo cp 'calc.1' '/usr/local/share/man/man1/'
    sudo mandb -q
fi
