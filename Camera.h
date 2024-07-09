#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include<GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "Shader.h"

enum Camera_Movement {
	FOWRARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UPWARD,
	DOWNWARD
};


class Camera
{
public:


	glm::vec3 position;
	glm::vec3 orientation= glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 right;
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	//Euler Angles
	float yaw = -90.0f;
	float pitch = 0.0f;
	//camera options
	float movementSpeed = 2.5f;
	float mouseSensitivity = 0.05f;
	float zoom = 45.0f;

	// constructor with vectors
	Camera(glm::vec3 positionIn = glm::vec3(0.0f, 0.0f, 0.0f));

	// constructor with scalar values
	//Camera(float posX, float posY, float posZ, float upX, float upY, float upZ);

	glm::mat4 GetViewMatrix();
	void ProcessKeyboard(Camera_Movement direction, float deltaTime);
	void ProcessMouseMovement(float xOffSet, float yOffSet, GLboolean constrainPitch = true);
	void ProcessMouseScroll(float yoffset);


	
private:
	void UpdateCameraVectors();
};
