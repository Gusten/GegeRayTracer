#ifdef WIN32
#include <windows.h>
#endif

#include <GL\glew.h>
#include <GL\glut.h>
#include <string>
#include <iostream>
#include <fstream>

const char *readShaderFromFile(const char *filePath) {
	std::string content;
	std::ifstream fStream(filePath);

	if (!fStream.is_open()) {
		std::cerr << "Could not read file: " << filePath << ". Are you sure it exists??" << std::endl;
		return "";
	}

	std::string tmpLine = "";
	while (!fStream.eof()) {
		std::getline(fStream, tmpLine);
		content.append(tmpLine + "\n");
	}

	fStream.close();
	return content.c_str();
}


void initGL() {
	// The image is displayed in the window by using two simple primitives(triangles)
	// that we map to a texture. The texture will contain the colors we get from our raytracing.

	glewInit();

	// Create an array for holding the vertex positions of our two triangles
	float positions[] = {
		1.0f,    -1.0f, 0.0f,
		1.0f,	  1.0f, 0.0f,
		-1.0f,	 -1.0f, 0.0f,
		-1.0f,	  1.0f, 0.0f
	};

	//Create a buffer for holding our triangle vertex positions
	GLuint positionBuffer;
	glGenBuffers(1, &positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	//TODO: Init vertex/fragment shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char *vertShaderString = readShaderFromFile("simple.vert");
	const char *fragShaderString = readShaderFromFile("simple.frag");

	glShaderSource(vertexShader, 1, &vertShaderString, NULL);
	glShaderSource(fragmentShader, 1, &fragShaderString, NULL);

	//TODO: Init texture to hold tracing results(image)
	//TODO: 
}


void display(void) {
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	int w = glutGet((GLenum)GLUT_WINDOW_WIDTH);
	int h = glutGet((GLenum)GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, w, h);
	glDisable(GL_CULL_FACE);
	
	glutSwapBuffers();
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GGRT");
	glutDisplayFunc(display);

	initGL();

	glutMainLoop();
	return 0;
}