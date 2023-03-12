############################################### MAKEFILE FOR THE FIRST PACS CHALLENGE ################################################################
# get all files *.cpp
SRCS=$(wildcard *.cpp)
# get the corresponding object file
OBJS = $(SRCS:.cpp=.o)
# get all headers in the working directory
HEADERS=$(wildcard *.h)
#
exe_sources=$(filter main%.cpp,$(SRCS))
EXEC=$(exe_sources:.cpp=)

CXXFLAGS+=-I/home/jellyfish/shared-folder/Examples/src/LinearAlgebraUti -I/home/jellyfish/shared-folder/Examples/include/
#-----------------------------------------------
.phony= all clean

.DEFAULT_GOAL = all

all: $(EXEC)

clean:
	rm -f $(EXEC) $(OBJS)
	
$(EXEC): $(OBJS)
	g++ -o main $(OBJS)

$(OBJS): $(SRCS) $(HEADERS)







