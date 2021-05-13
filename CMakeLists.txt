cmake_minimum_required(VERSION 3.15)
project(simExtCollada)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_AUTOUIC ON)

find_package(Boost REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(NOT LIBPLUGIN_DIR)
    if(DEFINED ENV{COPPELIASIM_ROOT_DIR})
        set(LIBPLUGIN_DIR $ENV{COPPELIASIM_ROOT_DIR}/programming/libPlugin)
    else()
        set(LIBPLUGIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libPlugin)
    endif()
endif()
list(APPEND CMAKE_MODULE_PATH ${LIBPLUGIN_DIR}/cmake)
find_package(CoppeliaSim 4.1.0.0 REQUIRED)

coppeliasim_add_plugin(
    simExtCollada
    LEGACY
    SOURCES
    simExtCollada.cpp
    COLLADAExporter.cpp
    COLLADAImporter.cpp
    mat4.cpp
    Matrix.cpp
    Mesh.cpp
    Polygon.cpp
    PolygonGroup.cpp
    Rotate.cpp
    Scale.cpp
    SceneNode.cpp
    Source.cpp
    StringHelper.cpp
    Translate.cpp
    TriangleGroup.cpp
    VisualScene.cpp
    XMLHelper.cpp
    colladadialog.cpp
    tinyxml2/tinyxml2.cpp
    colladadialog.ui
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/3Vector.cpp
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/3X3Matrix.cpp
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/4Vector.cpp
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/4X4FullMatrix.cpp
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/4X4Matrix.cpp
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/7Vector.cpp
    ${COPPELIASIM_ROOT_DIR}/programming/simMath/MyMath.cpp
)
target_include_directories(simExtCollada PRIVATE ${COPPELIASIM_ROOT_DIR}/programming/simMath)
target_include_directories(simExtCollada PRIVATE tinyxml2)
target_link_libraries(simExtCollada Qt5::Widgets)
