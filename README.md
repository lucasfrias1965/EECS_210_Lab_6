# EECS_210_Lab_5

Hey Pardas,

This lab was fun and I had a blast. I did it in C++. Here's how to install C++ (which you said is your primary language already, but just for completeness):

**PS** this can take both command line input or POSIX arg counting, as per the input file in python. just make sure to do

./a.out "(x+y)^3"

as if you do 

./a.out (x+y)^3

zsh will not treat it as a string.

# Mac OS

clang should be installed by default, and there's no reason it shouldn't compile like

```
clang main.cpp
```

I used g++, but that's Linux specific and probably not needed. I think it's installed as a variant in Xcode coreutils, so if you've done any moderate amount of development on your mac you should already have it. Try clang first, and then try g++. Here's an install tutorial for xcode. 

https://stackoverflow.com/questions/2122425/how-do-i-install-g-on-macos-x

https://brew.sh/
