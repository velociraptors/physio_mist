/*
The contents of this file are subject to the GiPSi Public License
Version 1.0 (the "License"); you may not use this file except in
compliance with the License. You may obtain a copy of the License at
http://gipsi.case.edu/GiPSiPL/

Software distributed under the License is distributed on an "AS IS"
basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
License for the specific language governing rights and limitations
under the License.

The Original Code is GiPSi Vector Class Header (vector.h).

The Initial Developers of the Original Code are Tolga Goktekin and M. Cenk Cavusoglu.  
Portions created by Tolga Goktekin and M. Cenk Cavusoglu are Copyright (C) 2004.
All Rights Reserved.

Contributor(s): Tolga Goktekin, M. Cenk Cavusoglu.
*/

////	VECTOR.H v0.1.0
////
////	Header for Vector
////
////////////////////////////////////////////////////////////////


#ifndef _CVECTOR_H
#define _CVECTOR_H

#include "algebra.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

// General N dimensional Vector Template Forward Declaration
template<class T> class Vector;

// Vector-Vector Copy
template<class T> void		copyVV(Vector<T> &result, const Vector<T> &v);
// Vector-Array Copy
template<class T> void		copyVA(Vector<T> &result, const T a[]);

// Vector-Scalar Multiply
template<class T> Vector<T>	operator*(const Vector<T> &v, const T &s);
template<class T> Vector<T>	operator*(const T &s, const Vector<T> &v);

// Vector-Scalar Divide
template<class T> Vector<T>	operator/(const Vector<T> &v, const T &s);

// Vector Scale
template<class T> void		scalVS(Vector<T> &result, const T &s);

// Vector-Vector Add
template<class T> Vector<T>	operator+(const Vector<T> &v1, const Vector<T> &v2);
template<class T> void		addVV(Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);

// Vector-Vector Sub
template<class T> Vector<T>	operator-(const Vector<T> &v1, const Vector<T> &v2);
template<class T> void		subVV(Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);

// General BLAS ?axpy function
template<class T> Vector<T> axpy(const int n, const T alpha, const Vector<T> &X, const int incX, Vector<T> &Y, const int incY);

// Dot Product
template<class T> T			operator*(const Vector<T> &v1, const Vector<T> &v2);
template<class T> T			dotVV(const Vector<T> &v1, const Vector<T> &v2);

// Cross Product (only for 3D vectors)
template<class T> void		crossVV(Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);

// Logical Operators
template<class T> bool		operator==(const Vector<T> &v1, const Vector<T> &v2);
template<class T> bool		operator!=(const Vector<T> &v1, const Vector<T> &v2);

// General N dimensional Vector Template
template <class T> 
class Vector {
public:
// Constructors
	Vector() : data(NULL), _dim(0), _ref(false) {}
    Vector(int dim) : _ref(false) {
		this->init(dim);
	}
	// Reference constructor
    Vector(int dim, T *r, int ref = 0) : _ref(ref) {
		if(!ref) {
			this->init(dim);
			copyVA((*this), r);
		} else {
			data = r;
			_dim = dim;
		}
	}
	// Copy constructor
	Vector(const Vector<T> &v) :   _ref(false) {
		this->init(v.dim());
		(*this) = v;
	}

	Vector(int dim, const T val) : _ref(false) {
		this->init(dim);
		(*this) = val;
	}

	Vector(int dim, char *valstr): _ref(false) {
		std::istringstream vin(valstr);
		
		this->init(dim);

		for(int i = 0; i < dim; i++)
			vin >> data[i];
	}

// Destructor
	~Vector<T>() {
		// Destroy data only if this is not a reference
		if(!_ref)
			if (data != NULL) delete[] data; 
		data = NULL;
	}


// Remapping reference and empty vectors
	void remap(int dim, T *r) {
		// Remap only works for reference vectors and empty vectors.
		// Use copyVV or = operator to initialize a default vector.
		if((_ref) || (this->empty())) {	
			data = r;
			_dim = dim;
			_ref = true;
		}
	}

// CResize clears the old values.
	void cresize(int new_dim) {
		if(!this->empty()) {
			delete[] data;
			_dim = 0;
		}

		this->init(new_dim);
	}

// Access Operators
    T&	operator[](unsigned int i) const	{ 
#ifdef ALGEBRA_DEBUG
		ASSERT(i >= 0 && i<_dim);
#endif
		return data[i]; 
	}

