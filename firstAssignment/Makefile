############################################### MAKEFILE FOR THE FIRST PACS CHALLENGE ################################################################
# get all files *.cpp
SRCS=$(wildcard *.cpp)
# get the corresponding object file
OBJS = $(SRCS:.cpp=.o)
# get all headers in the working directory
HEADERS=$(wildcard *.hpp)
#
exe_sources=$(filter main%.cpp,$(SRCS))
EXEC=$(exe_sources:.cpp=)

CXXFLAGS+=-I/home/jellyfish/shared-folder/Examples/src/LinearAlgebraUtil/ -I/home/jellyfish/shared-folder/Examples/src/Utilities/ \
	  -I/home/jellyfish/shared-folder/Examples/include -std=c++20
LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH))
#-----------------------------------------------

.phony= all clean

.DEFAULT_GOAL = all

all: $(EXEC)

clean:
	rm -f $(EXEC) $(OBJS)

$(EXEC): $(OBJS)
	g++ -std=c++20  -o main $(OBJS) -L/home/jellyfish/shared-folder/Examples/lib -lmuparser -Wl,-rpath=/home/jellyfish/shared-folder/Examples/lib

$(OBJS): $(SRCS) $(HEADERS)
