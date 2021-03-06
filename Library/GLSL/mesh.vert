#version 140

in vec3 position;
in vec3 normal;

uniform mat4 mvM;
uniform mat4 prM;
uniform mat3 nmM;
uniform vec3 lightDir;
uniform vec3 clipNormal;
uniform float clipDistance;

out vec3 mvsNormal;
out vec3 lightNormal;


void main() {
	gl_Position  = prM * mvM * vec4(position.xyz, 1.0);
	mvsNormal    = nmM * normal;
	lightNormal  = nmM * lightDir;
	gl_ClipDistance[0] = -dot(position.xyz, clipNormal) + clipDistance;

	//if (mvsNormal.z < 0.0) mvsNormal.z = -mvsNormal.z;
}
