###########################################################
# @author {\_Sidewinder22_/}
# @date 11.11.2020
###########################################################

TEMPLATE = app
TARGET = SFe
INCLUDEPATH += src

# Input

QT              += widgets

DEFINES         += "DEBUG=1"

#HEADERS         += ../src/*.hpp

SOURCES         += ../src/*.cpp

QMAKE_CXXFLAGS  += -std=c++20 -Wall -Wextra

QMAKE_LIBS      += -lstdc++fs
