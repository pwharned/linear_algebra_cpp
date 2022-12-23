#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
template <class T>
class matrix
{
public:
  matrix();
  matrix(int nRows, int nCols);
  
  ~matrix();
  
  int m_nRows;
  int m_nCols;
  int m_nElements;
  T** m_elements;
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
          m_elements[i][j]=0.0;
        }
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
          m_elements[i][j]=0.0;
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

#endif
