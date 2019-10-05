#pragma once

/*************************************************************************************************/
/*                                  CUBE DESCRIPTION                                             */
/*************************************************************************************************/

// NUMBER OF VERTEX (4 vertex * 6 faces)
const int cubeNVertex = 24;

// NUMBER OF TRIANGLES (2 triangles * 6 faces)
const int cubeNTriangleIndex = 12;


// VERTEX POSITION
const float cubeVertexPos[] = {
	//FACE Z = 1
	-1.0f,	-1.0f,	 1.0f, //0
	 1.0f,	-1.0f,	 1.0f, //1
	-1.0f,	 1.0f,	 1.0f, //2
	 1.0f,	 1.0f,	 1.0f, //3

	//FACE Z = -1		   
	-1.0f,	-1.0f,	-1.0f, //4
	 1.0f,	-1.0f,	-1.0f, //5
	-1.0f,	 1.0f,	-1.0f, //6
	 1.0f,	 1.0f,	-1.0f, //7

	//FACE X = 1		   
	1.0f,	-1.0f,	-1.0f, //8
	1.0f,	-1.0f,	 1.0f, //9
	1.0f,	 1.0f,	-1.0f, //10
	1.0f,	 1.0f,	 1.0f, //11

	//FACE X = -1		   
	-1.0f,	-1.0f,	-1.0f, //12
	-1.0f,	-1.0f,	 1.0f, //13
	-1.0f,	 1.0f,	-1.0f, //14
	-1.0f,	 1.0f,	 1.0f, //15

	//FACE Y = 1		   
	-1.0f,	 1.0f,	-1.0f, //16
	-1.0f,	 1.0f,	 1.0f, //17
	 1.0f,	 1.0f,	-1.0f, //18
	 1.0f,	 1.0f,	 1.0f, //19

	//FACE Y = -1		   
	-1.0f,	-1.0f,	-1.0f, //20
	-1.0f,	-1.0f,	 1.0f, //21
	 1.0f,	-1.0f,	-1.0f, //22
	 1.0f,	-1.0f,	 1.0f  //23
};


// VERTEX NORMAL
const float cubeVertexNormal[] = {
	//FACE Z = 1
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,

	//FACE Z = -1		   
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,

	//FACE X = 1		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,

	//FACE X = -1		   
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,

	//FACE Y = 1		   
	0.0f,	1.0f,	0.0f,
	0.0f,	1.0f,	0.0f,
	0.0f,	1.0f,	0.0f,
	0.0f,	1.0f,	0.0f,

	//FACE Y = -1		   
	0.0f,	-1.0f,	0.0f,
	0.0f,	-1.0f,	0.0f,
	0.0f,	-1.0f,	0.0f,
	0.0f,	-1.0f,	0.0f
};


// VERTEX COLOR
const float cubeVertexColor[] = {
	//FACE Z = 1
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,

	//FACE Z = -1		   
	0.6f,	0.6f,	 1.0f,
	0.6f,	0.6f,	 1.0f,
	0.6f,	0.6f,	 1.0f,
	0.6f,	0.6f,	 1.0f,

	//FACE X = 1		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,

	//FACE X = -1		   
	1.0f,	0.6f,	 0.6f,
	1.0f,	0.6f,	 0.6f,
	1.0f,	0.6f,	 0.6f,
	1.0f,	0.6f,	 0.6f,

	//FACE Y = 1		   
	0.0f,	1.0f,	0.0f,
	0.0f,	1.0f,	0.0f,
	0.0f,	1.0f,	0.0f,
	0.0f,	1.0f,	0.0f,

	//FACE Y = -1		   
	0.6f,	1.0f,	0.6f,
	0.6f,	1.0f,	0.6f,
	0.6f,	1.0f,	0.6f,
	0.6f,	1.0f,	0.6f
};

// VERTEX TEXTURE COORDINATES
const float cubeVertexTexCoord[] = {
	//FACE Z = 1
	 0.0f, 0.0f,
	 1.0f, 0.0f,
	 0.0f, 1.0f,
	 1.0f, 1.0f,

	 //FACE Z = -1
	 0.0f, 1.0f,
	 1.0f, 1.0f,
	 0.0f, 0.0f,
	 1.0f, 0.0f,

	 //FACE X = 1	
	 0.0f,	1.0f,
	 1.0f,	1.0f,
	 0.0f,	0.0f,
	 1.0f,	0.0f,

	 //FACE X = -1
	 0.0f,	0.0f,
	 1.0f,	0.0f,
	 0.0f,	1.0f,
	 1.0f,	1.0f,

	 //FACE Y = 1	
	 0.0f, 1.0f,
	 0.0f, 0.0f,
	 1.0f, 1.0f,
	 1.0f, 0.0f,

	 //FACE Y = -1
	 0.0f, 0.0f,
	 0.0f, 1.0f,
	 1.0f, 0.0f,
	 1.0f, 1.0f,
};

// TRIANGLE INDEX
const unsigned int cubeTriangleIndex[] = {
	//FACE Z = 1
	0,1,2,			1,3,2,
	//FACE Z = -1
	4,6,5,			5,6,7,
	//FACE X = 1
	8,10,9,			9,10,11,
	//FACE X = -1
	12,13,14,		13,15,14,
	//FACE Y = 1
	16,17,18,		17,19,18,
	//FACE Y = -1
	20,22,21,		21,22,23,
};

// TANGENTS
const float cubeVertexTangent[] = {
	//FACE Z = 1
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,

	//FACE Z = -1				
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,

	//FACE X = 1				
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,

	//FACE X = -1				
	0.0f,	0.0f,	1.0f,
	0.0f,	0.0f,	1.0f,
	0.0f,	0.0f,	1.0f,
	0.0f,	0.0f,	1.0f,

	//FACE Y = 1	   
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,

	//FACE Y = -1					   
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
	1.0f,	0.0f,	0.0f,
};