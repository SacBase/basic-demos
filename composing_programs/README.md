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



SAC demo programs:
==================


1) arrays.sac

This SAC demo program prints an introduction to the SAC array concept.
Basic issues like the SAC specific representation of arrays are covered
as well as the basic operations on arrays. Moreover, the functionality of
some high-level array operations that used to be primitive in former versions
of SAC, but are now provided by the module 'Array' from the SAC standard 
library, is explained by means of examples.


2) withloop.sac

This SAC demo program prints an introduction to the SAC specific array
construct with-loop. However, only a subset of the complete functionality
of today's with-loops is covered by this demo program.


3) use_CommandLine.sac

This SAC demo program prints a reference guide to the module 'CommandLine'
from the SAC standard library. This module provides access to the command
line arguments of a SAC application program.


4) use_String.sac

This SAC demo program prints a reference guide to the module 'String' from
he SAC standard library. This module provides strings as an abstract data type
along with a large set of operations on strings.


