####################################### MAKEFILE FOR THE FIRST PACS CHALLENGE ################################################################
 
CXX ?= g++

CXXFLAGS += -std=c++20 -Wall -Wextra -I../Include/ -I../Include/muParser/

LDFLAGS += -Wl,-rpath=../../../Examples/lib  # you should change these paths with your local paths 								    to link against muparser library
LDLIBS += -L../../../Examples/lib -lmuparser # to link against muparser library


LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

# get all files *.cpp
SRCS := $(wildcard *.cpp)

# get the corresponding object file
OBJS := $(SRCS:.cpp=.o)

# get all headers in the working directory
HEADERS := $(wildcard *.hpp)

# build the executable 
exe_sources = $(filter main%.cpp,$(SRCS))
EXEC = $(exe_sources:.cpp=)

#-----------------------------------------------

.PHONY: all clean

.DEFAULT_GOAL = all

clean:
	$(RM) $(EXEC) $(OBJS)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c
	
$(EXEC): $(OBJS)
	$(LINK.o) $(LDLIBS) $(OBJS) -o main

all: $(EXEC)
