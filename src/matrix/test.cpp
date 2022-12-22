#include <Rcpp.h>
#include <matrix.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
int mCreateTest()
{
  matrix<int> mymatrix = matrix<int>();
  std::cout << "The number of elements in mymatrix is " << mymatrix.m_nElements << std::endl;

  matrix<int> mymatrix2 = matrix<int>(1000,1000);
  std::cout << "The number of elements in mymatrix2 is " << mymatrix2.m_nElements << std::endl;
  delete &mymatrix2.m_elements;
  delete &mymatrix2;
  
  return 0;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
tail(mCreateTest())

*/

