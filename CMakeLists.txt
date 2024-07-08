cmake_minimum_required(VERSION 3.10)
project(zit VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/include/cmd
    PRIVATE ${PROJECT_SOURCE_DIR}/include/common
    PRIVATE ${PROJECT_SOURCE_DIR}/include/utils
    PRIVATE ${PROJECT_SOURCE_DIR}/include/deps/rapidjson/include
    PRIVATE ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE OpenSSL::SSL
    PRIVATE OpenSSL::Crypto
)
