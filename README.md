# calc
`calc` is a small esoteric programming language implemented in C based on FALSE and dc. It also draws inspiration from Befunge, Brainfuck, C, Emmental and Whitespace.

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
|'   |Push character "  |-               |\#34
|(   |If                |-               |
|)   |If                |-               |
|\*  |Muliply           |C               |
|+   |Add               |C               |
|,   |Dereference       |FALSE ;         |
|-   |Subtract          |C               |
|.   |Assign            |FALSE :         |
|/   |Divide            |C               |
|:   |Duplicate         |Befunge         |
|;   |Pick              |FALSE pick ø, Whitespace copy \[Tab\]\[Space\]|
|<   |Is less           |C               |
|=   |Is equal          |C ==            |
|>   |Is greater        |C               |
|?   |If expression     |C               |
|@   |Rotate            |FALSE           |
|\[  |While             |Brainfuck       |
|\\  |Swap              |Befunge         |
|\]  |While             |Brainfuck       |
|^   |Bitwise xor       |C               |
|\_  |Negate            |FALSE           |
|\`  |Signum            |-               |
|a   |Absolute          |-               |
|b   |                  |                |
|c   |Clear stack       |dc              |
|d   |Decrement         |-               |\#1\\-
|e   |Even              |-               |\#2\\%!
|f   |Debug (prints stack)|dc              |
|g   |                  |                |
|h   |                  |                |
|i   |Increment         |-               |\#1+
|j   |Jump to address   |- (same as })   |
|k   |                  |                |
|l   |Push pc           |-               |
|m   |                  |                |
|n   |Write \\n         |C               |\#10w
|o   |Odd               |-               |\#2\\%
|p   |Debug (prints top)|dc              |
|q   |Quit              |dc              |
|r   |Read              |-               |
|s   |Slide             |Whitespace \[Tab\]\[LF\]|
|t   |Write \\t         |C               |\#9w
|u   |                  |                |
|v   |                  |                |
|w   |Write             |-               |
|x   |Call              |FALSE ! (dc x)  |
|y   |                  |                |
|z   |Push stack size   |dc              |
|{   |Function          |-               |
|\|  |Bitwise or        |C               |
|}   |Function          |- (same as j)   |
|~   |Bitwise not       |C               |

# Common patterns

## If-else

`if (c) p; else p;`:  
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
