/*
The contents of this file are subject to the GiPSi Public License
Version 1.0 (the "License"); you may not use this file except in
compliance with the License. You may obtain a copy of the License at
http://gipsi.case.edu/GiPSiPL/

Software distributed under the License is distributed on an "AS IS"
basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
License for the specific language governing rights and limitations
under the License.

The Original Code is GiPSi Matrix Class Header (matrix.h).

The Initial Developers of the Original Code are Tolga Goktekin and M. Cenk Cavusoglu.  
Portions created by Tolga Goktekin and M. Cenk Cavusoglu are Copyright (C) 2004.
All Rights Reserved.

Contributor(s): Tolga Goktekin, M. Cenk Cavusoglu.
*/

////	MATRIX.H v0.0.9
////
////	Header for Matrix
////
////////////////////////////////////////////////////////////////


#ifndef _MATRIX_H
#define _MATRIX_H

#include "algebra.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

// General MxN dimensional Matrix Template Forward Declaration
template<class T> class Matrix; 

// Matrix-Matrix Copy
template<class T> void		copyMM(Matrix<T> &result, const Matrix<T> &a);
// Matrix-Array Copy
template<class T> void		copyMA(Matrix<T> &result, const T a[]);

// Matrix-Scalar Multiply
template<class T> Matrix<T>	operator*(const Matrix<T> &a, const T &s);
template<class T> Matrix<T>	operator*(const T &s, const Matrix<T> &a);

// Matrix-Scalar Divide
template<class T> Matrix<T>	operator/(const Matrix<T> &a, const T &s);

// Matrix Scale
template<class T> void		scalMS(Matrix<T> &result, const T &s);

// Matrix-Vector Multiply
template<class T> void		multMV(Vector<T> &result, const Matrix<T> &a, const Vector<T> &v);
template<class T> Vector<T>	operator*(const Matrix<T> &a, const Vector<T> &v);

// Matrix-Matrix Add
template<class T> Matrix<T>	operator+(const Matrix<T> &v1, const Matrix<T> &v2);
template<class T> void		addMM(Matrix<T> &result, const Matrix<T> &a1, const Matrix<T> &a2);

// Matrix-Matrix Sub
template<class T> Matrix<T>	operator-(const Matrix<T> &a1, const Matrix<T> &a2);
template<class T> void		subMM(Matrix<T> &result, const Matrix<T> &a1, const Matrix<T> &a2);

// General BLAS ?axpy function
// template<class T> Matrix<T> axpy(const int n, const T alpha, const Matrix<T> &X, const int incX, Matrix<T> &Y, const int incY);

// Matrix-Matrix Multiply
template<class T> Matrix<T>	operator*(const Matrix<T> &a1, const Matrix<T> &a2);
template<class T> void		multMM(Matrix<T> &result, const Matrix<T> &a1, const Matrix<T> &a2);

// Logical Operators
template<class T> bool		operator==(const Matrix<T> &a1, const Matrix<T> &a2);
template<class T> bool		operator!=(const Matrix<T> &a1, const Matrix<T> &a2);

// Higher level Matrix operations
template<class T> void		transposeM(Matrix<T> &result, const Matrix<T> &M);
template<class T> int		invM(Matrix<T> &result, const Matrix<T> &M);
template<class T> int		pinvM(Matrix<T> &result, const Matrix<T> &M);
template<class T> T			traceM(const Matrix<T> &M);


// General MxN dimensional Matrix Template
template <class T> 
class Matrix {
public:
// Constructors
	Matrix() : data(NULL), _m(0), _n(0) {}
    
	Matrix(int m, int n) {
		this->init(m, n);
	}
    
	Matrix(int m, int n, T *r) {
		this->init(m, n);
		copyMA((*this), r);
	}

	// Copy constructor
	Matrix(const Matrix<T> &a) {
		this->init(a.m(), a.n());
		(*this) = a;
	}

	Matrix(int m, int n, const T val) {
		this->init(m, n);
		(*this) = val;
	}

