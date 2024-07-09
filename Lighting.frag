#version 330 core
out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;

in vec3 normal;
in vec3 fragmentPosition;

void main()
{
	float ambientStrength = 0.2;
	vec3 ambient = ambientStrength * lightColor;

	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(lightPosition - fragmentPosition);
	float diff = max(dot(normal, lightDirection), 0.0);
	vec3 diffuse = diff * lightColor;
	vec3 result = (ambient + diffuse) * objectColor;
	FragColor = vec4(result, 1.0);
	
}