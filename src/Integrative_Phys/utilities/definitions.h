/**************************************************************************************************
  definitions.h

  Contributor(s): E. Zeynep Erson				  
  Created on:     December 2007
  Definition:	  Static definitions of constant values that are used throughout the progman
**************************************************************************************************/
#ifndef _DEFINITIONS_
#define _DEFINITIONS_

//ALGEBRAIC DEFINITIONS
#define ZERO 1e-16
#define EPSILON 1e-8
#define EMPTY_INITIAL_VALUE  numeric_limits<float>::infinity()

#define Continous 1
#define Discrete_time 2
#define Discrete_event 3

#define RK4 0
#define EULER 1

#define WHITE 0
#define GRAY  1
#define BLACK 2
#define RED	  3

#define FIXED_TIME		0
#define VARIABLE_TIME	1

#define	MAXLINEBUF	1024
#define MAX_PATH_LEN	512
#define MAXLINELEN	4000


#endif