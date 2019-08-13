#ifndef SIMPLEGL_SHAPE_H
#define SIMPLEGL_SHAPE_H
#include <GL/glew.h>
#include <GL/glut.h>
#include <list>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/vector_angle.hpp"

class Shape{
	public:
	int nVertices;
	int nElements;
	
	glm::vec3 bbox0, bbox1;
	
	bool useColor, useTexture, useElements;
	bool useTransparency;
		
	GLuint vbo, cbo, ebo, tbo;

	GLuint tex;
	
	GLuint vertexShader, fragmentShader;
	GLuint program;

	public:
	static std::list<Shape*> allShapes;	// a list of all currently existing shapes 
	
	public:
	Shape(int nverts);
	virtual ~Shape();

	void setVertices(float * verts);
	void setColors(float * cols);
	void setElements(int * ele, int nelements);
	void applyTexture(float * uvs, unsigned char * image, int w, int h);
	void deleteTexture();

	virtual void render();
	

};

#endif