	Matrix(int m, int n, char *valstr) {
		std::istringstream vin(valstr);
		
		this->init(m, n);

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				vin >> (*this)[i][j];
	}

// Destructor
	~Matrix<T>() {
		if (data != NULL) delete[] data; 
		data = NULL;
	}

// Access Operators
	T*	operator[](unsigned int i) const	{ return data + _n*i; }
    T*	operator[](unsigned int i)			{ return data + _n*i; }

// Assignment Operators
	void operator=(const Matrix<T> &a);
	void operator=(const T &s);
	void operator=(const T a[]);

// Fast Lvalue Matrix-Scalar Operators
    void operator*=(const T &s);		// Mult
    void operator/=(const T &s);		// Div

// Fast Lvalue Matrix-Matrix Operators
	void operator*=(const Matrix<T> &a);
    void operator+=(const Matrix<T> &a);		// Add
    void operator-=(const Matrix<T> &a);		// Sub

// Norm functions
    

// Extracting Columns and Rows
	Vector<T>	column(int i);
	Vector<T>	row(int i);

// In place higher level operations
	void		transpose();

// IO functions
	int			load(const char *filename);
	int			save(const char *filename);

// Query functions
	unsigned int	m()		const { return _m; }
	unsigned int	n()		const { return _n; }
	unsigned int	size()	const { return _m * _n; }
	T*				begin() const { return data; }
	T*				end()	const { return data + _m * _n; }
	bool			empty() const { return (data == NULL && _m == 0 && _n == 0); }

protected:
	T				*data;		// Component array
	unsigned int	_m, _n;		// Dimensions of the matrix

	void init(int m, int n) {
		data = new T[m * n];

		_m = m;
		_n = n;
	}

#if defined(_MSC_VER) && _MSC_VER <= 1200
	friend void		copyMM<T>(Matrix<T> &result, const Matrix<T> &a);
	friend void		copyMA<T>(Matrix<T> &result, const T a[]);
#else
	friend void		copyMM<>(Matrix<T> &result, const Matrix<T> &a);
	friend void		copyMA<>(Matrix<T> &result, const T a[]);
#endif
};	



// Matrix-Matrix Copy Operator
template<class T>
inline void Matrix<T>::operator=(const Matrix<T> &a)
{
	copyMM((*this), a);
}

// Matrix-Scalar Copy Operator
template<class T>
inline void Matrix<T>::operator=(const T &s)
{
	for(unsigned int i=0; i<_m*_n; i++)
		data[i] = s;
}

// Matrix-Array Copy Operator
template<class T>
inline void Matrix<T>::operator=(const T a[])
{
	copyMA((*this), a);
}

// Matrix-Scalar Multiply Operators
template<class T>
inline void Matrix<T>::operator*=(const T &s)
{
	scalMS((*this), s);
}

template<class T>
inline Matrix<T> operator*(const Matrix<T> &a, const T &s)
{
	Matrix<T> r(a);

	scalMS(r, s);

    return r;
}

template<class T>
inline Matrix<T> operator*(const T &s, const Matrix<T> &a)
{
	Matrix<T> r(a);

	scalMS(r, s);

    return r;
}

// Matrix-Scalar Divide Operators
template<class T>
inline void Matrix<T>::operator/=(const T &s)
{
	ASSERT( s != 0.0);

	scalMS((*this), 1.0/s);
}

template<class T>
inline Matrix<T> operator/(const Matrix<T> &a, const T &s)
{
	Matrix<T> r(a);

	ASSERT( s != 0.0);

	scalMS(r, s);

    return r;
}

// Matrix-Vector Multiply
template<class T> 
inline Vector<T> operator*(const Matrix<T> &a, const Vector<T> &v)
{
	Vector<Real> r(a.m());

	multMV(r, a, v);

	return r;
}

// Matrix-Matrix Add Operators
template<class T>
inline void Matrix<T>::operator+=(const Matrix<T> &a)
{
	addMM((*this), (*this), a);
}

template<class T>
inline Matrix<T> operator+(const Matrix<T> &a1, const Matrix<T> &a2)
{
	Matrix<T> r(a1.m(), a1.n());

	addMM(r, a1, a2);
	
	return r;
}

// Matrix-Matrix Subtract Operators
template<class T>
inline void Matrix<T>::operator-=(const Matrix<T> &a)
{
	subMM((*this), (*this), a);
}

template<class T>
inline Matrix<T> operator-(const Matrix<T> &a1, const Matrix<T> &a2)
{
	Matrix<T> r(a1.m(), a1.n());

	subMM(r, a1, a2);
	
	return r;
}

// Matrix-Matrix Product Operator
template<class T>
inline Matrix<T> operator*(const Matrix<T> &a1, const Matrix<T> &a2)
{
	Matrix<T> r(a1.m(), a2.n());

	multMM(r, a1, a2);
	
	return r;
}

// Logical Operators
template<class T>
inline bool operator==(const Matrix<T> &v1, const Matrix<T> &v2)
{
	ASSERT(v1.m() == v2.m() && v1.n() == v2.n());

	for(unsigned int i = 0; i < v1.m(); i++)
		for(unsigned int j = 0; j < v1.n(); j++)
			if (v1[i][j] != v2[i][j]) return false;

	return true;
}

template<class T>
inline bool operator!=(const Matrix<T> &v1, const Matrix<T> &v2)
{
	ASSERT(v1.m() == v2.m() && v1.n() == v2.n());

	for(unsigned int i = 0; i < v1.m(); i++)
		for(unsigned int j = 0; j < v1.n(); j++)
			if (v1[i][j] == v2[i][j]) return false;

	return true;
}

