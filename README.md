# Simple Stack-Based Compiler

A basic compiler implementation that processes a custom assembly-like language and executes it on a stack-based virtual machine. Built this to understand how compilers work under the hood - from tokenization to bytecode generation and execution.

## What it does

Takes simple assembly instructions like `push`, `add`, `print` and runs them through three stages:
1. **Lexer** - breaks source code into tokens
2. **Parser** - converts tokens into bytecode instructions  
3. **VM** - executes the bytecode on a stack machine

## Project Structure

```
simple_compiler/
├── main.cpp              # Entry point - orchestrates lexer → parser → VM pipeline
├── test.file             # Sample program to test the compiler
├── headers/
│   ├── lexer.h           # Lexer interface and Token definitions
│   ├── parser.h          # Parser interface
│   ├── vm.h              # Virtual machine interface
│   └── opcodes.h         # OpCode enum
└── lib/
    ├── lexer.cpp         # Tokenization logic
    ├── parser.cpp        # Bytecode generation from tokens
    └── vm.cpp            # Stack-based execution engine
```

## Supported Instructions

- `push <number>` - push a value onto the stack
- `pop` - remove top value from stack
- `add` - pop two values, push their sum
- `sub` - pop two values, push difference (a - b)
- `mul` - pop two values, push product
- `div` - pop two values, push quotient (a / b)
- `print` - pop and print top value
- `dup` - duplicate top stack value
- `swap` - swap top two stack values
- `halt` - stop execution

## Building and Running

Compile the project:
```bash
g++ -std=c++17 -o simple_compiler main.cpp lib/lexer.cpp lib/parser.cpp lib/vm.cpp
```

Run with a source file:
```bash
./simple_compiler test.file
```

You'll see three sections of output:
- **TOKENS** - what the lexer extracted
- **BYTECODE** - instructions the parser generated
- **Execution** - actual program output

## Example

Given `test.file`:
```
push -7
push 3
add
print
halt
```

Output:
```
======TOKENS======
[INSTRUCTION "push" L1]
[NUMBER "-7" L1]
[INSTRUCTION "push" L2]
[NUMBER "3" L2]
[INSTRUCTION "add" L3]
[INSTRUCTION "print" L4]
[INSTRUCTION "halt" L5]
[EOF "" L5]

======BYTECODE======
PUSH -7
PUSH 3
ADD 0
PRINT 0
HALT 0

======Execution======
-4
```

### Thanks a lot :)

