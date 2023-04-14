#!/bin/bash


for i in {1..20}
do
	args=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")

	instruction_count=$(./push_swap $args | wc -l)
	test_ok=$(./push_swap $args | ./checker_Mac $args)

	echo "Number of instructions: $instruction_count
	Is sorted?: $test_ok"
done
