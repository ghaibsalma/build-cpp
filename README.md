# A Simple C++ class builder

This program is a simple code generator for c++ classes (*.cpp/ *.hpp) with orthodox canonical form (42/1337 style).

*Because writing classes, constructors, copy constructor, copy assignment operator annnd and a destructor is too tedious.*

To use you can clone the repo, make and copy the executable to bin
```
make
cp build++ ~/bin
```

Then you could use the command with the name of the class or classes you wanna generate the source files for

```
build++ Dog Cat
```

And it will generate the following files (for this example):  
Dog.cpp Dog.hpp Cat.cpp Cat.hpp