    T&	operator[](unsigned int i)			{ 
#ifdef ALGEBRA_DEBUG
		ASSERT(i >= 0 && i<_dim);
#endif
		return data[i]; 
	}

// Assignment Operators
	void operator=(const Vector<T> &v);
	void operator=(const T &s);
	void operator=(const T a[]);

// Fast Lvalue Vector-Scalar Operators
    void operator*=(const T &s);		// Mult
    void operator/=(const T &s);		// Div

// Fast Lvalue Vector-Vector Operators
    void operator+=(const Vector<T> &v);		// Add
    void operator-=(const Vector<T> &v);		// Sub

// Norm functions
    double			length_sq();		// Length square (L2 norm square)
    double			length();		// Length (L2 norm)
    double			normalize();		// Normalization

// IO functions
	int				load(const char *filename);
	int				save(const char *filename);
	int				loadb(const char *filename);
	int				saveb(const char *filename);

// Query functions
	unsigned int	dim()	const { return _dim; }
	unsigned int	size()	const { return _dim; }
	int				ref()	const { return _ref; }
	T*				begin() const { return data; }
	T*				end()	const { return data + _dim; }
	bool			empty() const { return (data == NULL && _dim == 0); }

protected:
	T				*data;		// Component array
	unsigned int	_dim;		// Dimension (size) of the vector
	int				_ref;		// True if this is a reference

	void init(int dim) {
		data = new T[dim];

		_dim = dim;
	}

	//#if defined(_MSC_VER) && _MSC_VER <= 1200
#if 1
	friend void		copyVV<T>(Vector<T> &result, const Vector<T> &v);
	friend void		copyVA<T>(Vector<T> &result, const T a[]);
	friend void		scalVS<T>(Vector<T> &result, const T &s);
	friend void		addVV<T> (Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);
	friend void		subVV<T> (Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);
	friend T		dotVV<T> (const Vector<T> &v1, const Vector<T> &v2);
#else
	friend void		copyVV<>(Vector<T> &result, const Vector<T> &v);
	friend void		copyVA<>(Vector<T> &result, const T a[]);
	friend void		scalVS<>(Vector<T> &result, const T &s);
	friend void		addVV<> (Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);
	friend void		subVV<> (Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2);
	friend T		dotVV<> (const Vector<T> &v1, const Vector<T> &v2);
#endif
};
	
template <>
double Vector<float>::length(void); 
template <>
double Vector<double>::length(void); 
template <>
double Vector<float>::length_sq(void); 
template <>
double Vector<double>::length_sq(void); 

// Vector-Vector Copy Operator
template<class T>
inline void Vector<T>::operator=(const Vector<T> &v)
{
	copyVV((*this), v);
}

// Vector-Scalar Copy Operator
template<class T>
inline void Vector<T>::operator=(const T &s)
{
	T		*tdata;

	tdata	= data;

	for(int i=_dim; i; i--)
		*(tdata++) = s;
}

// Vector-Array Copy Operator
template<class T>
inline void Vector<T>::operator=(const T a[])
{
	copyVA((*this), a);
}

// Vector-Scalar Multiply Operators
template<class T>
inline void Vector<T>::operator*=(const T &s)
{
	scalVS((*this), s);
}

template<class T>
inline Vector<T> operator*(const Vector<T> &v, const T &s)
{
	Vector<T>				r(v.dim());
	static unsigned int		dim;
	T						*rdata, *vdata;

	dim		= r.dim();
	rdata	= r.begin();
	vdata	= v.begin();

	for(unsigned int i = dim; i; i--)
		*(rdata++) = *(vdata++) * s;

    return r;
}

template<class T>
inline Vector<T> operator*(const T &s, const Vector<T> &v)
{
	Vector<T>				r(v.dim());
	static unsigned int		dim;
	T						*rdata, *vdata;

	dim		= r.dim();
	rdata	= r.begin();
	vdata	= v.begin();

	for(unsigned int i = dim; i; i--)
		*(rdata++) = *(vdata++) * s;

    return r;
}

