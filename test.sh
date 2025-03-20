#!/bin/bash

for i in {1..20}
do
	args=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-$1, $1), $1))))")

	instruction_count=$(./push_swap $args | wc -l)

	test_ok=$(./push_swap $args | ./checker $args)

	echo "Number of instructions: $instruction_count
	Is sorted?: $test_ok"
done
