#ifndef SLIC_COMPILER_H
#define SLIC_COMPILER_H
/* ==============================================================
/* This file contains the logic to walk and initialize the 
/* abstract syntax tree.
/*
/* Author: Gabe ambrosio
/* ============================================================== */

#include "abstractSyntaxTree.h"

AstNode* astRootNode;

void walkSyntaxTree();
void initSyntaxTree();

#endif