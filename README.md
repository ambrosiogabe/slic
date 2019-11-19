# Slic

#### Github

The Github link for this code is located [here](https://github.com/ambrosiogabe/slic). The repository contains the changelog, and some test files.

This version of slic is done for all intents and purposes. It successfully compiles counting upward loops, counting downward loops, print statements, read statements, and everything else the documentation states (for all of my test cases at least).

I will give a brief rundown of some of the shortcomings of the compiler, as well as some added features.

## Usage  

To compile a program from Slic to Gstal, you can run:

``` powershell
      slic.exe programFile.slic
    | slic.exe < programFile.slic
```

If the first command is used, it will output a file of the same name as the input, except with the extension changed to ```.gstal```. So executing ```slic.exe test.slic``` will output ```test.gstal``` if compilation succeeds. Using the second command will output a program called ```out.gstal``` if compilation succeeds.

## Shortcomings

There is a memory leak... It is not too big, as long as the user does not enter too many variables, but it should not be a problem in compiling small programs. The OS will clean up the lingering memory once the program exits execution as well, so there should be no longterm ill effects. I would have continued to look for a way to fix this, but the compiler works the way fine for now.

There are also a lot of global variables. I got messy when implementing function calling, and created a few globals to make my life a bit easier, than hastily scrapped together a working product.  

Speaking of functions, this version of the compiler only takes integer and float variables as parameters (no arrays), and it passes by value. It also will not do well if a float parameter gets passed an integer (or vice versa), it will implicitly interpret that integer as a float and result in weird bugs.  

## Extra Features

This version of the Slic compiler does include modulus arithmetic. It implements this by walking the left and right hand side of the binary expression in the AST (Abstract Syntax Tree) twice and doing some fancy maths that I can't recall off the top of my head. It is in the "compiler.c" file though located in the switch expression inside of walkExpressionNode.  

This version of Slic does also support rudimentary functions. You can create a function by writing something like this:

``` slic
fido;
    parameter:
        integer: fluffy;
        real: x;
    data:
    algorithm:
        x := 2 * fluffy;
        return x;
end fido;
```

As you can see:

1. The function is formatted exactly the same way as a main block (or main *function*), with the addition of a parameter section.

2. The data section is optional, so you do not have to include any data if you are purely working with the parameters.

3. The return type does not need to be specified, it will be coerced based on the expression or statement using the function.

4. The beginning statement and end statement must have the name of the function. Otherwise it will result in compilation errors.

To call said function in the main block, you would write code that looks like this:

``` slic
main;
    data:
        ...
    algorithm:
        ...
        someVar := fido(10, 2.9);
end main;
```

If the proper number of arguments is not supplied, it will result in a compilation error and report the problem to the user.

### Example Files

Included in the test files suite (located at ./testFiles/*.slic) are a couple of recursive function implementations that give working examples of how to implement a function in Slic. There is the recursiveFactorial.slic file and the recursiveFibonacci.slic file, which both have a good example of how to code a function.

## The Inner Workings

The whole premise of the compilation process is built around turning the source code into an Abstract Syntax Tree, then walking the tree and outputing appropriate GSTAL code. The AST was built using one base "class" that I made using a struct in c:

``` c
struct AstNode {
    NodeType type;
    int tokenInfoIndex;
    int isFloaty;
    union {
        IfStmt* ifStmt;
        AssignStmt* assignStmt;
        ArrayAssignStmt* arrayAssignStmt;
        Expr* expression;
        UnaryExpr* unaryExpr;
        Value* value;
        ArrayLoad* arrayLoad;
        PrintListNode* printList;
        SymbolTableEntry variable;
        PrintExpr* printExpr;
        WhileLoop* whileLoop;
        CountingLoop* countingLoop;
        ReadArrayNode* readArrayNode;
        EndOfFunctionNode* endOfFunction;
        FunctionCallNode* functionCall;
        ReturnNode* returnNode;
        char* string;
    } as; 
    AstNode* next;
};
```

This node was what comprised every single node of the AST. Since every single node has a ```tokenInfoIndex```, ```isFloaty``` value, and ```next``` pointer to the next branch in the tree, I made those members of the node. 

Then, I wrapped every other type of struct into a union called as, this allows me to use the type to figure out which specific node I'm dealing with, and then cast it to the appropriate type of node by saying something like ```IfStmt* ifNode = node->as.ifStmt;```.  It may seem cumbersome to wrap everything in one struct like this, but it allows for some nice recursive functions to walk the tree and such later on.

The rest of the code is fairly well documented (where the code may not be self-documenting) explaining what the structs are used for, what the functions are used for etc.
