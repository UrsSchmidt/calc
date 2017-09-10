#!/bin/bash

if [ -f '/usr/local/bin/calc' ]; then
    rm '/usr/local/bin/calc'
fi

if [ -f '/usr/local/share/man/man1/calc.1' ]; then
    rm '/usr/local/share/man/man1/calc.1'
    mandb -q
fi
