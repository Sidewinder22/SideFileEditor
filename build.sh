#!/usr/bin/bash

RED='\e[0;31m'
YELLOW='\e[0;33m'
MAGENDA='\e[0;35m'
CYAN='\e[0;36m'

LIGHT_YELLOW='\e[0;93m'
LIGHT_MAGENDA='\e[0;95m'

BOLD='\e[1m'
BLINK='\e[5m'
REVERSE='\e[7m'
NC='\e[0m'


echo -e "${LIGHT_YELLOW}${BOLD}${REVERSE}->>>- Starting build -<<<-${NC}"

if [ -d build ]; then
    echo -e "${LIGHT_MAGENDA}${BOLD}${REVERSE}-!- Build directory exists! -!-${NC}"
else
    mkdir build
fi

cd build

echo -e "${LIGHT_YELLOW}${BOLD}${REVERSE}-+- Invoking qmake -+-${NC}"
qmake-qt5 ..

echo -e "${CYAN}${BOLD}${REVERSE}-+- Build started... -+-${NC}"
make
if [ -f SideFileEditor ]; then
    echo -e "${GREEN}${BOLD}${REVERSE}-<<<- Application SFE is ready. Bye! ->>>-${NC}"
else
    echo -e "${RED}${BOLD}${REVERSE}${BLINK}-!!!- Error occured -!!!-${NC}"
fi
