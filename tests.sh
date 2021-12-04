#!/bin/bash

examples='examples'

function assert {
    title="$1"
    expected="$2"
    actual="$3"
    [ "$actual" != "$expected" ] && echo "$title: Expected $expected, but was $actual"
}

function assert_output_file {
    title="$1"
    output_file="$2"
    program="$3"
    calc "$program" > 'temp_output.txt'
    diff "$output_file" 'temp_output.txt' || echo "$title"
    rm 'temp_output.txt'
}

function assert_input_output_file {
    title="$1"
    input_file="$2"
    output_file="$3"
    program="$4"
    cat "$input_file" | calc "$program" > 'temp_output.txt'
    diff "$output_file" 'temp_output.txt' || echo "$title"
    rm 'temp_output.txt'
}

assert_output_file '99bottles' 'outputs/99bottles.txt' "$examples/99bottles.txt"

assert 'abs' '123' "$(calc "$examples/abs.txt"  123)"
assert 'abs'   '0' "$(calc "$examples/abs.txt"    0)"
assert 'abs' '123' "$(calc "$examples/abs.txt" -123)"

assert 'ackermann'  '1' "$(calc "$examples/ackermann.txt" 0 0)"
assert 'ackermann'  '7' "$(calc "$examples/ackermann.txt" 2 2)"
assert 'ackermann'  '9' "$(calc "$examples/ackermann.txt" 2 3)"
assert 'ackermann' '29' "$(calc "$examples/ackermann.txt" 3 2)"

assert_output_file 'ascii' 'outputs/ascii.txt' "$examples/ascii.txt"

assert 'cat' 'Hello, world!' "$(echo 'Hello, world!' | calc examples/cat.txt)"

assert_input_output_file 'deadfish' 'inputs/deadfish1.txt' 'outputs/deadfish1.txt' "$examples/deadfish.txt"
assert_input_output_file 'deadfish' 'inputs/deadfish2.txt' 'outputs/deadfish2.txt' "$examples/deadfish.txt"
assert_input_output_file 'deadfish' 'inputs/deadfish3.txt' 'outputs/deadfish3.txt' "$examples/deadfish.txt"

assert 'digitalroot' '0' "$(calc "$examples/digitalroot.txt"   0)"
assert 'digitalroot' '6' "$(calc "$examples/digitalroot.txt" 123)"

assert 'factorial'   '1' "$(calc "$examples/factorial.txt" 0)"
assert 'factorial' '120' "$(calc "$examples/factorial.txt" 5)"

assert_output_file 'fibonacci' 'outputs/fibonacci.txt' "$examples/fibonacci.txt"

assert_output_file 'fizzbuzz' 'outputs/fizzbuzz.txt' "$examples/fizzbuzz.txt"

assert 'gcd' '2' "$(calc "$examples/gcd.txt"  4  6)"
assert 'gcd' '6' "$(calc "$examples/gcd.txt" 54 24)"

assert 'heap' 'This example uses heap elements beyond z' "$(calc "$examples/heap.txt")"

assert 'helloworld' 'Hello, world!' "$(calc "$examples/helloworld.txt")"

# TODO interactive-bmi

assert 'power' '1' "$(calc "$examples/power.txt" 0 0)"
assert 'power' '0' "$(calc "$examples/power.txt" 0 1)"
assert 'power' '0' "$(calc "$examples/power.txt" 0 2)"
assert 'power' '1' "$(calc "$examples/power.txt" 1 0)"
assert 'power' '1' "$(calc "$examples/power.txt" 1 1)"
assert 'power' '1' "$(calc "$examples/power.txt" 1 2)"
assert 'power' '1' "$(calc "$examples/power.txt" 2 0)"
assert 'power' '2' "$(calc "$examples/power.txt" 2 1)"
assert 'power' '4' "$(calc "$examples/power.txt" 2 2)"
assert 'power' '8' "$(calc "$examples/power.txt" 2 3)"
assert 'power' '9' "$(calc "$examples/power.txt" 3 2)"

assert 'rot13' 'NOPABC' "$(echo 'ABCNOP' | calc examples/rot13.txt)"

assert 'sgn'  '1' "$(calc "$examples/sgn.txt"  123)"
assert 'sgn'  '0' "$(calc "$examples/sgn.txt"    0)"
assert 'sgn' '-1' "$(calc "$examples/sgn.txt" -123)"

assert_output_file 'squares' 'outputs/squares.txt' "$examples/squares.txt"

assert_input_output_file 'trigraphs' 'inputs/trigraphs.txt' 'outputs/trigraphs.txt' "$examples/trigraphs.txt"

# TODO truth
