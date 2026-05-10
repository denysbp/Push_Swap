*This project has been created as part of the 42 curriculum by deferrei, pecoelho.*

---
# Push_swap

## Description

Push_swap is a sorting project from the 42 curriculum. The goal is to sort a stack of integers using only a limited set of stack operations and to do it with as few moves as possible.

The program reads a list of integers, validates the input, and prints the operations needed to sort the values in ascending order.

---
## Instructions

Compile the project with:

```bash
make
```

Run it with a list of numbers:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

If the input is invalid, the program prints `Error`.

The project also supports a benchmark mode:

```bash
./push_swap --bench 4 67 3 87 23
./push_swap --bench --adaptive 4 67 3 87 23
```

Useful Makefile targets:

```bash
make clean
make fclean
make re
```

The repository also includes `checker_linux`, which can be used to verify the output of `push_swap`.

Example:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

---
## Algorithms

This project uses different strategies depending on the size and disorder of the input.

### Simple strategy

For small inputs, the program uses a selection-based approach. It repeatedly finds the minimum value, rotates the stack to bring it to the top, pushes it to the second stack, and then pushes everything back in order.

This is simple to implement and works well when the input is small, but it becomes expensive for larger stacks because it may require many rotations.

### Medium strategy

For medium-sized inputs, the program uses a chunk-based strategy. The stack is divided into chunks, and values are moved to the second stack chunk by chunk.

This reduces the number of operations compared to a pure selection approach, while staying simpler than a full radix-based solution.

### Complex strategy

For larger and more disordered inputs, the program uses radix sort on normalized indices.

This strategy is a good choice for bigger datasets because it scales much better than quadratic approaches and keeps the number of operations more predictable.

### Adaptive strategy

The adaptive mode chooses between the available strategies by checking the stack size and a disorder rate.

This gives the project a practical balance: small inputs use the lightest method, medium inputs use chunk sorting, and heavily disordered inputs use radix sort.

### Justification

The selected algorithms match the constraints of push_swap:

- small inputs need a very low-overhead method
- medium inputs benefit from grouping values into chunks
- large inputs need an approach that avoids quadratic behavior

Using multiple strategies instead of a single fixed algorithm helps reduce the total number of operations across different input sizes.

---
## Resources

Documentation and references:

- 42 push_swap subject and project guidelines
- Stack data structure documentation
- Sorting algorithm references for selection sort, chunk-based sorting, and radix sort
- Articles and tutorials about minimizing operations in push_swap

AI usage:

- AI was used rewrite this README in clear English.


---