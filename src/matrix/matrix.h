#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#define MSIZEOF(arr) sizeof(*arr) / sizeof(**arr)
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)
#define ARRSIZEOF(arr) *(&arr + 1) - arr;

template <class T>
class matrix
{
public:
  matrix();
  matrix(int nRows, int nCols);
  matrix(T** elements,int nRows, int nCols);
  
  void print();
  int det();

  ~matrix();
  
  int m_nRows;
  int m_nCols;
  int m_nElements;
  T** m_elements;

  T* operator[] (int n){

    if(n>m_nCols-1){
      std::cout << "Index " << n << " exceeds the number of matrix elements " << m_nCols << std::endl; 
      return m_elements[0];

    }
    else return m_elements[n];
    
  };
  
  template <class U> friend matrix<U> operator+ (matrix<U>& operand);
  
  
};

template <class T>
matrix<T>::matrix()
{
  m_nRows = 1;
  m_nCols = 1;
  m_nElements = m_nRows*m_nCols;
  m_elements = new T*[m_nElements]; //declare a memory block
  for(int i=0; i<m_nRows; i++){
        m_elements[i] = new T[m_nCols];
        for (int j=0; j<m_nCols; j++){
          m_elements[i][j]=0.0+j;
        }
  }
}

template <class T>
matrix<T>::matrix(T** elements, int nCols, int nRows){
  

  m_nRows = nRows;
  m_nCols = nCols;
  std::cout << "The number of rows in the matrix is " << m_nRows << "\n" << std::endl;
  std::cout << "The number of columns in the matrix is " << m_nCols << "\n" << std::endl;
  
  m_elements = new T*[nCols];
  
  for(int i=0;i<nCols; i++){
    m_elements[i] = elements[i];
  }
  
}
  
template <class T>
matrix<T>::matrix(int nRows, int nCols)
{
  m_nRows = nRows;
  m_nCols = nCols;
  m_nElements = nRows*nCols;
  m_elements = new T*[m_nElements];
  
  for(int i=0; i<m_nRows; i++){
        m_elements[i] = new T[m_nCols];
        for (int j=0; j<m_nCols; j++){
          m_elements[i][j]=0.0+j;
        }
  }
 

}

template <class T>
matrix<T>::~matrix()
{

//  std::cout << "Destructing" << std::endl;
  if(m_elements!=nullptr)
  delete [] m_elements;
}


template <class T>
void matrix<T>::print()
{
  for(int i = 0; i < m_nRows; i++ ){
    
    for(int j = 0; j < m_nCols; j++){
      
      if(j==m_nCols-1){
        std::cout << m_elements[j][i] << std::endl;
        
      } else{
        
        std::cout  << m_elements[j][i] << " | ";
        
      }
    }
    
  }
}

template <class T>
int matrix<T>::det()
{
  int det = 0;
  

  if(m_nRows!=m_nCols){
    std::cout << "The determinant is not defined for non-square matrices" << std::endl;
    return 0;
  }

  matrix<int> submatrix = matrix<int>(m_nRows-1, m_nCols-1);
  if (m_nRows == 2){

    
    det = ((m_elements[0][0] * m_elements[1][1]) - (m_elements[1][0] * m_elements[0][1]));

    return det;
  }
 
  else {
    for (int x = 0; x < m_nRows; x++) {
      int subi = 0;
      for (int i = 1; i < m_nRows; i++) {
        int subj = 0;
        for (int j = 0; j < m_nRows; j++) {
          if (j == x)
            continue;

          submatrix[subi][subj] = m_elements[i][j];
          subj++;
        }
        subi++;
      }
      det = det + (pow(-1, x) * m_elements[0][x] * submatrix.det() );
    }
  }

  return det;
}


#endif
