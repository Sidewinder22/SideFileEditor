######################################################################
# Automatically generated by qmake (3.0) wt. wrz 20 00:53:28 2016
######################################################################

TEMPLATE = app
TARGET = MidiAnalyzer
INCLUDEPATH += ../src

# Input

QT      += widgets

# DEFINES +=  "DEBUG=1"

HEADERS += 	../src/utils/Logger.hpp \
            ../src/window/Window.hpp \
            ../src/file/File.hpp \
            ../src/file/FileContainer.hpp

SOURCES	+= 	../src/utils/Logger.cpp \
            ../src/window/Window.cpp \
            ../src/file/File.cpp \
            ../src/file/FileContainer.cpp \
			../src/application/main.cpp

QMAKE_CXXFLAGS += -std=c++11

