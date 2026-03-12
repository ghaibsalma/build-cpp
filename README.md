# A Simple C++ class builder

As the title suggests, this program is a simple code generator for c++ classes with orthodox canonical form (42/1337 style).

To use you can clone the repo, make and copy the executable to bin
```
make
cp build++ ~/bin
```

Then you could use the command with the name of the class or classes you wanna generate the source files for

```
build++ Dog Cat
```

And it will generate the following files (for thsi example):
Dog.cpp Dog.hpp Cat.cpp Cat.hpp