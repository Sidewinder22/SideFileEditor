######################################################################
# Automatically generated by qmake (3.0) wt. wrz 20 00:53:28 2016
######################################################################

TEMPLATE = app
TARGET = SideFileEditor
INCLUDEPATH += src

# Input

QT      += widgets

# DEFINES +=  "DEBUG=1"

HEADERS += 	../src/app/IMaincontroller.hpp \
            ../src/app/MainController.hpp \
            ../src/file/Buffer.hpp \
            ../src/file/IBuffer.hpp \
            ../src/file/File.hpp \
            ../src/file/FileManager.hpp \
            ../src/file/IFile.hpp \
            ../src/file/IFileManager.hpp \
            ../src/log/Logger.hpp \
            ../src/utils/Utils.hpp \
            ../src/window/IWindow.hpp \
            ../src/window/OpenFilesDock.hpp \
            ../src/window/Window.hpp

SOURCES	+= 	../src/app/main.cpp \
            ../src/app/MainController.cpp \
            ../src/file/Buffer.cpp \
            ../src/file/File.cpp \
            ../src/file/FileManager.cpp \
            ../src/log/Logger.cpp \
            ../src/utils/Utils.cpp \
            ../src/window/OpenFilesDock.cpp \
            ../src/window/Window.cpp

#QMAKE_CXXFLAGS += -std=c++17
QMAKE_CXXFLAGS += -std=c++2a -Wextra

QMAKE_LIBS += -lstdc++fs

