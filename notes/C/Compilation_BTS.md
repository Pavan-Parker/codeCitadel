# Compilation BTS

![Overview](Compilation_BTS.assets/GCC_CompilationProcess.png)

## Preprocessing

In this stage, we take the input (.c, .cpp, .h) souce files and 

1. Expand the included files.
2. Conditional Compiling.
3. Expand the macros.
4. Strip the comments away.

Outputs a (.i,.ii) file.

## Compilation

In this stage, we take the input (.i,.ii) files and convert the code into the assembly code that is unique to the architecture.

Outputs a (.s) file.

## Assembly

In this stage, we take the input (.s) assembly files and convert them into machine level instructions.

Outputs a (.o) file.

## Linking

In this stage, we take the inputs (.o) object files and link the object code of our program with the object code of the library files and other files.

Till now the libraries functions are not mapped to any memory. These library functions are pre-compiled, and the object code of these library files is stored with '.lib' (or '.a') extension. In this stage, if the compilation is static (which is not default for GCC), it will link them to those functions. Else, that will be done while runtime.