template<class T>
inline	Vector<T>	Matrix<T>::column(int i) 
{
	Vector<T>	result(_m, 0.0);
	Matrix<T>&	M = (*this);

	for(int j=0; j<_m; j++)	result[j] = M[j][i];

	return result;
}

template<class T>
inline Vector<T>	Matrix<T>::row(int	i)
{
	Vector<T>	result(_n, 0.0);
	Matrix<T>	&M = (*this);

	for(int j=0; j<_n; j++)	result[j] = M[i][j];

	return result;
}



template<class T> 
inline void copyMM(Matrix<T> &result, const Matrix<T> &a) 
{
	static unsigned int m, n;

	if (result.empty()) {
		result.init(a.m(), a.n());
	}

	m = result.m();
	n = result.n();

	ASSERT( m <= a.m() && n <= a.n() );

	if(m <= 4 && n <= 4)
		for(unsigned int i = 0; i < m; i++)
			for(unsigned int j = 0; j < n; j++)
				result[i][j] = a[i][j];
	else
		// NOTE: The below pays off for large Matrices
		memmove(result.begin(), a.begin(), m * n * sizeof(T));
}

template<class T> 
inline void copyMA(Matrix<T> &result, const T a[]) 
{
	static unsigned int m, n;

	m = result.m();
	n = result.n();

	if(m <= 4 && n <= 4)
		for(unsigned int i = 0; i < m; i++)
			for(unsigned int j = 0; j < n; j++)
				result[i][j] = a[i*m+j];
	else
		// NOTE: The below pays off for large Matrixs
		memmove(result.begin(), a, m * n * sizeof(T));
}

template<class T> 
inline void scalMS(Matrix<T> &result, const T &s) 
{
	static unsigned int m, n;

	m = result.m();
	n = result.n();
	
	for(unsigned int i = 0; i < m; i++)
			for(unsigned int j = 0; j < n; j++)
				result[i][j] *= s;
}


template<class T>
inline void addMM(Matrix<T> &result, const Matrix<T> &a1, const Matrix<T> &a2)
{
	static unsigned int m, n;

	m = result.m();
	n = result.n();
	
	ASSERT(m == a1.m() && n == a1.n() && m == a2.m() && n == a2.n());

	// result = a1 + a2
	for(unsigned int i = 0; i < m; i++)
			for(unsigned int j = 0; j < n; j++)
				result[i][j] = a1[i][j] + a2[i][j];
}


template<class T>
inline void subMM(Matrix<T> &result, const Matrix<T> &a1, const Matrix<T> &a2)
{
	static unsigned int m, n;

	m = result.m();
	n = result.n();
	
	ASSERT(m == a1.m() && n == a1.n() && m == a2.m() && n == a2.n());

	// result = a1 - a2
	for(unsigned int i = 0; i < m; i++)
		for(unsigned int j = 0; j < n; j++)
			result[i][j] = a1[i][j] - a2[i][j];
}


#ifdef ALGEBRA_USE_GENERAL
// GENERAL implementations
//


template<class T> 
inline void multMV(Vector<T> &result, const Matrix<T> &a, const Vector<T> &v)
{
	ASSERT(a.n() == v.dim());

	for(unsigned int i=0; i<a.m(); i++) {
		result[i] = 0.0;
		for(unsigned int j=0; j<a.n(); j++)
			result[i] += a[i][j] * v[j];
	}
}


template<class T>
inline void multMM(Matrix<T> &result, const Matrix<T> &a1, const Matrix<T> &a2)
{
	static unsigned int m, n, p;

	m = result.m();
	n = result.n();
	p = a1.n();

	ASSERT((a1.n() == a2.m()) && (m == a1.m() && n == a2.n()));
	
	for(unsigned int i = 0; i < m; i++)
		for(unsigned int j = 0; j < n; j++) {
			result[i][j] = 0.0;
			for(unsigned int k = 0; k < p; k++)
				result[i][j] += a1[i][k] * a2[k][j];
		}
}


#endif


template<class T> 
inline void transposeM(Matrix<T> &result, const Matrix<T> &M)
{
	unsigned int		i,j;
	
	ASSERT(result.m() == M.n() && result.n() == M.m());

	for(i=0; i<M.m(); i++)	
		for(j=0; j<M.n(); j++)
			result[j][i] = M[i][j];

}


template<class T>
inline void	Matrix<T>::transpose(void)
{
	Matrix<T>	temp((*this));

	transposeM((*this), temp);
}


template<class T> 
inline T traceM(const Matrix<T> &M)
{
	unsigned	int i;
	T			trace;
	
	trace = 0;

	for(i=0; i<M.m(); i++)	trace += M[i][i];

	return trace;
}




#endif

