# C - Stacks, Queues - LIFO, FIFO
This project is to learn about the data structures on C.
## Learnin objectives
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables
## Opcodes
Opcodes | Description
:---: | ---
push | pushes an element to the stack
pall | prints all the values on the stack, starting from the top of the stack
pint | prints the value at the top of the stack, followed by a new line
pop | removes the top element of the stack
swap | swaps the top two elements of the stack
add | adds the top two elements of the stack
nop | doesn’t do anything
## Monty files examples
```
vagrant@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
```
vagrant@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```
## Set up
* Ubuntu 14.04 LTS
* `GCC version 4.8.4` with flags: `-Wall` `-Werror` `-Wextra` and `-pedantic`