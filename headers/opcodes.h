enum class OpCode {
    PUSH,   // push to stack
    POP,    //pop stack top
    ADD,    //pop 2 elements and push their sum
    SUB,    //pop 2 elements and push their difference
    MUL,    //pop 2 elements and push their product
    DIV,    //pop 2 elements and push their quotient
    PRINT,  //pop one and print it
    DUP,    //duplicate top of stack
    SWAP,   //swap top 2 elements of stack
    JMP,    //jump to address
    JMP_IF_ZERO, //jump if top of stack is zero
    JMP_IF_NOT_ZERO, //jump if top of stack is not zero
    HALT    //halt execution
};