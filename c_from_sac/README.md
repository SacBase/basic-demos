SAC demo modules and classes
============================

## `MyList.sac` / `src/List/*.[ch]`

The C module List naively implements cons-lists on integer numbers in C.
In order to properly handle the memory management involved, the C-code
makes use of some macros of the SAC runtime system such as `SAC_MALLOC`,
`SAC_ND_KS_DEC_OUT_RC`, `SAC_ND_KS_DEC_IN_RC` as can be seen in the C source
files in `src/List/*.[ch]`. 
This is indicated to the `sac2c` compiler by proper `refcounting` - pragmas
in the declaration file `MyList.sac`.


SAC demo programs
=================

## `quicksort_list.sac`

`quicksort_list.sac` straight-forwardly implements QuickSort on cons-lists
as provided by the module List.  However, the implementation is not tuned for
efficiency. A far more efficient implementation can be achieved, when 
operating on arrays. This implementation is meant as an example application
for using the MyList module only.
