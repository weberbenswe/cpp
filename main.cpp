#include <iostream>
#include <MoltenVK/mvk_vulkan.h>
#include <GLFW/glfw3.h>

int main(){
    initWindow();

    // Initialize Vulkan instance
    VkInstance instance;
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Application";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Enable MoltenVK extensions
    const char* enabledExtensions[] = {VK_MVK_MACOS_SURFACE_EXTENSION_NAME};
    createInfo.enabledExtensionCount = sizeof(enabledExtensions) / sizeof(enabledExtensions[0]);
    createInfo.ppEnabledExtensionNames = enabledExtensions;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance." << std::endl;
        return -1;
    }

    // Set up MoltenVK for the instance
    MVKConfiguration mvkConfig = {0};
    mvkConfig.pView = window;
    mvkConfig.viewSurfaceId = (MVKSurface*)&surface;

    // Main loop
    mainLoop();

    // Cleanup resources
    cleanup();
    return 0;
}

void initWindow() {
    // Initialize GLFW
    glfwInit();

    // Set GLFW to not create an OpenGL context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create a GLFW window
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Window", nullptr, nullptr);
}

void mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Render here
    }
}

void cleanup() {
    // Destroy GLFW window
    glfwDestroyWindow(window);

    // Terminate GLFW
    glfwTerminate();
}