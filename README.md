# calc
`calc` is a small esoteric programming language implemented in C based on FALSE and dc. It also draws inspiration from Befunge, Brainfuck, C, Emmental and Whitespace.

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
