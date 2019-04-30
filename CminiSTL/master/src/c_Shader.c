#pragma once
#include "glsl/c_Shader.h"
#include <stdio.h>
#include <stdlib.h>

static GLuint state = GL_NONE;

static GLvoid checkCompileErrors(c_Shader *shader, GLuint id, GLint type) {
	c_BOOL success = c_FALSE;
	GLchar infoLog[512];
	if (type == GL_LINK_STATUS) {
		glGetProgramiv(id, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(id, 512, NULL, infoLog);
			strbAppendOfChars(shader->log, "ERROR::PROGRAM_LINKING_ERROR of type:\n");
			strbAppendOfChars(shader->log, infoLog);
		}
	} else {
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(id, 512, NULL, infoLog);
			strbAppendOfChars(shader->log, "ERROR::SHADER_COMPILATION_ERROR of type:\n");
			strbAppendOfChars(shader->log, infoLog);
		}
	}
}

static c_StringBuffer* loadfile(const GLchar *path) {
	FILE *fp;
	c_StringBuffer *sb;
	c_CHAR ch[50];
	GLint size;

	fp = fopen(path, "r+");
	if (fp == C_NULL) {
		printf("Load { %s }::Error \n", path);
		return C_NULL;
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp) + 1;
	sb = strbCreateCapacity(size);
	fseek(fp, 0, 0);
	while (fgets(ch, 50, fp)) {
		strbAppendOfChars(sb, ch);
	}
	fclose(fp);

	return sb;
}

c_Shader* shCreate(const GLchar *vert, const GLchar *frag) {
	c_Shader *newShader = C_MALLOC(c_Shader*, sizeof(c_Shader), 1);
	newShader->log = strbCreate();

	c_StringBuffer *vertSource = loadfile(vert);
	c_StringBuffer *fragSource = loadfile(frag);

	if (vertSource == C_NULL || fragSource == C_NULL)
		return C_NULL;

	//VertexShader
	GLuint vertNum = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertNum, 1, &vertSource->chars, NULL);
	glCompileShader(vertNum);
	checkCompileErrors(newShader, vertNum, GL_VERTEX_SHADER);

	//FragmentShader
	GLuint fragNum = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragNum, 1, &fragSource->chars, NULL);
	glCompileShader(fragNum);
	checkCompileErrors(newShader, fragNum, GL_FRAGMENT_SHADER);

	//Á´½Ó
	newShader->id = glCreateProgram();
	glAttachShader(newShader->id, vertNum);
	glAttachShader(newShader->id, fragNum);
	glLinkProgram(newShader->id);
	checkCompileErrors(newShader, newShader->id, GL_LINK_STATUS);

	strbDestroy(vertSource);
	strbDestroy(fragSource);
	glDeleteShader(vertNum);
	glDeleteShader(fragNum);

	return newShader;
}

c_Shader* shCreateinGeom(const GLchar *vert, const GLchar *frag, const GLchar *geom) {
	c_Shader *newShader = C_MALLOC(c_Shader*, sizeof(c_Shader), 1);
	newShader->log = strbCreate();

	c_StringBuffer *vertSource = loadfile(vert);
	c_StringBuffer *fragSource = loadfile(frag);
	c_StringBuffer *geomSource = loadfile(geom);

	//VertexShader
	GLuint vertNum = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertNum, 1, &vertSource->chars, NULL);
	glCompileShader(vertNum);
	checkCompileErrors(newShader, vertNum, GL_VERTEX_SHADER);

	//FragmentShader
	GLuint fragNum = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragNum, 1, &fragSource->chars, NULL);
	glCompileShader(fragNum);
	checkCompileErrors(newShader, fragNum, GL_FRAGMENT_SHADER);

	//GeomtryShader
	GLuint geomNum = glCreateShader(GL_GEOMETRY_SHADER);
	glShaderSource(geomNum, 1, &geomSource->chars, NULL);
	glCompileShader(geomNum);
	checkCompileErrors(newShader, geomNum, GL_GEOMETRY_SHADER);

	//Á´½Ó
	newShader->id  = glCreateProgram();
	glAttachShader(newShader->id, vertNum);
	glAttachShader(newShader->id, fragNum);
	glAttachShader(newShader->id, geomNum);
	glLinkProgram(newShader->id);
	checkCompileErrors(newShader, newShader->id, GL_LINK_STATUS);

	strbDestroy(vertSource);
	strbDestroy(fragSource);
	strbDestroy(geomSource);
	glDeleteShader(vertNum);
	glDeleteShader(fragNum);
	glDeleteShader(geomNum);

	return newShader;
}

GLvoid shBegin(const c_Shader *sourceTar) {
	state = sourceTar->id;
	glUseProgram(sourceTar->id);
}

GLvoid shSetBool(const GLchar *name, GLint value) {
	glUniform1i(glGetUniformLocation(state, name), value);
}

GLvoid shSetInt(const GLchar *name, GLint value) {
	glUniform1i(glGetUniformLocation(state, name), value);
}

GLvoid shSetFloat(const GLchar *name, GLfloat value) {
	glUniform1f(glGetUniformLocation(state, name), value);
}

GLvoid shSetFloat2f(const GLchar *name, GLfloat x, GLfloat y) {
	glUniform2f(glGetUniformLocation(state, name), x, y);
}

GLvoid shSetFloat3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z) {
	glUniform3f(glGetUniformLocation(state, name), x, y, z);
}

GLvoid shSetFloat4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	glUniform4f(glGetUniformLocation(state, name), x, y, z, w);
}

GLvoid shSetVec2(const GLchar *name, c_Vec2f const*const vec) {
	glUniform2f(glGetUniformLocation(state, name), vec->x, vec->y);
}

GLvoid shSetVec3(const GLchar *name, c_Vec3f const*const vec) {
	glUniform3f(glGetUniformLocation(state, name), vec->x, vec->y, vec->z);
}

GLvoid shSetVec4(const GLchar *name, c_Vec4f const*const vec) {
	glUniform4f(glGetUniformLocation(state, name), vec->x, vec->y, vec->z, vec->w);
}

GLvoid shSetMat2(const GLchar *name, c_Matrix2x2f const*const mat) {
	glUniformMatrix2fv(glGetUniformLocation(state, name), 1, GL_FALSE, &mat->m[0][0]);
}

GLvoid shSetMat3(const GLchar *name, c_Matrix3x3f const*const mat) {
	glUniformMatrix3fv(glGetUniformLocation(state, name), 1, GL_FALSE, &mat->m[0][0]);
}

GLvoid shSetMat4(const GLchar *name, c_Matrix4x4f const*const mat) {
	glUniformMatrix4fv(glGetUniformLocation(state, name), 1, GL_FALSE, &mat->m[0][0]);
}

GLvoid shEnd() {
	glUseProgram(GL_NONE);
	state = GL_NONE;
}

GLvoid shDerstory(c_Shader *sourceTar) {
	state = GL_NONE;
	glDeleteProgram(sourceTar->id);
	strbDestroy(sourceTar->log);
	C_FREE(sourceTar);
}