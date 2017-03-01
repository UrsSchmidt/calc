# calc
`calc` is a small esoteric programming language I designed based on FALSE and dc. It also draws inspiration from Befunge, Brainfuck, C, Deadfish, Emmental and Whitespace. This repository contains an interpreter written in C.

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
|a   |                  |                |
|b   |                  |                |
|c   |Clear stack       |dc              |
|d   |Decrement         |Deadfish        |\#1\\-
|e   |                  |                |
|f   |Debug (prints all)|dc              |
|g   |`getchar`         |C               |
|h   |                  |                |
|i   |Increment         |Deadfish        |\#1+
|j   |Jump to address   |- (same as })   |
|k   |                  |                |
|l   |Push pc           |-               |
|m   |                  |                |
|n   |Write \\n         |C               |\#10w
|o   |Output            |Deadfish        |
|p   |`putchar`         |C               |
|q   |Quit              |dc              |
|r   |                  |                |
|s   |Square            |Deadfish        |:\*
|t   |Write \\t         |C               |\#9w
|u   |                  |                |
|v   |                  |                |
|w   |                  |                |
|x   |Call              |FALSE ! (dc x)  |
|y   |                  |                |
|z   |Push stack size   |dc              |
|{   |Function          |-               |
|\|  |Bitwise or        |C               |
|}   |Function          |- (same as j)   |
|~   |Bitwise not       |C               |

# Common patterns

## Is odd / even

Is odd: `#2\%`  
Is even: `#2\%!`

## If-else

`if (C) p; else p;`:  
`C,(\p\)!(\p\)$`

Or if the stack is irrelevant:  
`C,( )!( )$`

## Looping

Looping M..1:  
`M,[pd]$`

Looping 1..M:  
`M,[:M,i-p$d]$`

Looping N..M:  
`N,#1[$pi:M,i>]$$`

`p` here refers to the loop's body.
