####################################### MAKEFILE FOR THE FIRST PACS CHALLENGE ################################################################
 
CXX ?= g++

CXXFLAGS += -std=c++20 -DCONVERGENCE_RATE=7 -Wall -Wextra -I../Include/ -I../Include/muParser/

LDFLAGS += -Wl,-rpath=../../../Examples/lib  # you should change these paths with your local paths 								    to link against muparser library
LDLIBS += -L../../../Examples/lib -lmuparser # to link against muparser library

LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

# get all files *.cpp
SRCS := $(wildcard *.cpp)

# get the corresponding object file
OBJS := $(SRCS:.cpp=.o)

# build the executable 
exe_sources = $(filter main%.cpp,$(SRCS))
EXEC = $(exe_sources:.cpp=)

# output file 
FILE := ../result.dat ../error_rate.dat

#-----------------------------------------------

.PHONY: all clean 

.DEFAULT_GOAL = all

clean:
	$(RM) $(EXEC) $(OBJS) $(FILE)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c
	
$(EXEC): $(OBJS)
	$(LINK.o) $(LDLIBS) $(OBJS) -o $(EXEC)

all: $(EXEC)



