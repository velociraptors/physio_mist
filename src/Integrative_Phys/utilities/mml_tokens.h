/**************************************************************************************************
  mml_tokens.h

  Contributor(s): E. Zeynep Erson				  
  Created on:     December 2007
  Definition:	  Tokens used in MML models
**************************************************************************************************/

#ifndef MML_TOKENS_H
#define	MML_TOKENS_H

//NOTE TO ROBIN: DEFINE DELIMINATOR CHARACTERS OR ANY TOKEN THAT IS USED THROUGHOUT THE PARSING PROCESS HERE.
#define	LINEBUFFERSIZE		256
#define EQUATIONBUFFERSIZE  256
#define SECTION_HEADER			"//-------------------"
#define OPERATORS				"()+-*/^<>=!&[]"
#define EQUAL_SIGN				"="
#define CONDITION_SIGN			"<>=!"
#define TERMINATION_CHAR		";"
#define COMMENT_CHARS			"//"
#define COMMENT_BLOCK_START		"/*"
#define COMMENT_BLOCK_END		"*/"
#define EXPONENT				"exp"
#define ABS						"abs"
#define LN						"ln"
#define LOG10					"log"
#define SQUARE_RT				"sqrt"
#define SPACE_CHARS				"\t "
#define COS						"cos"
#define SIN						"sin"
#define PI						"PI"
#define POW						"pow"
#define	COMMA					","
#define IF						"if"
#define ELSEIF					"elseif"
#define ELSE					"else"

#endif