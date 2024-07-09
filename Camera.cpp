#include "Camera.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(glm::vec3 position)
{
	Camera::position = position;
	UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + orientation, worldUp);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
	float velocity = movementSpeed * deltaTime;
	if (direction == FOWRARD)
		position += orientation * velocity;
	if (direction == BACKWARD)
		position -= orientation * velocity;
	if (direction == LEFT)
		position -= right * velocity;
	if (direction == RIGHT)
		position += right * velocity;
	if (direction == UPWARD)
		position += up * velocity;
	if (direction == DOWNWARD)
		position -= up * velocity;

}

void Camera::ProcessMouseMovement(float xOffSet, float yOffSet, GLboolean constrainPitch)
{
	xOffSet *= mouseSensitivity;
	yOffSet *= mouseSensitivity;

	yaw = glm::mod(yaw + xOffSet, 360.0f);
	pitch += yOffSet;

	if (constrainPitch) {
		if (pitch > 89.0f) {
			pitch = 89.0f;
		}
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	UpdateCameraVectors();
}



void Camera::ProcessMouseScroll(float yoffset)
{
	zoom -= (float)yoffset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;
}

void Camera::UpdateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	orientation = glm::normalize(front);

	right = glm::normalize(glm::cross(orientation, up));
	worldUp = glm::normalize(glm::cross(right, orientation));
}
