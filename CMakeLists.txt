cmake_minimum_required(VERSION 4.4.3)
project(Kabuki CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------------------------------------------------------------------------------------------------
# Dependencies (FetchContent)
# -------------------------------------------------------------------------------------------------
include(FetchContent)

set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)

FetchContent_Declare(glfw   GIT_REPOSITORY https://github.com/glfw/glfw     GIT_TAG 3.5.1)
FetchContent_Declare(glm    GIT_REPOSITORY https://github.com/g-truc/glm    GIT_TAG 1.0.3)
FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog GIT_TAG v1.17.0)
FetchContent_Declare(stb    GIT_REPOSITORY https://github.com/nothings/stb  GIT_TAG origin/master)
FetchContent_Declare(imgui  GIT_REPOSITORY https://github.com/ocornut/imgui GIT_TAG origin/master)

FetchContent_MakeAvailable(glfw glm spdlog stb imgui)

add_library(imgui STATIC
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# -------------------------------------------------------------------------------------------------
# Target
# -------------------------------------------------------------------------------------------------
add_executable(app src/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/src ${stb_SOURCE_DIR})
target_link_libraries(app PRIVATE glm::glm spdlog::spdlog imgui)