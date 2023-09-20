#include "../matrix/matrix.h"
#include <iostream>
#include <Rcpp.h>
using namespace Rcpp;
#define MSIZEOF(arr) sizeof(*arr) / sizeof(**arr)
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

// [[Rcpp::export]]

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
 
 
 int arr[4] = { 10, 20, 30, 40 };
 int arr2[4] = { 50, 60, 70, 80 };
 

 int** elements =  new int*[2];
 
 elements[0]= arr;
 elements[1]= arr2;
 
 
 
matrix<int> mymatrix3 = matrix<int>(elements);

std::cout << "The first element of the matrix3 matrix is " << mymatrix3.m_elements[1][1] << std::endl;

std::cout << "The number of rows is  " << mymatrix3.m_nRows << std::endl;


mymatrix3.print();

 return 0;

  
}

/*** R
main()

*/

