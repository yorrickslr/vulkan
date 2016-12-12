#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <exception>

// I am going to hate myself for this coding style...

// global variables
std::string app_name = "Vulkan Voodoo Wonderland";
int app_width = 500;
int app_height = 500;
GLFWwindow* window;

// declarations
void initGLFW();
void initVulkan();
void mainLoop();

// definitions
void initGLFW() {
  std::cout << "initializing GLFW" << std::endl;
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(app_width, app_height, app_name.c_str(), nullptr, nullptr);
}

void initVulkan() {
  std::cout << "initializing Vulkan" << std::endl;

}

void mainLoop() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    std::cout << "main loop" << std::endl;
  }
}

// application
int main(int argc, char** argv) {
  try {
    initGLFW();
    initVulkan();
    mainLoop();
  } catch(std::exception e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }
  std::cout << "terminating..." << std::endl;
  return 0;
}
