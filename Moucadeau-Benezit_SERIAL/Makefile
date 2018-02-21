SHELL    = /bin/bash

ifeq ($(CXX),)
CXX=g++
endif
CFLAGS   = -g -Wall -W -ansi -pedantic -O2
CXXFLAGS = $(CFLAGS) -std=c++11
LIBS     = -L/usr/X11R6/lib -lX11 -lXext -lpthread
RM       = rm -f

EXECSPP = SERV

all :: $(EXECSPP)

.cpp.o :
	$(CXX) -c $(CXXFLAGS) $*.cpp

$(EXECSPP): client_serial server_serial

client_serial : client_serial.o cli_req.o monomial.o polynomial.o
	$(CXX) -o $@ $^ $(LIBS)

server_serial : server_serial.o serv_req.o monomial.o polynomial.o
	$(CXX) -o $@ $^ $(LIBS)

depends :
	$(CXX) -MM $(CXXFLAGS) *.cpp >depends

clean ::
	$(RM) *.o core

distclean :: clean
	$(RM) *% *~ .*.swp $(EXECSPP)

include depends
