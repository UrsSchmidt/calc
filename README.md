# calc
`calc` is a small [esoteric programming language](https://en.wikipedia.org/wiki/Esoteric_programming_language "esoteric programming language") based on [FALSE](https://esolangs.org/wiki/FALSE "FALSE"), [dc](https://esolangs.org/wiki/Dc "dc") and [Deadfish](https://esolangs.org/wiki/Deadfish "Deadfish"). It also draws inspiration from C, [Befunge](https://esolangs.org/wiki/Befunge "Befunge"), [Whitespace](https://esolangs.org/wiki/Whitespace "Whitespace"), [Emmental](https://esolangs.org/wiki/Emmental "Emmental") and [Brainfuck](https://esolangs.org/wiki/Brainfuck "Brainfuck").

# Basics
Every printable ASCII character has exactly one semantic meaning. Some letters do not have any meaning assigned yet. Most characters are executed from left to right (see [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation "RPN")). Thus if you wanted to calculate 6 / 3, it would look like this: `#3#6/o$`. Note that the operands are in reverse order, which is important when subtracting or dividing integers. This example will push the number 3, then the number 6, then divide them by popping both arguments from the stack and pushing the result, i.e. 2, then printing the number to the console and then popping the result back from the stack, leaving it empty.

# Commands

|chr                |Command               |Inspired by                                                      |Short for   |
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
|`;`                |Pick (aka Copy)       |FALSE `ø`, Whitespace \[Space\]\[Tab\]\[Space\]                  |            |
|`<`                |Is less               |C                                                                |            |
|`=`                |Is equal              |C `==`                                                           |            |
|`>`                |Is greater            |C                                                                |            |
|`?`                |If expression         |C                                                                |`` !;#2` `` |
|`@`                |Rotate                |FALSE                                                            |            |
|`A` - `Z`          |Push address          |FALSE `a` - `z`                                                  |`#0` - `#25`|
|`[`                |While (begin)         |Brainfuck                                                        |            |
|`\`                |Swap                  |Befunge, FALSE, Whitespace \[Space\]\[LF\]\[Tab\]                |            |
|`]`                |While (end)           |Brainfuck                                                        |            |
|`^`                |Bitwise xor           |C                                                                |            |
|`_`                |Negate                |C `-`, dc, FALSE                                                 |            |
|<code>&#96;</code> |Slide                 |Whitespace \[Space\]\[Tab\]\[LF\]                                |            |
|`b`                |`putchar('\b')`       |C                                                                |`#8p`       |
|`c`                |Clear stack           |dc                                                               |            |
|`d`                |Decrement             |Deadfish                                                         |`#1\-`      |
|`e`                |                      |                                                                 |            |
|`f`                |`putchar('\f')`       |C                                                                |`#12p`      |
|`g`                |`getchar()`           |Befunge `~`, C, FALSE `^`                                        |            |
|`h`                |Halt                  |Deadfish                                                         |            |
|`i`                |Increment             |Deadfish                                                         |`#1+`       |
|`j`                |                      |                                                                 |            |
|`k`                |                      |                                                                 |            |
|`l`                |                      |                                                                 |            |
|`m`                |Read number           |Befunge `&`                                                      |            |
|`n`                |`putchar('\n')`       |C                                                                |`#10p`      |
|`o`                |Output                |Deadfish, dc `p`                                                 |`:wn`       |
|`p`                |`putchar()`           |Befunge `,`, C, FALSE `,`                                        |            |
|`q`                |Debug (print stack)   |dc `f`                                                           |            |
|`r`                |`putchar('\r')`       |C                                                                |`#13p`      |
|`s`                |Square                |Deadfish                                                         |`:*`        |
|`t`                |`putchar('\t')`       |C                                                                |`#9p`       |
|`u`                |                      |                                                                 |            |
|`v`                |`putchar('\v')`       |C                                                                |`#11p`      |
|`w`                |Write number          |Befunge `.`, FALSE `.`                                           |            |
|`x`                |Call                  |dc, FALSE `!`                                                    |            |
|`y`                |                      |                                                                 |            |
|`z`                |Push stack size       |dc                                                               |            |
|`{`                |Function (begin)      |dc `[`, FALSE `[`                                                |            |
|<code>&#124;</code>|Bitwise or            |C                                                                |            |
|`}`                |Function (end)        |dc `]`, FALSE `]`                                                |            |
|`~`                |Bitwise not           |C                                                                |            |

`0` - `9`: Pop the top value, multiply by 10, add the numerical value of the digit and push back onto the stack.

# Common patterns

## Commenting
`#(this is a comment)`  
`{this is a comment}$`

## Pushing an integer

`#` will push the number 0. The digits `0` - `9` will take the top value, multiply it by ten and add the digit to it.

To push 0: `#`  
To push 42: `#42`  
To push -1: `#1_`

## Is odd / even

Is odd: `#2\%`  
Is even: `#2\%!`

## If-else

### If condition then body

condition `(` body `)`

### If condition then body1 else body2

body1 doesn't access the stack:  
condition `:(` body1 `)!(` body2 `)`

body1 is only accessing the top value:  
condition `:(\` body1 `\)!(` body2 `)`

body1 is only accessing the top two values:  
condition `:(@@` body1 `@)!(` body2 `)`

## Looping

Looping M..1:  
`M,[` body `d]$`

Looping 1..M:  
`M,[:M,i-` body `$d]$`

Looping N..M:  
`N,#1[$` body `i:M,i>]$$`

## Converting FALSE structures to calc

`c[` body `]?`:  
`C(` body `)`

`[c][` body `]#`:  
`C[$` body `C]$`

The example `primes.txt` was converted from the [FALSE Prime Numbers](http://strlen.com/false-language "FALSE Prime Numbers") example. Here in comparison:  
<pre> 99 9[1-$][ \$@$@$@$@\/*=[1-$$[%\1-$@]?0=[\$.' ,\]?]?  ]#
#99#9 d : [$\:@:@:@:@ /*=(d ::($\d :@) #=(\:w" "\) ) d:] $$$</pre>

## Converting a Deadfish program to calc

Simply add `#` to the beginning of the Deadfish program. Integer overflow has to be implemented manually. For examples see `examples/deadfish_test*.txt`, which are test programs taken from [Esolang](https://esolangs.org/wiki/Deadfish#Example_program "Esolang").
