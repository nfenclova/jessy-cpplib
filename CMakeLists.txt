cmake_minimum_required(VERSION "3.14.0")

### Default Build Type Configuration
set(CMAKE_BUILD_TYPE
  "RelWithDebInfo"
  CACHE
  STRING
  "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel"
)

### Include Cross Toolchain
include("FetchContent")

FetchContent_Declare("toolchain"
  GIT_REPOSITORY "https://github.com/nfenclova/jessy-cmake-toolchain.git"
  GIT_TAG "master"
)
FetchContent_MakeAvailable("toolchain")

### Project Information
project("jessy-cpplib"
  LANGUAGES CXX
  VERSION 0.1.0
)

### Library
file(GLOB JESSY_CPPLIB_HEADERS RELATIVE "${PROJECT_SOURCE_DIR}" CONFIGURE_DEPENDS "include/**")

add_library("jessy-cpplib" INTERFACE)

target_sources("jessy-cpplib" INTERFACE
  ${JESSY_CPPLIB_HEADERS}
)

target_include_directories("jessy-cpplib" SYSTEM INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

add_library("jessy::c++" ALIAS "jessy-cpplib")