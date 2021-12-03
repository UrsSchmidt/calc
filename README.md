# calc
`calc` is a small [esoteric programming language](https://en.wikipedia.org/wiki/Esoteric_programming_language "esoteric programming language") based on [FALSE](https://esolangs.org/wiki/FALSE "FALSE") and [dc](https://esolangs.org/wiki/Dc "dc"). It also draws inspiration from [Deadfish](https://esolangs.org/wiki/Deadfish "Deadfish"), C, [Befunge](https://esolangs.org/wiki/Befunge "Befunge"), [Whitespace](https://esolangs.org/wiki/Whitespace "Whitespace"), [Emmental](https://esolangs.org/wiki/Emmental "Emmental") and [Brainfuck](https://esolangs.org/wiki/Brainfuck "Brainfuck").

# Basics
Every printable ASCII character has exactly one semantic meaning. Some letters do not have any meaning assigned yet. Most characters are executed from left to right (see [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation "RPN")). Thus if you wanted to calculate 6 / 3, it would look like this: `#3#6/W`. Note that the operands are in reverse order, which is important when subtracting or dividing integers. This example will push the number 3, then the number 6, then divide them by popping both arguments from the stack and pushing the result, i.e. 2, then printing the number to the console and popping the result from the stack, leaving it empty.

# Commands

|Character          |Command               |Inspired by/Implementation notes                                 |Short for   |
|-------------------|----------------------|-----------------------------------------------------------------|------------|
|`!`                |Logical not           |C                                                                |            |
|`"`                |Print string          |FALSE                                                            |            |
|`#`                |Push 0                |Emmental                                                         |            |
|`$`                |Pop (aka Discard/Drop)|Befunge, FALSE `%`, Whitespace \[Space\]\[LF\]\[LF\]             |            |
|`%`                |Remainder             |C                                                                |            |
|`&`                |Bitwise and           |C                                                                |            |
|`'`                |Push characters       |Befunge `"`                                                      |            |
|`(`                |If (begin)            |-                                                                |            |
|`)`                |If (end)              |-                                                                |            |
|`*`                |Multiply              |C                                                                |            |
|`+`                |Add                   |C                                                                |            |
|`,`                |Dereference           |FALSE `;`                                                        |            |
|`-`                |Subtract              |C                                                                |            |
|`.`                |Assign                |FALSE `:`                                                        |            |
|`/`                |Divide                |C                                                                |            |
|`0` - `9`          |(see below)           |Emmental                                                         |            |
|`:`                |Duplicate             |Befunge, Emmental, FALSE `$`, Whitespace \[Space\]\[LF\]\[Space\]|            |
|`;`                |Rotate                |FALSE `@`                                                        |            |
|`<`                |Is less               |C                                                                |            |
|`=`                |Is equal              |C `==`                                                           |            |
|`>`                |Is greater            |C                                                                |            |
|`?`                |If expression         |C                                                                |`` !O#2` `` |
|`@`                |Call                  |dc `x`, FALSE `!`                                                |            |
|`A`                |                      |                                                                 |            |
|`B`                |Beep                  |*not yet implemented*                                            |            |
|`C`                |Clear stack           |dc `c`                                                           |            |
|`D`                |Decrement             |Deadfish `d`                                                     |`#1\-`      |
|`E`                |`exit()`              |C *stdlib.h*                                                     |            |
|`F`                |                      |                                                                 |            |
|`G`                |`getchar()`           |C *stdio.h*, Befunge `~`, FALSE `^`                              |            |
|`H`                |                      |                                                                 |            |
|`I`                |Increment             |Deadfish `i`                                                     |`#1+`       |
|`J`                |                      |                                                                 |            |
|`K`                |                      |                                                                 |            |
|`L`                |                      |                                                                 |            |
|`M`                |Read number           |Befunge `&`                                                      |            |
|`N`                |                      |                                                                 |            |
|`O`                |Pick (aka Copy)       |FALSE, Whitespace \[Space\]\[Tab\]\[Space\]                      |            |
|`P`                |`putchar()`           |C *stdio.h*, Befunge `,`, FALSE `,`                              |            |
|`Q`                |Debug (print stack)   |dc `f`                                                           |            |
|`R`                |                      |                                                                 |            |
|`S`                |                      |                                                                 |            |
|`T`                |                      |                                                                 |            |
|`U`                |                      |                                                                 |            |
|`V`                |                      |                                                                 |            |
|`W`                |Write number          |Befunge `.`, FALSE `.`                                           |            |
|`X`                |                      |                                                                 |            |
|`Y`                |                      |                                                                 |            |
|`Z`                |Push stack size       |dc `z`                                                           |            |
|`[`                |While (begin)         |Brainfuck                                                        |            |
|`\`                |Swap                  |Befunge, FALSE, Whitespace \[Space\]\[LF\]\[Tab\]                |            |
|`]`                |While (end)           |Brainfuck                                                        |            |
|`^`                |Bitwise xor           |C                                                                |            |
|`_`                |Negate                |C `-`, dc, FALSE                                                 |            |
|`` ` ``            |Slide                 |Whitespace \[Space\]\[Tab\]\[LF\]                                |            |
|`a` - `z`          |Push address          |FALSE                                                            |`#0` - `#25`|
|`{`                |Function (begin)      |dc `[`, FALSE `[`                                                |            |
|<code>&#124;</code>|Bitwise or            |C                                                                |            |
|`}`                |Function (end)        |dc `]`, FALSE `]`                                                |            |
|`~`                |Bitwise not           |C                                                                |            |

`0` - `9`: Pop the top value, multiply by 10, add the numerical value of the digit and push back onto the stack.

# Common patterns

## Commenting
`#(this is a comment)`  
`{this is a comment}$`

## Printing a new line character

`#10P`

## Pushing an integer

`#` will push the number 0. The digits `0` - `9` will take the top value, multiply it by ten and add the digit to it.

To push 0: `#`  
To push 42: `#42`  
To push -1: `#1_`

## Is odd / even

Is odd: `#2\%`  
Is even: `#2\%!`

## Squaring a number

`:*`

## If-else

### If condition then body

condition `(` body `)`

### If condition then body1 else body2

body1 doesn't access the stack:  
condition `:(` body1 `)!(` body2 `)`

body1 is only accessing the top value:  
condition `:(\` body1 `\)!(` body2 `)`

body1 is only accessing the top two values:  
condition `:(;;` body1 `;)!(` body2 `)`

## Looping

Looping m..1:  
`m,[` body `D]$`

Looping 1..m:  
`m,[:m,I-` body `$D]$`

Looping n..m:  
`n,#1[$` body `I:m,I>]$$`

## Converting FALSE structures to calc

`c[` body `]?`:  
`c(` body `)`

`[c][` body `]#`:  
`c[$` body `c]$`

The example `primes.txt` was converted from the [FALSE Prime Numbers](http://strlen.com/false-language "FALSE Prime Numbers") example. Here in comparison:  
<pre> 99 9[1-$][ \$@$@$@$@\/*=[1-$$[%\1-$@]?0=[\$.' ,\]?]?  ]#
#99#9 D : [$\:;:;:;:; /*=(D ::($\D :;) #=(\:W" "\) ) D:] $$$</pre>
