# THE NEXT THREE LINE OF CODE SHOULD BE CHANGED TO FIT THE ENVIROMENT
PACS-ROOT = /home/matteo/Desktop/PACS/pacs-examples

CXX = g++
CXXFLAGS += -std=c++20 -Wall

CPPFLAGS += -I../include \
-I$(PACS-ROOT)/Examples/include \
-I$(PACS-ROOT)/Examples/src/Derivatives
LDLIBS += -L$(PACS-ROOT)/Examples/lib -lmuparser -Wl,-rpath=$(PACS-ROOT)/Examples/lib
LINK.o = $(LINK.cc)

SRCS=$(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADERS=$(wildcard *.hpp)
exe_sources=$(filter main%.cpp,$(SRCS))
EXEC=$(exe_sources:.cpp=)

.PHONY = all clean run

.DEFAULT_GOAL = all

all: $(EXEC)

clean:
	$(RM) $(EXEC) $(OBJS)

$(EXEC): $(OBJS)

$(OBJS): $(SRCS)

run: all
	./$(EXEC)
