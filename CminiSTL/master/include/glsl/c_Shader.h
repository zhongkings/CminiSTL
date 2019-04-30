#pragma once
#include "glad.h"
#include "../c_StringBuffer.h"
#include "3dmath/c_MatCalculate.h"

typedef struct {
	GLuint id;
	c_StringBuffer *log;
} c_Shader;


c_Shader* shCreate(const GLchar *vert, const GLchar *frag);
c_Shader* shCreateinGeom(const GLchar *vert, const GLchar *frag, const GLchar *geom);
GLvoid shBegin(c_Shader *sourceTar);
GLvoid shSetBool(const GLchar *name, GLint value);
GLvoid shSetInt(const GLchar *name, GLint value);
GLvoid shSetFloat(const GLchar *name, GLfloat value);
GLvoid shSetFloat2f(const GLchar *name, GLfloat x, GLfloat y);
GLvoid shSetFloat3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z);
GLvoid shSetFloat4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLvoid shSetVec2(const GLchar *name, c_Vec2f const*const vec);
GLvoid shSetVec3(const GLchar *name, c_Vec3f const*const vec);
GLvoid shSetVec4(const GLchar *name, c_Vec4f const*const vec);
GLvoid shSetMat2(const GLchar *name, c_Matrix2x2f const*const mat);
GLvoid shSetMat3(const GLchar *name, c_Matrix3x3f const*const mat);
GLvoid shSetMat4(const GLchar *name, c_Matrix4x4f const*const mat);
GLvoid shEnd();
GLvoid shDerstory(c_Shader *sourceTar);
