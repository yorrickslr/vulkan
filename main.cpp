#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

// global variables #uglycode
std::string app_name = "Vulkan Voodoo Wonderland";

// declarations
void initGLFW();
void initVulkan();
void mainLoop();

// definitions
void initGLFW() {
  std::cout << "initializing GLFW" << std::endl;
}

void initVulkan() {
  std::cout << "initializing Vulkan" << std::endl;
}

void mainLoop() {
  for(int i=0; i<10000; i++) {
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
