# calc
`calc` is a small esoteric programming language I designed based on FALSE, dc and Deadfish. It also draws inspiration from Befunge, Brainfuck, C, Emmental and Whitespace. This repository contains an interpreter written in C.

# Commands

|chr |Command           |Inspired by     |Short for
|----|------------------|----------------|---------------------------------
|0-9 |Push integer      |Emmental        |
|A-Z |Push address      |FALSE a-z       |\#0-\#25
|!   |Logical not       |C               |
|"   |Push characters   |Befunge         |
|#   |Push integer 0    |Emmental        |
|$   |Pop               |Befunge         |
|%   |Remainder         |C               |
|&   |Bitwise and       |C               |
|'   |Push characters   |Befunge "       |
|(   |If                |-               |
|)   |If                |-               |
|\*  |Multiply          |C               |
|+   |Add               |C               |
|,   |Dereference       |FALSE ;         |
|-   |Subtract          |C               |
|.   |Assign            |FALSE :         |
|/   |Divide            |C               |
|:   |Duplicate         |Befunge, Emmental|
|;   |Pick              |FALSE pick ø, Whitespace copy \[Tab\]\[Space\]|
|<   |Is less           |C               |
|=   |Is equal          |C ==            |
|>   |Is greater        |C               |
|?   |If expression     |C               |
|@   |Rotate            |FALSE           |
|\[  |While             |Brainfuck       |
|\\  |Swap              |Befunge, FALSE  |
|\]  |While             |Brainfuck       |
|^   |Bitwise xor       |C               |
|\_  |Negate            |FALSE           |
|\`  |Slide             |Whitespace \[Tab\]\[LF\]|
|a   |`putchar('\a')`   |C               |\#7w
|b   |`putchar('\b')`   |C               |\#8w
|c   |Clear stack       |dc              |
|d   |Decrement         |Deadfish        |\#1\\-
|e   |                  |                |
|f   |`putchar('\f')`   |C               |\#12w
|g   |`getchar()`       |C               |
|h   |Halt              |Deadfish        |
|i   |Increment         |Deadfish        |\#1+
|j   |Jump to address   |-               |
|k   |                  |                |
|l   |Push pc           |-               |
|m   |                  |                |
|n   |`putchar('\n')`   |C               |\#10w
|o   |Output            |Deadfish        |
|p   |`putchar()`       |C               |
|q   |Debug (prints all)|dc f            |
|r   |`putchar('\r')`   |C               |\#13w
|s   |Square            |Deadfish        |:\*
|t   |`putchar('\t')`   |C               |\#9w
|u   |                  |                |
|v   |`putchar('\v')`   |C               |\#11w
|w   |                  |                |
|x   |Call              |dc, FALSE !     |
|y   |                  |                |
|z   |Push stack size   |dc              |
|{   |Function          |dc \[, FALSE \[ |
|\|  |Bitwise or        |C               |
|}   |Function          |dc \], FALSE \] |
|~   |Bitwise not       |C               |

# Common patterns

## Pushing an integer

To push 0: `#`
To push 42: `#42`

## Is odd / even

Is odd: `#2\%`  
Is even: `#2\%!`

## If-else

`if (C) ` body1 `; else ` body2 `;`:  
`C,(\` body1 `\)!(\` body2 `\)$`

Or if the stack is irrelevant:  
`C,(` body1 `)!(` body2 `)$`

## Looping

Looping M..1:  
`M,[` body `d]$`

Looping 1..M:  
`M,[:M,i-` body `$d]$`

Looping N..M:  
`N,#1[$` body `i:M,i>]$$`

## Converting a Deadfish program to calc

Simply add `#` to the beginning of the program. Integer overflow has to be implemented manually. For examples see `examples/deadfish_test*.txt`, which are test programs taken from (https://esolangs.org/wiki/Deadfish#Example_program "Esolang").
