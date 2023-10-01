    #include <Rcpp.h>
    using namespace Rcpp;
    int main(){
        std::cout << "The number of elements in mymatrix2 is " << std::endl;
        return 1;
    }

    //[[Rcpp::export]]
    Rcpp::IntegerVector double2Me() {
      return main();
    }

For each element of the first row or first column get the cofactor of
those elements and then multiply the element with the determinant of the
corresponding cofactor, and finally add them with alternate signs. As a
base case, the value of the determinant of a 1\*1 matrix is the single
value itself.

Cofactor of an element is a matrix that we can get by removing the row
and column of that element from that matrix.

    m = cbind(c(1,2,3), c(1,2,3), c(1,2,3))

    m[0:-1,0:-1]

    ##      [,1] [,2]
    ## [1,]    2    2
    ## [2,]    3    3

    for(i in 1:(dim(m)[[1]])) {
      
      sign = -1
      

    }

    #include <Rcpp.h>
    // C program to find Determinant
    // of a matrix
    #include <stdio.h>

    // Dimension of input square matrix
    #define N 4

    // Function to get cofactor of mat[p][q]
    // in temp[][]. n is current dimension
    // of mat[][]
    void getCofactor(int mat[N][N], int temp[N][N],
                    int p, int q, int n)
    {
        int i = 0, j = 0;

        // Looping for each element of the matrix
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // Copying into temporary matrix
                // only those element which are
                // not in given row and column
                if (row != p && col != q)
                {
                    temp[i][j++] = mat[row][col];

                    // Row is filled, so increase row
                    // index and reset col index
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    /* Recursive function for finding the
    determinant of matrix. n is current
    dimension of mat[][]. */
    int determinantOfMatrix(int mat[N][N], int n)
    {
        // Initialize result
        int D = 0;

        // Base case : if matrix contains
        // single element
        if (n == 1)
            return mat[0][0];

        // To store cofactors
        int temp[N][N];

        // To store sign multiplier
        int sign = 1;

        // Iterate for each element of
        // first row
        for (int f = 0; f < n; f++)
        {
            // Getting Cofactor of mat[0][f]
            getCofactor(mat, temp, 0, f, n);
            D += sign * mat[0][f]
                * determinantOfMatrix(temp, n - 1);

            // Terms are to be added with alternate sign
            sign = -sign;
        }

        return D;
    }

    // Function for displaying the matrix
    void display(int mat[N][N],
                int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                printf(" %d", mat[i][j]);
            printf("n");
        }
    }

    // Driver code
    int main()
    {
        int mat[N][N] = {{1, 0, 2, -1},
                        {3, 0, 0, 5},
                        {2, 1, 4, -3},
                        {1, 0, 5, 0}};

        // Function call
        printf("Determinant of the matrix is : %d",
                determinantOfMatrix(mat, N));
        return 0;
    }

    //[[Rcpp::export]]
    Rcpp::IntegerVector determinant() {
      return main();
    }

    determinant()

    ## integer(0)

# linear\_algebra\_cpp

Learning linear algebra for ML with C++

## Intro

This repo contains source code and documentation for doing basic linear
algebra operations in C++. It is for engineers who want to get a
practical foundation in Linear Algebra through programming. I made this
repo for the following reasons.

1.  I was already an experienced Python and Scala developer but had
    relatively little experience in C/C++ and I need to understand these
    languages as many of the low level tools (scientific computing
    libraries for example) are written in either C or C++ for
    performance reasons.
2.  I was an experienced Data Scientist without a formal background in
    Linear Algebra.

Many programming courses are designed for absolute beginners and are
very tedious for those with extensive programming experience who really
just want know how to do certain things in a new language (declare a
variable, write a class definition, write a for loop ) but don’t need
these concepts reexplained to them from scratch in the process. Many
math courses are also designed to give a theoretical introduction to a
particular topic and are not tailored to engineers who are “just trying
to get stuff done” and don’t need to spend hours understanding proofs.

I decided I would start writing my own scientific computing library for
C++ - this would allow me to absorb the Linear Algebra concepts I was
learning and understand how to practically implement algorithms while
also getting a foothold in C++.

I assume that anyone using the library is familiar with basic
programming concepts ( object-orientation, pointers etc) as I won’t
delve deeply into these topics.

This is an ongoing learning experience and any helpful feedback is more
than welcome.

## Acknowledgements

Much of the code and content here is taken or adapted from the Youtube
channel ‘Quantative Bytes’s video series ’Linear Algebra in C++’ or the
‘C++ Primer’ by Lippman, Lajoie and Moo (LLM) which I have adapted to my
own use case. I also use the book ‘Mathematics for Machine Learning’ by
Deisenroth, Faisal and Ong (DFO) and Sheldon Axler’s ‘Linear Algebra
Done Right’. (SA) I will try to provide explicit references using the
shorthand I described above where applicable.

## Disclaimer

I am completely self taught student of programming and computer science.
The explanations and code in this document are provided on an as is
basis and I don’t make any claims that anything I have written is
correct. By writing things down and trying to explain what I am learning
I help myself learn and process ideas. However much if not all of what I
have written may be considered or may simply be incorrect. If i’ve made
a mistake please correct me - don’t take anything I say (or anything
anyone else says) as gospel - use your God-given rational faculties to
interpret everything and come to the truth of the matter yourself.

## Testing and Running Code

I am using Rstudio as my IDE for the following reasons.

1.  I don’t want to pay for an IDE
2.  I don’t like VSCode or any of the other free IDES (CodeBlocks etc.)
3.  I already have several IDES installed on my computer for other
    languages and hate bloat
4.  Rstudio is a great all around IDE and includes support for easily
    running C/C++ programs - plus I am familiar with it from using R.

Running C++ code in Rstudio is very easy. You create a new C++ file from
a template, and it will add some elements to it to allow you to simple
source the file as if it were a .R file. Then just source the file and
it will compile and run the functions for you. Boom.

# Matrices

“A matrix is an m\*n-tuple of elements which is ordered according to a
rectangular schema consisting of m rows and n columns” (Deisenroth,
Faisal and Ong)

In programming terms, a matrix can be conceived of as an array, where
each element of the array is an array of real numbers (float, integer,
double, long etc). While we could store chars and strings in a nested
array of this type, most operations on a matrix are defined as
operations on the underlying real valued numbers stored in the arrays
themselves ( mathematically there is no definition for “adding” two
strings) - so we say that it must be some kind of number.

So the first step to designing our scientific computing library is to
create a `class` which will store the data of the matrix described above
and will allow us to define methods for matrix operations on that data.

Unlike languages like Java or Python C++ defines classes as `templates`
in separate header files (LLM, 19).

If your familiar with basic C/C++ concepts you know that external
dependencies to a program are defined in header files that end with
`.h`. We then include those dependencies in our own programs by adding
`#include <dependency>` to the top of any program that needs it. (I’m
using the term library as it will be familiar to those coming from the
JVM or Python).

    #include <Rcpp.h>
    #include <iostream>

        int main() {
          
          int v1 = 0, v2 = 0;
          std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
          return 0;
        }

    //[[Rcpp::export]]
    Rcpp::IntegerVector test() {
      return main();
    }

    test()

    ## integer(0)

So, in order to create a class for our matrix we need a header file with
a class template. Lets create a basic header file and then a program
that uses it just to get our heads around the concept. This example is
adapted from LLM page 77.


        #ifndef MATRIX_H
        #define MATRIX_H

        template <class T>
        class matrix
        {
        public:
          matrix();
        };

        #endif

Okay a lot more going on here than I thought. First lets talk about the
header directives. If you look in LLM page 77 they discuss
<strong>header guards</strong>. The idea is that when we have a header
file, we may define some classes or methods that have dependencies on
other header files, and so we have to `#include` those in our own header
files. However this can lead to recursive imports since other header
files may also `#include` those same dependencies. You may have run into
this problem in python imports. In order to avoid this, we use the
header guards `#ifndef <>; #define;…#endif;` - our code goes where the
ellipses are.

### Interlude: Classes versus Templates

C++ has classes and templates; Scala just has classes which can be type
parameterizable - C++(?) and Scala are both strongly typed in that the
types have to be known at compile time - one of the issues that comes up
is say we want to define a class that takes an input variable to its
constructor of a certain type, but we dont want to define separate
classes for each type we want to support ( in our case a matrix of
integers and a matrix of longs).

In Scala we would do something like this.  

    class Matrix[A];

The C++ equivalent is a `template`: Notice that we have a single method
that hasn’t yet been implemented - the class constructor. In C++ we
implement these separately.

    #include <Rcpp.h>

        template <class T>
        class matrix
        {
        public:
          matrix();
          int nRows;
          int nCols;
          int nElements;
          T *elements;
        };

        template <class T>
        matrix<T>::matrix()
        {
          nRows = 1;
          nCols = 1;
          nElements = 1;
          elements = new T[nElements];
          elements[0] = 0.0;
        }

We can test that we have done everything correctly with the following
test program


        #include <Rcpp.h>
        #include "/Users/pat/Projects/linear_algebra_cpp/src/matrix/matrix.h"
        using namespace Rcpp;

        int mCreateTest()
        {
          matrix<int> mymatrix = matrix<int>();
          std::cout << "The number of elements in mymatrix is " << mymatrix.m_nElements << std::endl;
          
          return 0;
        }
        
    //[[Rcpp::export]]
    Rcpp::IntegerVector RmCreateTest() {
      return mCreateTest();
    }

    RmCreateTest()

    ## integer(0)

Couple of things to note.

1.  Once we `include` the matrix .h header file, we can define the
    matrix by specifying the type we want in the constructor. Much
    easier than I expected.
2.  We can access public class members with the `.` notation. very easy.
3.  We can deallocate the memory allocated to the matrix using the
    &notation, which returns a reference? to the object ( still not
    clear on this)

Our matrix still doesn’t really have any data because we only defined a
constructor that returns a 1 dimensional matrix with a single float in
it. Lets define a constructor for our matrix that returns a matrix of a
given size with all the elements set to zero.

### Naming conventions

I realized at this point that I need to adjust my naming conventions for
variables and parameters. I wanted to keep things simple but If I define
a constructor that takes an `int` and then sets a class member to that
input parameter, the name of the class member must be different than the
input parameter. So i am going to append an `m_` to all class members to
indicate these are members of the class matrix. I don’t know if this is
standard convention, its what I saw in Quantitative Bytes, but its a
good lesson that you should set for yourself consistent naming
conventions that you follow ( I don’t go in for style guides and
standards as this just adds to the every growing pile of things you need
to learn) - as long as the convention makes sense and you follow it, its
probably good enough.

Heres the new template for our new constructor.

    template <class T>
    matrix<T>::matrix(int nRows, int nCols)
    {
      m_nRows = nRows;
      m_nCols = nCols;
      m_nElements = nRows*nCols;
      m_elements = new T[m_nElements];
      for(int i = 0; i<m_nElements; i++){
        m_elements[i]=0.0;
      }
    }

We also have to update the class template with a reference to our new
method before implementing it.

    template <class T>
    class matrix
    {
    public:
      matrix();
      matrix(int nRows, int nCols);
      int m_nRows;
      int m_nCols;
      int m_nElements;
      T *m_elements;
    };

We can then update our test code.

    int mCreateTest()
    {
      matrix<int> mymatrix = matrix<int>();
      std::cout << "The number of elements in mymatrix is " << mymatrix.m_nElements << std::endl;
      delete &mymatrix;
      
      matrix<int> mymatrix2 = matrix<int>(2,2);
      std::cout << "The number of elements in mymatrix2 is " << mymatrix2.m_nElements << std::endl;
      delete &mymatrix2;
      
      return 0;
    }

### Destructor

Now I am told we need something called a destructor. This is because we
need to use dynamic memory allocation. This is typically something that
in a language like Python and JVM based languages like Scala we never
think about - all memory allocation is dynamic. ( In reality the JVM
bulk allocates a portion of the available underlying memory when it
starts up and then manages it for you, so this process is opaque to the
user).

However in C++ this is not the case. Local and global variables are
allocated to the stack, and dynamically allocated memory is put on the
heap.  
  
With our matrix program, we want to be able to create more or less any
size matrix, subject to the limits of the OS and hardware. So this means
we need dynamic memory allocations - ie memory for our matrix will be
allocated at runtime based on conditions set by the user.

Because C++ does not have a garbage collector like JVM based languages,
dynamically allocated memory is not automatically deallocated. As a
result we need to make sure that the memory allocated with the new
keyword is deallocated with the `delete` keyword.

You’ll notice that I used the `delete` keyword to delete my matrix -
however when I looked into it I realized this does NOT deallocate the
memory allocated for the matrix data, because we used the `new` keyword
to create that array.

In order to make sure that the underlying data does get deallocated, we
need to define a destructor for the class that deletes any memory that
we allocated during the class construction.

We use the `~` to define the destructor. Lets add it to our class
template.

    template <class T>
    class matrix
    {
    public:
      matrix();
      ~matrix();
      matrix(int nRows, int nCols);
      int m_nRows;
      int m_nCols;
      int m_nElements;
      T *m_elements;
    };

Now we can define the interface.

    template <class T>
    matrix<T>::~matrix()
    {
      if(m_matrixData!=nullptr){
        delete[] m_elements;
      }
    }

## Re-factoring

At this point I realized I did not like the implementation that was
being described by QuantativeBytes - in that we are using a single array
to store all elements of the matrix. Its possible to do it this way by
just using basic arithmetic to determine the positions of various
elements along the rows and columns within the one dimensional array,
and he gives an explanation as to why he does it this way ( something
about raw pointers, which I don’t yet understand - how can a pointer be
raw?) but one of the main issues i see is that every-time we want to
access an element in the array we have to compute its location based in
the user provided indices - It seems to me that this adds significant
overhead to accessing elements in our matrix which with small matrices
is probably trivial but may ultimately affect the performance in larger
dimensions.

So instead I decided we would create a two dimensional matrix using
nested arrays. I went to LLM p 126 to read up on multidimensional
arrays.

There is apparently several ways to make multidimensional arrays in c++
but of course one of our requirements is dynamic memory allocation. So
we do this by declaring an array of pointers.

    T** m_elements;

So whereas `T*` declares a single pointer that points to the start first
block of memory to our array (since an array is just a contiguous block
of memory) declaring an array of pointers in this way makes sense- every
array index points to a piece of memory that can be used to instantiate
an array.

After we declare our array of pointers, we instantiate it using the
`new` keyword. `new T*[n]` says “give me an array of pointers where each
pointer points to an array of type T where each element is of type T” .

      m_elements = new T*[m_nElements]; //declare a memory block
      for(int i=0; i<m_nRows; i++){
            m_elements[i] = new T[m_nCols];
            for (int j=0; j<m_nCols; j++){
              m_elements[i][j]=0.0;
            }
      }

With our updated constructors we can now work on adding a method to
access and index elements in our matrix. I really wanted to be able to
index elements of my matrix using the regular `[]` operator instead of
writing some method that does it for me - since I want my matrix to
basically behave in a familiar way. Fortunately this is possible in C++
although I am not going to expand this functionality alot as I will
focus more on developing the actual matrix operations. So lets just have
the `[]` operator return the array at the given index.

       T* operator[] (int n){

        if(n>m_nRows){
          std::cout << "Index " << n << " exceeds the number of matrix elements " << m_nElements << std::endl; 
          return m_elements[0];

        }
        else return m_elements[n];
        
      }

Right now if the user tries to access an element that doesnt exist in
the matrix, we just print a warning to stdout and return the first
element. I don’t know how exactly to throw and catch errors yet so this
seemed like the best way to do it.

Notice that unlike the approach of Quantitative Bytes, I decided to
return a pointer rather than a reference. That way, I declare a pointer
to the column that I am interested in looking at, which returns a
pointer to the first row element for that column, allowing me then to
iterate over those elements easily.

We will add a simple test to our test file to make sure it works.


        #include <Rcpp.h>
        #include "/Users/pat/Projects/linear_algebra_cpp/src/matrix/matrix.h"
        using namespace Rcpp;

       int main()
        {
          matrix<int> mymatrix = matrix<int>();
          std::cout << "The number of elements in mymatrix is " << mymatrix.m_nElements << std::endl;

          matrix<int> mymatrix2 = matrix<int>(1000,1000);
          std::cout << "The number of elements in mymatrix2 is " << mymatrix2.m_nElements << std::endl;
         
         int *p =mymatrix2[900];
         for(int i = 0; i<mymatrix2.m_nRows; i++){
           int v = p[i];
           std::cout << "The" <<i <<"th element of the 900th element of mymatrix2 is " << v << std::endl;
           
         }
         
         int *p2 =mymatrix2[1001];
         int *p3 =mymatrix2[0];
         
         std::cout << "The 1001th element mymatrix2 is " << p2 << std::endl;
         
         std::cout << "The pointer p2 "<< p2 << " is the same as " << p3 << std::endl;

          return 0;
        }
        
    //[[Rcpp::export]]
    Rcpp::IntegerVector RmCreateTest() {
      return main();
    }

    RmCreateTest()

    ## integer(0)

We have most of the boilerplate in place - we need to implement one more
constructor to get started actually implementing things - a constructor
that takes some in a predefined matrix data to work on.

This was a bit tricky as what I realized/thought I have to do is to
reassign the pointer value `m_elements` the pointer value corresponding
to the first element of the matrix data that I created. So first I need
a way just to create an array of arrays that had actual values, which I
did like this.

     int arr[6] = { 10, 20, 30, 40 };
     int arr2[6] = { 10, 20, 30, 40 };
     int* elements[2];
     elements[0] = &arr[0];
     elements[1] = &arr2[0];

Then I should be able to pass this into my constructor - this didn’t
quite work though. I eventually got it to this.

     int arr[6] = { 10, 20, 30, 40 };
     int arr2[6] = { 10, 20, 30, 40 };

     int** elements =  new int*[2];
     
     elements[0]= arr;
     elements[1]= arr;

This part was educative for me because it began to help me understand
better what an array is and what pointers really are and how they
function. Notice that the declaration

     int arr[6] = { 10, 20, 30, 40 };

Declares an array and instantiates it with a bunch of values between the
brackets. However when I print the value of `arr` I see that its a
POINTER. That’s because an array is just a contiguous block of memory,
and in a language like C or C++ (unlike in Java, Python, Scala, etc), we
manipulate the elements of the array in a more direct manner by
interacting with the memory directly, rather than indirectly through the
language’s API.

Which allowed me to define the constructor that takes the matrix
elements

    template <class T>
    matrix<T>::matrix(T** elements){
      
      int size = SIZEOF(elements);
      
      std::cout << "The size of the elements array is " << size << std::endl;
      
      m_elements = new int*[size];

      m_elements = elements;
    }

And now I can create a matrix with my elements.

       
       
        #include <Rcpp.h>
        #include "/Users/pat/Projects/linear_algebra_cpp/src/matrix/matrix.h"
        using namespace Rcpp;
        
        int main() {
          
         int arr[6] = { 10, 20, 30, 40 };
         int arr2[6] = { 50, 60, 70, 80 };

         int** elements =  new int*[2];
         
         elements[0]= arr;
         elements[1]= arr2;
         
         
        matrix<int> mymatrix3 = matrix<int>(elements,2,4);
        
        mymatrix3.print();
         return 2;
          
    }
        
        //[[Rcpp::export]]
    Rcpp::IntegerVector RmCreateTest() {
      return main();
    }

    RmCreateTest()

    ## [1] 0 0

# Matrix Decomposition

## The Determinant

The Determinant of a matrix is a mapping from a matrix A to a real
number. The determinant is measurement of the signed volume of an
n-dimensional paralleleipiped formed by the columns of the matrix A.

The Determinant can be used to test for matrix invertability. If the
determinant is zero, the matrix is not invertible.

For triangular matrices, the determinant is the product of the diagonal
elements.

    #include <Rcpp.h>
        int main(){
          int arr[2] = {1,2};
          int size = *(&arr + 1) - arr;
          std::cout << "The size of the array is " << size << std::endl;
          return 0;
    }
        //[[Rcpp::export]]
        Rcpp::IntegerVector ArraySize () {
          return main();
    }

    ArraySize()

    ## integer(0)

       
       
        #include <Rcpp.h>
        #include "/Users/pat/Projects/linear_algebra_cpp/src/matrix/matrix.h"
        using namespace Rcpp;

        int main() {
          
         int arr[3] = { 178, 20,10 };
         int arr2[3] = { 8, 240,10  };
         int arr3[3] = { 88, 22,10  };

         int** elements =  new int*[3];
         
         elements[0]= arr;
         elements[1]= arr2;

         elements[2]= arr3;

        matrix<int> mymatrix3 = matrix<int>(elements,3 ,3);
        
        
        
        std::cout << "The  determinant s  " << mymatrix3.det() << std::endl;

       

         return 0;
          
    }
        
        //[[Rcpp::export]]
    Rcpp::IntegerVector mdet() {
      return main();
    }

    det(as.matrix(cbind(c(178, 20,10), c(8, 240,10), c(88, 22,10))))

    ## [1] 194600

    mdet()

    ## integer(0)
