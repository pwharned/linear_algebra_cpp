#include <Rcpp.h>
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
std::vector<int> FibCpp0(int n)
{
  // Error checking
  if(n <= 0)
  {
    throw std::range_error("n must be a positive integer");
  }
  
  // Allocate memory
  std::vector<int> out(n);
  out[0]=1;
  
  // Compute additional terms
  if(n > 0)
  {
    out[1]=1;
    int i;
    for(i=2; i<n; i++)
    {
      out[i] = out[i-1] + out[i-2];
    }
  }
  
  return out;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
tail(FibCpp0(30))

*/

