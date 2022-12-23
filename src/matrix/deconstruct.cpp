#include "matrix.h"
#include <iostream>

int main()
{
  matrix<int> mymatrix = matrix<int>();
  std::cout << "The number of elements in mymatrix is " << mymatrix.m_nElements << std::endl;

  matrix<int> mymatrix2 = matrix<int>(1000,1000);
  std::cout << "The number of elements in mymatrix2 is " << mymatrix2.m_nElements << std::endl;
  
  return 0;
}
