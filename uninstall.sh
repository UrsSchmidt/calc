#!/bin/bash

if [ -f '/usr/local/bin/calc' ]; then
    sudo rm '/usr/local/bin/calc'
fi

if [ -f '/usr/local/share/man/man1/calc.1' ]; then
    sudo rm '/usr/local/share/man/man1/calc.1'
    sudo mandb -q
fi
