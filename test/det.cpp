  
    #include "/Users/pat/Projects/linear_algebra_cpp/src/matrix/matrix.h"
    
    int main() {
      
     int arr[6] = { 10, 20,  };
     int arr2[6] = { 10, 20,  };

     int** elements =  new int*[2];
     
     elements[0]= arr;
     elements[1]= arr;
     
     
    matrix<int> mymatrix3 = matrix<int>(elements);
    
    int det = mymatrix3.det();
      std::cout << "The determinant of the matrix is " << det << std::endl;
    
     return 0;
      
}
