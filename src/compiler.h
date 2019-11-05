#ifndef SLIC_COMPILER_H
#define SLIC_COMPILER_H

#include "abstractSyntaxTree.h"

AstNode* astRootNode;

void walkSyntaxTree();
void initSyntaxTree();

#endif