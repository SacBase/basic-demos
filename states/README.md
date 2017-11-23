/*****************************************************************************
 * 
 * file:   README
 *
 * description:
 *
 *   This file is to give an overview of the SAC demo programs of this
 *   directory.
 *   
 *   The directory comes with a Makefile that contains pattern rules
 *   for making executables from SAC-source files. Therefore each of the
 *   demo programs <name>.sac can be compiled by simply running (GNU-)
 *   "make <name>". The pattern rules provided even comprise an implicit
 *   dependency-checking system. It makes sure that any module needed for
 *   the compilation of a particular program will be compiled on beforehand.
 *   
 *****************************************************************************/



SAC demo modules and classes:
=============================


1) IntStack.dec / IntStack.sac

The SAC class IntStack demonstrates the basic concepts of how states and
state modifications are integrated into the functional framework of SAC.
An integer stack is implemented as an example data structure. Besides the
appropriate abstract data type, a set of common access and manipulation
functions is provided. Using the notion of global objects in SAC, also,
a predefined global stack is incorporated.

Apart from the state specific stuff, this class is also a useful introduction
to the declaration and implementation of modules in SAC since classes are
special kinds of modules.




SAC demo programs:
==================


1) use_IntStack.sac

This SAC demo program demonstrates the usage of the demo class IntStack
(see above). Some comprehensive stack operations are defined based on the
stack primitives provided by the class IntStack. These are applied to various
example stacks and the respective results are printed.


