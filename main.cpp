#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    // Print the error description to stderr
    fprintf(stderr, "Error: %s\n", description);
}

int main()
{
    // Set the error callback function
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
        return -1;

    // Declare a pointer to a GLFW window
    GLFWwindow* window;

    // Set the OpenGL profile to core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Set the major version of the OpenGL context to 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // Set the minor version of the OpenGL context to 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Enable forward compatibility for the OpenGL context
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
    // Check if the window creation failed
    if(!window)
    {
        // Terminate GLFW
        glfwTerminate();
        // Return error code
        return -1;
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW to setup the OpenGL Function pointers
    GLenum err = glewInit();
    // Check if GLEW initialization failed
    if(err != GLEW_OK)
    {
        // Print error message to stderr
        fprintf(stderr, "Error initializing GLEW.\n");
        // Terminate GLFW
        glfwTerminate();
        // Return error code
        return -1;
    }

    // Declare an array to store the OpenGL version
    int glVersion[2] = {-1, 1};
    // Get the major version of the OpenGL context
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    // Get the minor version of the OpenGL context
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

    // Print the OpenGL version being used
    printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);

    glClearColor(1.0, 0.0, 0.0, 1.0);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}