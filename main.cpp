#include <GL\glew.h>
#include <GL\glut.h>
#include <string>
#include <iostream>
#include <fstream>

// The defaault shader program and the vertex array object are global variables
// so that the display method can properly use them.
GLuint defShaderProgram;
GLuint vertexArrayObject;

// Variables to hold FPS data
int framesSinceLastCheck;
float timeAtLastCheck;
int fps;


std::string readShaderFromFile(const char *filePath) {
	std::string content;
	std::ifstream fStream(filePath);

	if (!fStream.is_open()) {
		std::cerr << "Could not open: " << filePath << ". Typos much??\n";
		return "";
	}

	std::string tmpLine = "";
	while (!fStream.eof()) {
		std::getline(fStream, tmpLine);
		content.append(tmpLine + "\n");
	}

	fStream.close();
	return content;
}

void compileShader(GLuint shaderObject) {
	glCompileShader(shaderObject);

	// Get log file and print it, even if there are no errors since there could be warnings
	// helping us debug the shaders
	GLint logBuffLen;
	glGetShaderiv(shaderObject, GL_INFO_LOG_LENGTH, &logBuffLen);
	if (logBuffLen > 1)
	{
		GLchar* log_string = new char[logBuffLen + 1];
		glGetShaderInfoLog(shaderObject, logBuffLen, 0, log_string);
		std::cout << log_string;

		delete log_string;
	}

	// Check if the shader successfully compiled
	GLint shaderIsCompiled;
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &shaderIsCompiled);
	if (shaderIsCompiled != GL_TRUE)
	{
		std::cerr << "Shader could not compile\n";
	}
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

	//Create a vertex array object
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);

	//TODO: Init vertex/fragment shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertShaderString = readShaderFromFile("simple.vert");
	std::string fragShaderString = readShaderFromFile("simple.frag");
	const char *vertShaderChars = vertShaderString.c_str();
	const char *fragShaderChars = fragShaderString.c_str();

	glShaderSource(vertexShader, 1, &vertShaderChars, NULL);
	glShaderSource(fragmentShader, 1, &fragShaderChars, NULL);

	compileShader(vertexShader);
	compileShader(fragmentShader);

	defShaderProgram = glCreateProgram();
	glAttachShader(defShaderProgram, vertexShader);
	glAttachShader(defShaderProgram, fragmentShader);

	// Might be counterintuitive to delete the shaders here but they live on in our shaderprogram
	// so basically we just free up some unused memory.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glBindAttribLocation(defShaderProgram, 0, "position");

	glLinkProgram(defShaderProgram);

	GLint programIsLinked;
	glGetProgramiv(defShaderProgram, GL_LINK_STATUS, &programIsLinked);
	if (!programIsLinked) {
		std::cout << "Error when linking default shader program\n";
	}

	//TODO: Init texture to hold tracing results(image)
	//TODO: 
}


void display(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	int w = glutGet((GLenum)GLUT_WINDOW_WIDTH);
	int h = glutGet((GLenum)GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, w, h);
	glDisable(GL_CULL_FACE);
	
	// Set our shaderprogram and then draw the triangles that contains the raytraced texture/image.
	//TODO: Actually draw a texture.............
	glUseProgram(defShaderProgram);
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glUseProgram(0);

	// Print fps in bottom left corner
	std::string fpsString = std::to_string(fps);
	for (int i = 0; i < fpsString.length(); i++) {
		glWindowPos2i(i*12, 0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, fpsString[i]);
	}

	glutSwapBuffers();
}

void idle()
{
	//Calculate fps to display in the scene
	framesSinceLastCheck++;
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	float timeSinceLastCheck = currentTime - timeAtLastCheck;

	if (timeSinceLastCheck > 1000.0f) {
		//Calculate with floats and then cast to int
		fps = ((float)framesSinceLastCheck) / (timeSinceLastCheck / 1000.0f);

		timeAtLastCheck = currentTime;
		framesSinceLastCheck = 0;
	}

	glutPostRedisplay();
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GGRT");
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	initGL();

	glutMainLoop();
	return 0;
}