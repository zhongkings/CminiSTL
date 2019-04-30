#include "glad.h"
#include "SDL.h"
#include "SDL_opengl.h"

#include "c_StringBuffer.h"
#include "3dmath/c_MatCalculate.h"
#include "sample/sample.h"
#include "glsl/c_Shader.h"

c_BOOL quitflag = c_FALSE;
SDL_Window *app = C_NULL;
SDL_GLContext *glContext = C_NULL;
SDL_Event e;
c_Matrix4x4f model;
static GLint x = 800;
static GLint y = 600;

static c_FLOAT triangle_vertices[] = {
	  -1.0f, -1.0f, 0.0f, 1,0,0,
	   1.0f, -1.0f, 0.0f, 0,1,0,
	   0.0f,  1.0f, 0.0f, 0,0,1
};

static void HandleEvent(SDL_Event *e) {
	if (e->type == SDL_QUIT)
		quitflag = c_TRUE;
	else if (e->type == SDL_WINDOWEVENT) {
		SDL_GetWindowSize(app, &x, &y);
		glViewport(0, 0, x, y);
	}
	else if (e->type == SDL_KEYDOWN) {
		switch (e->key.keysym.sym) {
		case SDLK_r:
			model = mat4RotateXYZ(&model, 90.0f, 0, 0, 1);
			break;
		case SDLK_d:
			model = mat4fCreateDiag(1.0f);
			break;
		case SDLK_m:
			model = mat4MirrorXYZ(&model, 1, 1, 0);
			break;
		case SDLK_UP:
			model = mat4TranslateXYZ(&model, 0.2, 0.2, 0.2);
			break;
		case SDLK_DOWN:
			model = mat4TranslateXYZ(&model, -0.2, -0.2, -0.2);
			break;
		case SDLK_ESCAPE:
			quitflag = c_TRUE;
			break;
		case SDLK_SPACE:
			model = mat4ScaleXYZ(&model, 0.2f, 0.2f, 0.2f);
			break;
		}
	}
	else if (e->type == SDL_MOUSEBUTTONDOWN) {
		if (e->button.button == SDL_BUTTON_LEFT) {
			
		}
	}


}

static GLuint getVertexBuffer(c_FLOAT *vertex, c_INT vlen) {
	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex[0]) * vlen, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);

	return vbo;
}
static GLuint getVertexArray(c_INT vbo) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, c_FALSE, 6 * sizeof(c_FLOAT), (c_DATA*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, c_FALSE, 6 * sizeof(c_FLOAT), (c_DATA*)(sizeof(c_FLOAT) * 3));
	glEnableVertexAttribArray(1);
	glBindVertexArray(GL_NONE);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
	return vao;
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	app = SDL_CreateWindow("CminiSTL", 400, 100, x, y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	glContext = SDL_GL_CreateContext(app);
	gladLoadGL();
	glClearColor(0, 0, 0, 1);
	glViewport(0, 0, x, y);

	c_Shader *shader = shCreate("./glsl/triangle.vert", "./glsl/triangle.frag");
	c_Shader *lineShader = shCreate("./glsl/line.vert", "./glsl/line.frag");

	GLuint vbo = getVertexBuffer(triangle_vertices, sizeof(triangle_vertices));
	GLuint vao = getVertexArray(vbo);

	model = mat4fCreateDiag(1.0f);
	model = mat4TranslateXYZ(&model, 400, 300, 0);
	model = mat4ScaleSetXYZ(&model, 150, 150, 0);
	c_Matrix4x4f projection = mat4OrthoRH(0, x, 0, y, 0.0f, 1.0f);
	c_Matrix4x4f mp = mat4x4fMul(&projection, &model);

	while (!quitflag) {
		glClear(GL_COLOR_BUFFER_BIT);

		//Draw triangles
		shBegin(shader);
		mp = mat4fCreateDiag(1.0f);
		shSetMat4("model", &model);
		shSetMat4("projection", &projection);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		SDL_GL_SwapWindow(app);
		while (SDL_PollEvent(&e) != 0)
			HandleEvent(&e);
	}

	shDerstory(shader);
	shDerstory(lineShader);
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(app);
	SDL_Quit();

	return 0;
}