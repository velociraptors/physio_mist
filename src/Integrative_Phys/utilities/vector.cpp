/*
The contents of this file are subject to the GiPSi Public License
Version 1.0 (the "License"); you may not use this file except in
compliance with the License. You may obtain a copy of the License at
http://gipsi.case.edu/GiPSiPL/

Software distributed under the License is distributed on an "AS IS"
basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
License for the specific language governing rights and limitations
under the License.

The Original Code is GiPSi Vector Class Implementation (vector.cpp).

The Initial Developers of the Original Code are Tolga Goktekin and M. Cenk Cavusoglu.  
Portions created by Tolga Goktekin and M. Cenk Cavusoglu are Copyright (C) 2004.
All Rights Reserved.

Contributor(s): Tolga Goktekin, M. Cenk Cavusoglu.
*/

////	VECTOR.CPP v0.1.0
////
////	CBLAS wrapper for Vector. Implements BLAS Level 1.
////
////////////////////////////////////////////////////////////////


//#include "algebra.h"

#ifdef ALGEBRA_USE_MKL
#define USE_MATH_LIBS
#endif

#ifdef ALGEBRA_USE_ATLAS
#ifdef ALGEBRA_USE_CLAPACK
#define USE_MATH_LIBS
#endif
#endif

#ifdef USE_MATH_LIBS

// ?copy
template<>
void copyVV(Vector<float> &result, const Vector<float> &v)
{
	if (result.empty()) {
		result.init(v.dim());
	}

	ASSERT(result.dim() <= v.dim());

	cblas_scopy(result.dim(), v.begin(), 1, result.begin(), 1);
}

template<>
void copyVV(Vector<double> &result, const Vector<double> &v)
{
	if (result.empty()) {
		result.init(v.dim());
	}

	ASSERT(result.dim() <= v.dim());

	cblas_dcopy(result.dim(), v.begin(), 1, result.begin(), 1);
}

template<>
void copyVA(Vector<float> &result, const float a[])
{
	cblas_scopy(result.dim(), a, 1, result.begin(), 1);
}

template<>
void copyVA(Vector<double> &result, const double a[])
{
	cblas_dcopy(result.dim(), a, 1, result.begin(), 1);
}

// ?dot
template<>
float dotVV(const Vector<float> &v1, const Vector<float> &v2)
{
	ASSERT(v1.dim() == v2.dim());
	
	return cblas_sdot(v1.dim(), v1.begin(), 1, v2.begin(), 1);

}

template<>
double dotVV(const Vector<double> &v1, const Vector<double> &v2)
{
	ASSERT(v1.dim() == v2.dim());
	
	return cblas_ddot(v1.dim(), v1.begin(), 1, v2.begin(), 1);

}

// ?scal
template<>
void scalVS(Vector<float> &result, const float &s) 
{
	cblas_sscal(result.dim(), s, result.begin(), 1);
}

template<>
void scalVS(Vector<double> &result, const double &s) 
{
	cblas_dscal(result.dim(), s, result.begin(), 1);
}


// ?nrm2
template <>
double Vector<float>::length()
{
	return cblas_snrm2(_dim, data, 1);
}

template <>
double Vector<double>::length()
{
	return cblas_dnrm2(_dim, data, 1);
}

template <>
double Vector<float>::length_sq()
{
	return cblas_sdot(_dim, data, 1, data, 1);
}

template <>
double Vector<double>::length_sq()
{
	return cblas_ddot(_dim, data, 1, data, 1);
}


// ?axpy
template<>
void addVV(Vector<float> &result, const Vector<float> &v1, const Vector<float> &v2)
{
	ASSERT(result.dim() == v1.dim() && result.dim() == v2.dim());

	// AXPY:  Y = alpha * X + Y
	//
	// Thus we need first:	result = Y
	cblas_scopy(result.dim(), v1.begin(), 1, result.begin(), 1);

	// Then:	result = 1.0 * X + result
	cblas_saxpy(result.dim(), 1.0, v2.begin(), 1, result.begin(), 1);
}

template<>
void addVV(Vector<double> &result, const Vector<double> &v1, const Vector<double> &v2)
{
	ASSERT(result.dim() == v1.dim() && result.dim() == v2.dim());

	// AXPY:  Y = alpha * X + Y
	//
	// Thus we need first:	result = Y
	cblas_dcopy(result.dim(), v1.begin(), 1, result.begin(), 1);

	// Then:	result = 1.0 * X + result
	cblas_daxpy(result.dim(), 1.0, v2.begin(), 1, result.begin(), 1);
}

template<>
void subVV(Vector<float> &result, const Vector<float> &v1, const Vector<float> &v2)
{
	ASSERT(result.dim() == v1.dim() && result.dim() == v2.dim());

	// AXPY:  Y = alpha * X + Y
	//
	// Thus we need first:	result = Y
	cblas_scopy(result.dim(), v1.begin(), 1, result.begin(), 1);

	// Then:	result = -1.0 * X + result
	cblas_saxpy(result.dim(), -1.0, v2.begin(), 1, result.begin(), 1);
}

template<>
void subVV(Vector<double> &result, const Vector<double> &v1, const Vector<double> &v2)
{
	ASSERT(result.dim() == v1.dim() && result.dim() == v2.dim());

	// AXPY:  Y = alpha * X + Y
	//
	// Thus we need first:	result = Y
	cblas_dcopy(result.dim(), v1.begin(), 1, result.begin(), 1);

	// Then:	result = -1.0 * X + result
	cblas_daxpy(result.dim(), -1.0, v2.begin(), 1, result.begin(), 1);
}


#endif
