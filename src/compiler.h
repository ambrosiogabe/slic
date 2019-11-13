#ifndef SLIC_COMPILER_H
#define SLIC_COMPILER_H
/* ==============================================================
/* This file contains the logic to walk and initialize the 
/* abstract syntax tree.
/*
/* Author: Gabe ambrosio
/* ============================================================== */

#include "abstractSyntaxTree.h"

typedef enum {
    ADI, ADF, SBI, SBF, MLI, MLF, DVI, DVF, NGI, NGF,
    EQI, NEI, LTI, LEI, GTI, GEI, EQF, NEF, LTF, LEF, GTF, GEF, 
    FTI, ITF, PTI, PTF, PTC, PTL, INI, INF, LLI, LLF, ISP, DSP, 
    STO, STM, LOD, LAA, LRA, JMP, JPF, PAR, CAL, RET, NOP, HLT
} InstructionType;

typedef struct {
    int line;
    int hasOperand;
    int operandIsFloat;
    InstructionType type;
    union {
        float fval;
        int   ival;
    } operand;
} Instruction;

typedef struct {
    Instruction* instructions;
    int size;
    int capacity;
} InstructionContainer;

AstNode* astRootNode;
InstructionContainer instructions;

void initInstructionContainer();
void freeInstructionContainer();
void insertFloatInstruction(InstructionType type, float operand);
void insertIntInstruction(InstructionType type, int operand);
void insertEmptyInstruction(InstructionType type);
void walkSyntaxTree();
void initSyntaxTree();

#endif