// Vector-Scalar Divide Operators
template<class T>
inline void Vector<T>::operator/=(const T &s)
{
#ifdef ALGEBRA_DEBUG

	ASSERT( s != 0.0);

#endif

	scalVS((*this), 1/s);
}

template<class T>
inline Vector<T> operator/(const Vector<T> &v, const T &s)
{
	Vector<T>				r(v.dim());
	static unsigned int		dim;
	T						*rdata, *vdata;

	dim		= r.dim();
	rdata	= r.begin();
	vdata	= v.begin();

#ifdef ALGEBRA_DEBUG

	ASSERT( s != 0.0);

#endif

	for(unsigned int i = dim; i; i--)
		*(rdata++) = *(vdata++) / s;

    return r;
}

// Vector-Vector Add Operators
template<class T>
inline void Vector<T>::operator+=(const Vector<T> &v)
{
	addVV((*this), (*this), v);
}

template<class T>
inline Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2)
{
	Vector<T> r(v1.dim());

	addVV(r, v1, v2);
	
	return r;
}

// Vector-Vector Subtract Operators
template<class T>
inline void Vector<T>::operator-=(const Vector<T> &v)
{
	subVV((*this), (*this), v);
}

template<class T>
inline Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2)
{
	Vector<T> r(v1.dim());

	subVV(r, v1, v2);

	return r;
}

// Dot Product Operator
template<class T>
inline T operator*(const Vector<T> &v1, const Vector<T> &v2)
{
	return dotVV(v1, v2);
}

// Logical Operators
template<class T>
inline bool operator==(const Vector<T> &v1, const Vector<T> &v2)
{
	T				*v1data, *v2data;
	unsigned int	dim;

	dim		= v1.dim;
	v1data	= v1.begin();
	v2data	= v2.begin();

#ifdef ALGEBRA_DEBUG

	ASSERT(v1.dim() == v2.dim());

#endif

	for(unsigned int i = dim; i; i--)
		if (*(v1data++) != *(v2data++)) return false;

	return true;
}

template<class T>
inline bool operator!=(const Vector<T> &v1, const Vector<T> &v2)
{
	T				*v1data, *v2data;
	unsigned int	dim;

	dim		= v1.dim;
	v1data	= v1.begin();
	v2data	= v2.begin();

#ifdef ALGEBRA_DEBUG

	ASSERT(v1.dim() == v2.dim());

#endif

	for(unsigned int i = dim; i; i--)
		if (*(v1data++) == *(v2data++)) return false;

	return true;
}


template<class T>
inline Real Vector<T>::normalize()
{
	Real l = length();
  
	if(!l) return l;
  
	scalVS((*this), 1.0/l);

	for(unsigned int i = 0; i < _dim; i++) {
		if (fabs(data[i]) < EPSILON)
			data[i] = 0.0;
	}
    
	return l;
}

template<class T>
inline void crossVV(Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2)
{  
	// This only works for 3D Vectors
	if(v1.dim() == 3 && v2.dim() == 3 && result.dim() == 3) {	
		result[0] = v1[1] * v2[2] - v1[2] * v2[1];
		result[1] = v1[2] * v2[0] - v1[0] * v2[2];
		result[2] = v1[0] * v2[1] - v1[1] * v2[0];
	} else if(v1.dim() == 2 && v2.dim() == 2 && result.dim() == 3) {
		result[0] = 0.0;
		result[1] = 0.0;
		result[2] = v1[0] * v2[1] - v1[1] * v2[0];
	} else ASSERT(0);
}


template<class T>
int Vector<T>::load(const char *filename) {
	FILE	*fp;

	// Save position info
	if((fp = fopen(filename, "r")) == NULL) {
		printf("Cannot open output file!\n");
		return false;
	}
	
	for(int i=0; i<_dim; i++) {
		fscanf(fp, "%lf\n", &data[i]);
	}

	fclose(fp);

	return true;
}


template<class T>
int Vector<T>::loadb(const char *filename) {
	FILE	*fp;

	// Save position info
	if((fp = fopen(filename, "rb")) == NULL) {
		printf("Cannot open output file!\n");
		return false;
	}
	
	for(int i=0; i<_dim; i++) {
		fread(&data[i], sizeof(data[i]), 1, fp);
	}

	fclose(fp);

	return true;
}


