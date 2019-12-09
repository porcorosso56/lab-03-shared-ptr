cmake_minimum_required(VERSION 3.10:)
project(SharedPtr)

set(CMAKE_CXX_STANDARD 17)
add_library(SharedPtr INTERFACE)


add_executable(shared_ptr sources/main.cpp)

target_include_directories(
  SharedPtr
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(shared_ptr SharedPtr)
