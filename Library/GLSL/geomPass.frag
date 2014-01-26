#version 330

in vec3 fsPos;
in vec4 fsCol;
in vec3 fsNrm;

out vec3 outPos;
out vec4 outCol;
out vec3 outNrm;

void main(void) {
	outPos = fsPos;
	outCol = fsCol;
	outNrm = normalize(fsNrm);
}