template<class T>
int Vector<T>::saveb(const char *filename) {
	FILE	*fp;

	// Save position info
	if((fp = fopen(filename, "wb")) == NULL) {
		printf("Cannot open output file!\n");
		return false;
	}
	
	for(int i=0; i<_dim; i++) {
		fwrite(&data[i], sizeof(data[i]), 1, fp);
	}

	fclose(fp);

	return true;
}


template<class T>
int Vector<T>::save(const char *filename) {
	FILE	*fp;

	// Save position info
	if((fp = fopen(filename, "w")) == NULL) {
		printf("Cannot open output file!\n");
		return false;
	}
	
	for(int i=0; i<_dim; i++) {
		fprintf(fp, "%.14lf\n", data[i]);
	}

	fclose(fp);

	return true;
}


#ifdef ALGEBRA_USE_GENERAL
//
// GENERAL implementations
//
template<class T> 
inline void copyVV(Vector<T> &result, const Vector<T> &v) 
{
	static unsigned int dim;

	if (result.empty()) {
		result.init(v.dim());
	}
	dim = result.dim();

#ifdef ALGEBRA_DEBUG

	ASSERT( dim <= v.dim() );

#endif

	if(dim <= 4)
		for(unsigned int i = 0; i < dim; i++)
			result[i] = v[i];
	else
		// NOTE: The below pays off for large vectors
		memcpy(result.begin(), v.begin(), dim * sizeof(T));
}


// Vector-Array Copy
template<class T> 
inline void copyVA(Vector<T> &result, const T a[]) 
{
	static unsigned int dim;

	dim = result.dim(); 

	if(dim <= 4)
		for(unsigned int i = 0; i < dim; i++)
			result[i] = a[i];
	else
		// NOTE: The below pays off for large vectors
//		memmove(result.begin(), a, dim * sizeof(T));
		memcpy(result.begin(), a, dim * sizeof(T));
}


// Vector-Scalar Product
template<class T> 
inline void scalVS(Vector<T> &result, const T &s) 
{
	T						*rdata;
	static unsigned int		dim;

	dim		= result.dim();
	rdata	= result.begin();

	for(unsigned int i = dim; i; i--)
		*(rdata++) *= s;

}


// Vector Addition
template<class T>
inline void addVV(Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2)
{
	T						*rdata, *v1data, *v2data;
	static unsigned int		dim;

	dim		= result.dim();
	rdata	= result.begin();
	v1data	= v1.begin();
	v2data	= v2.begin();

	
#ifdef ALGEBRA_DEBUG

	ASSERT(dim == v1.dim() && dim == v2.dim());

#endif

	// result = v1 + v2
	for(unsigned int i = dim; i; i--)
		*(rdata++) = *(v1data++) + *(v2data++);
}


// Vector Subtraction
template<class T>
inline void subVV(Vector<T> &result, const Vector<T> &v1, const Vector<T> &v2)
{
	T						*rdata, *v1data, *v2data;
	static unsigned int		dim;

	dim		= result.dim();
	rdata	= result.begin();
	v1data	= v1.begin();
	v2data	= v2.begin();

#ifdef ALGEBRA_DEBUG

	ASSERT(dim == v1.dim() && dim == v2.dim());
	
#endif

	// result = v1 - v2
	for(unsigned int i = dim; i; i--)
		*(rdata++) = *(v1data++) - *(v2data++);
}


// Vector Dot Product
template<class T>
inline T dotVV(const Vector<T> &v1, const Vector<T> &v2)
{
	T						*v1data, *v2data;
	static unsigned int		dim;

	dim		= v1.dim();
	v1data	= v1.begin();
	v2data	= v2.begin();

#ifdef ALGEBRA_DEBUG
	
	ASSERT(dim == v2.dim());

#endif

	T sp = 0.0;

	for(unsigned int i = dim; i; i--)
		sp += (*(v1data++)) * (*(v2data++));

    return sp;
}

template<class T>
inline Real Vector<T>::length_sq()
{
	return dotVV((*this), (*this));
}

template<class T>
inline Real Vector<T>::length()
{
	return sqrt(length_sq());
}
#endif

// Constant vector definitions
const Vector<Real>	zero_vector2(2, 0.0);
const Vector<Real>	zero_vector3(3, 0.0);

#endif
