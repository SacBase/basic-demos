SAC demo modules and classes
============================


1) `IntStack.sac`

The SAC class `IntStack` demonstrates the basic concepts of how states and
state modifications are integrated into the functional framework of SAC.
An integer stack is implemented as an example data structure. Besides the
appropriate abstract data type, a set of common access and manipulation
functions is provided. Using the notion of global objects in SAC, also,
a predefined global stack is incorporated.

Apart from the state specific stuff, this class is also a useful introduction
to the declaration and implementation of modules in SAC since classes are
special kinds of modules.




SAC demo programs
=================


1) `use_IntStack.sac`

This SAC demo program demonstrates the usage of the demo class `IntStack`
(see above). Some comprehensive stack operations are defined based on the
stack primitives provided by the class `IntStack`. These are applied to various
example stacks and the respective results are printed.
