This is a repository with example sac programs.

Building programs require operational sac2c and sac4c as well as CMake at least version 3.3.

Building instructions:
```bash
$ cd basic-demos
$ git submodule init
$ git submodule update
$ mkdir build
$ cd build
$ cmake ..
$ make -j5
```
Compiled files will be available under `build` directory, under corresponding
sub-directories.  Each directory will be build for `seq` and `mt_pth` targets,
appending the name of the target to the name of the directory.

# simple

This directory contains very simple examples such as `gcd` only. It is primarily
useful for the entirely novice user.


# composing\_programs

The demo programs of this directory are less meant for studying the program codes
themselves but for running the compiled applications and inspecting the output
generated. Due to their basic nature, they are a good starting point when
being familiar with C and trying to get used to the peculiarities of SAC.


# states

Here you will find some examples for demonstrating how to create your own 
state-full data structures in SAC. Since the documentation on states and
state-modifications in SAC is not too extensive this might be a good
source for getting started with states in SAC.


# c\_from\_sac

The programs in this directory demonstrate how C-libraries can be used from
SAC programs. However, besides the examples found in this directory there
are several further examples hidden in the standard library.

# sac\_from\_c

`sac_from_c` contains several examples for how to export the various features 
of SAC to the C world. Probably, this is the most interesting part of the demos
if you intend to replace part of an existing C/C++/Fortran program by a
SAC implementation.
