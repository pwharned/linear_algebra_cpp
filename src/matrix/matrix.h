#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#define MSIZEOF(arr) sizeof(*arr) / sizeof(**arr)
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

template <class T>
class matrix
{
public:
  matrix();
  matrix(int nRows, int nCols);
  matrix(T** elements);
  
  void print();
  
  ~matrix();
  
  int m_nRows;
  int m_nCols;
  int m_nElements;
  T** m_elements;

  T* operator[] (int n){

    if(n>m_nRows){
      std::cout << "Index " << n << " exceeds the number of matrix elements " << m_nElements << std::endl; 
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
matrix<T>::matrix(T** elements){
  
  int size = MSIZEOF(elements);
  
  m_nCols = size;
  
  m_nRows = sizeof(elements[0][0]);
  
  std::cout << "The size of the elements array is " << size << std::endl;

  m_elements = new T*[m_nCols];
  
  for(int i=0;i<m_nCols; i++){
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
  for(int i = 0; i < m_nCols; i++ ){
    
    for(int j = 0; j < m_nRows; j++){
      
      std::cout  << m_elements[i][j] << " | ";
      
      if(j==m_nRows-1){
        std::cout << std::endl;
        
      }
      
    }
    
  }
}


#endif
