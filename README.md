# linear_algebra_cpp

Learning linear algebra for ML with C++

## Intro

This repo contains source code and documentation for doing basic linear algebra operations in C++. It is for engineers who want to get a practical foundation in Linear Algebra through programming. I made this repo for the following reasons.

1.  I was already an experienced Python and Scala developer but had relatively little experience in C/C++ and I need to understand these languages as many of the low level tools (scientific computing libraries for example) are written in either C or C++ for performance reasons.
2.  I was an experienced Data Scientist without a formal background in Linear Algebra.

Many programming courses are designed for absolute beginners and are very tedious for those with extensive programming experience who really just want know how to do certain things in a new language (declare a variable, write a class definition, write a for loop ) but don't need these concepts reexplained to them from scratch in the process. Many math courses are also designed to give a theoretical introduction to a particular topic and are not tailored to engineers who are "just trying to get stuff done" and don't need to spend hours understanding proofs.

I decided I would start writing my own scientific computing library for C++ - this would allow me to absorb the Linear Algebra concepts I was learning and understand how to practically implement algorithms while also getting a foothold in C++.

I assume that anyone using the library is familiar with basic programming concepts ( object-orientation, pointers etc) as I won't delve deeply into these topics.

This is an ongoing learning experience and any helpful feedback is more than welcome.

## Acknowledgements

Much of the code and content here is taken or adapted from the Youtube channel 'Quantative Bytes's video series 'Linear Algebra in C++' or the 'C++ Primer' by Lippman, Lajoie and Moo (LLM) which I have adapted to my own use case. I also use the book 'Mathematics for Machine Learning' by Deisenroth, Faisal and Ong (DFO) and Sheldon Axler's 'Linear Algebra Done Right'. (SA) I will try to provide explicit references using the shorthand I described above where applicable.

# Matrices

"A matrix is an m\*n-tuple of elements which is ordered according to a rectangular schema consisting of m rows and n columns" (Deisenroth, Faisal and Ong)

In programming terms, a matrix can be conceived of as an array, where each element of the array is an array of real numbers (float, integer, double, long etc). While we could store chars and strings in a nested array of this type, most operations on a matrix are defined as operations on the underlying real valued numbers stored in the arrays themselves ( mathematically there is no definition for "adding" two strings) - so we say that it must be some kind of number.

So the first step to designing our scientific computing library is to create a `class` which will store the data of the matrix described above and will allow us to define methods for matrix operations on that data.

Unlike languages like Java or Python C++ defines classes as `templates` in separate header files (LLM, 19).

If your familiar with basic C/C++ concepts you know that external dependencies to a program are defined in header files that end with `.h`. We then include those dependencies in our own programs by adding `#include <dependency>` to the top of any program that needs it. (I'm using the term library as it will be familiar to those coming from the JVM or Python).


    #include <iostream>

    int main() {
      
      std::cout << "Enter two numbers:"  << std::endl;
      int v1 = 0, v2 = 0;
      std::cin >> v1 >> v2;
      std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
      return 0;
    }

So we need to write a
