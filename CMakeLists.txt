# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StudentManagement VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler flags
if (MSVC)
    # Windows specific flags
    add_compile_options(/W4)
else()
    # Linux and other platforms specific flags
    add_compile_options(-Wall -Wextra)
endif()

# Source files
set(SOURCES main.cpp student.cpp)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Custom clean target for Windows
if (WIN32)
    add_custom_target(clean_custom
        COMMAND del /f ${PROJECT_NAME}.exe
        COMMENT "Cleaning up executable"
    )
else()
    add_custom_target(clean_custom
        COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_NAME}
        COMMENT "Cleaning up executable"
    )
endif()
