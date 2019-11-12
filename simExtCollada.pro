include(config.pri)

TARGET = simExtCollada
TEMPLATE = lib

DEFINES -= UNICODE
CONFIG += shared
greaterThan(QT_MAJOR_VERSION,4): QT += widgets

*-msvc* {
    QMAKE_CXXFLAGS += -O2
    QMAKE_CXXFLAGS += -W3
}
*-g++* {
    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS += -Wall
    QMAKE_CXXFLAGS += -Wno-unused-parameter
    QMAKE_CXXFLAGS += -Wno-strict-aliasing
    QMAKE_CXXFLAGS += -Wno-empty-body
    QMAKE_CXXFLAGS += -Wno-write-strings

    QMAKE_CXXFLAGS += -Wno-unused-but-set-variable
    QMAKE_CXXFLAGS += -Wno-unused-local-typedefs
    QMAKE_CXXFLAGS += -Wno-narrowing

    QMAKE_CFLAGS += -O3
    QMAKE_CFLAGS += -Wall
    QMAKE_CFLAGS += -Wno-strict-aliasing
    QMAKE_CFLAGS += -Wno-unused-parameter
    QMAKE_CFLAGS += -Wno-unused-but-set-variable
    QMAKE_CFLAGS += -Wno-unused-local-typedefs
}

INCLUDEPATH += "../include"
INCLUDEPATH += "../simMath"
INCLUDEPATH += "tinyxml2"

INCLUDEPATH += $$BOOST_INCLUDEPATH

win32 {
    DEFINES += WIN_SIM
}

macx {
    DEFINES += MAC_SIM
}

unix:!macx {
    DEFINES += LIN_SIM
}

SOURCES += \
    COLLADAExporter.cpp \
    COLLADAImporter.cpp \
    mat4.cpp \
    Matrix.cpp \
    Mesh.cpp \
    Polygon.cpp \
    PolygonGroup.cpp \
    Rotate.cpp \
    Scale.cpp \
    SceneNode.cpp \
    Source.cpp \
    StringHelper.cpp \
    Translate.cpp \
    TriangleGroup.cpp \
    VisualScene.cpp \
    XMLHelper.cpp \
    colladadialog.cpp \
    tinyxml2/tinyxml2.cpp \
    simExtCollada.cpp \
    ../simMath/3Vector.cpp \
    ../simMath/3X3Matrix.cpp \
    ../simMath/4Vector.cpp \
    ../simMath/4X4FullMatrix.cpp \
    ../simMath/4X4Matrix.cpp \
    ../simMath/7Vector.cpp \
    ../simMath/MyMath.cpp \
    ../common/simLib.cpp \

HEADERS +=\
    COLLADAExporter.h \
    COLLADAImporter.h \
    Hash.h \
    mat4.h \
    Material.h \
    Matrix.h \
    Mesh.h \
    Polygon.h \
    PolygonGroup.h \
    Rotate.h \
    Scale.h \
    SceneNode.h \
    Source.h \
    StringHelper.h \
    Transformation.h \
    Translate.h \
    TriangleGroup.h \
    vec3.h \
    VisualScene.h \
    XMLHelper.h \
    colladadialog.h \
    tinyxml2/tinyxml2.h \
    simExtCollada.h \
    ../simMath/3Vector.h \
    ../simMath/3X3Matrix.h \
    ../simMath/4Vector.h \
    ../simMath/4X4FullMatrix.h \
    ../simMath/4X4Matrix.h \
    ../simMath/7Vector.h \
    ../simMath/MyMath.h \
    ../include/simLib.h \

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    colladadialog.ui

