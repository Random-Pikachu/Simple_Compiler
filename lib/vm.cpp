#include "../headers/vm.h"
#include <bits/stdc++.h>
using namespace std;

VM::VM(const vector<Instruction> &instructions)
    : instructions(instructions), pc(0) {}

void VM::run() {
    while (pc < instructions.size()) {
        const Instruction &instruction = instructions[pc];
        if (instruction.op == OpCode::HALT) return;
        execute(instruction);
        pc++;
    }
    throw runtime_error("VM error: reached end of program without HALT");
}

void VM::execute(const Instruction &instruction) {
    int a, b, top;

    switch (instruction.op) {
    case OpCode::PUSH:
        push(instruction.operand);
        break;
    case OpCode::POP:
        pop();
        break;
    case OpCode::ADD:
        b = pop();
        a = pop();
        push(a + b);
        break;
    case OpCode::SUB:
        b = pop();
        a = pop();
        push(a - b);
        break;
    case OpCode::MUL:
        b = pop();
        a = pop();
        push(a * b);
        break;
    case OpCode::DIV:
        b = pop();
        a = pop();
        if (b == 0) throw runtime_error("VM error: division by zero");
        push(a / b);
        break;
    case OpCode::PRINT:
        cout << pop() << endl;
        break;
    case OpCode::DUP:
        top = peek();
        push(top);
        push(top);
        break;
    case OpCode::SWAP:
        b = pop();
        a = pop();
        push(b);
        push(a);
        break;
    case OpCode::HALT:
        return;
    default:
        throw runtime_error("VM error: unknown instruction");
    }
}

void VM::push(int value) {
    stack.push_back(value);
}

int VM::pop() {
    if (stack.empty()) throw runtime_error("VM error: stack underflow");
    int value = stack.back();
    stack.pop_back();
    return value;
}

int VM::peek() {
    if (stack.empty()) throw runtime_error("VM error: stack underflow");
    return stack.back();
}
