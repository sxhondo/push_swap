# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.
### Installation
```sh
$ git clone --recurse-submodules https://github.com/sxhondo/push_swap.git && cd push_swap && make
```
### Overview
Projects consists of two binaries ./push_swap and ./checker
+ ./push_swap - sorts the stack given to him as an argument and displays the necessary commands
+ ./checker - checks the correctness of the list of commands given by ./push_swap

### Run
```sh
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

### Visualisation
```sh
python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"
````
## Summary
+ Main algorithm - quick-sort with a small modifications
+ Stacks are implemented via linked-lists.
