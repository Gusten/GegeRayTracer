#version 130

precision highp float;

//uniform sampler2D framebuffer; 
//uniform int framebufferSamples; 

//in vec2 texCoord; 
out vec4 fragmentColor;

void main() 
{
	//fragmentColor = (1.0 / float(framebufferSamples)) * texture2D(framebuffer, texCoord);
	fragmentColor = vec4(0.0f, 1.0f, 0.0f, 0.0f);
}
