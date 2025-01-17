# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -Og -Wall -Wextra -pedantic-errors -Wold-style-cast -fsanitize=leak
CXXFLAGS += -std=c++11 
CXXFLAGS += -g 
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g -fsanitize=leak
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = node_test test_graph_small test_nodeset test_dijkstra test_graph_nofile test_graph_file

all: $(PROGS)

test: 

# Targets rely on implicit rules for compiling and linking
node_test: node_test.o node.o edge.o
test_graph_small: test_graph_small.o node.o edge.o
test_nodeset: test_nodeset.o NodeSet.o Node.o Edge.o
test_dijkstra: test_dijkstra.o dijkstra.o NodeSet.o Node.o Edge.o
test_graph_nofile: test_graph_nofile.o dijkstra.o graph.o NodeSet.o Node.o Edge.o
test_graph_file: test_graph_file.o dijkstra.o graph.o NodeSet.o Node.o Edge.o

# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
