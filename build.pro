######################################################################
# Automatically generated by qmake (3.0) wt. wrz 20 00:53:28 2016
######################################################################

TEMPLATE = app
TARGET = SideFileEditor
INCLUDEPATH += src

# Input

QT      += widgets

# DEFINES +=  "DEBUG=1"

HEADERS +=  src/app/*.hpp \
            src/common/*.hpp \
            src/file/*.hpp \
            src/log/*.hpp \
            src/gui/*.hpp \
            src/gui/command/*.hpp

SOURCES +=  src/app/*.cpp \
            src/common/*.cpp \
            src/file/*.cpp \
            src/log/*.cpp \
            src/gui/*.cpp \
            src/gui/command/*.cpp

QMAKE_CXXFLAGS += -std=c++2a -Wextra

QMAKE_LIBS += -lstdc++fs

