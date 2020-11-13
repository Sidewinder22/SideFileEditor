###########################################################
# @author {\_Sidewinder22_/}
# @date 11.11.2020
###########################################################

TEMPLATE = app
TARGET = SFe
INCLUDEPATH += src

# Input

QT              +=  widgets

DEFINES         +=  "DEBUG=1"

HEADERS         +=  ../src/*.hpp \
                    ../src/ctrl/*.hpp \
                    ../src/log/*.hpp \
                    ../src/view/*.hpp

SOURCES         +=  ../src/*.cpp \
                    ../src/ctrl/*.cpp \
                    ../src/log/*.cpp \
                    ../src/view/*.cpp

QMAKE_CXXFLAGS  +=  -std=c++20 \
                    -Wall \
                    -Wextra

QMAKE_LIBS      +=  -lstdc++fs
