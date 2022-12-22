#ifndef MATRIX_H
#define MATRIX_H

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
  T *m_elements;
};

template <class T>
matrix<T>::matrix()
{
  m_nRows = 1;
  m_nCols = 1;
  m_nElements = 1;
  m_elements = new T[m_nElements];
  m_elements[0] = 0.0;
}

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

template <class T>
matrix<T>::~matrix()
{

    //delete[] m_elements;
  
}

#endif