#include "lib/Camera.hpp"
#include <iostream>
#include <memory>

Camera::Camera(int id) { this->id = id; }

Camera::~Camera() { std::cout << "Destroying camera #" << id << std::endl; }

void Camera::run() { std::cout << "Running camera #" << id << std::endl; }
