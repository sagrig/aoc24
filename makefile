bin			?= day1
dir			:= $(bin)

obj			:= ${bin:=.o}
src			:= ${bin:=.cpp}

cmndir			:= cmn

CXX			:= g++

CXXFLAGS		:=
CXXFLAGS		+= -Wall
CXXFLAGS		+= -Wextra
CXXFLAGS		+= -pedantic
CXXFLAGS		+= -std=c++20
CXXFLAGS		+= -O2
CXXFLAGS		+= -I.
CXXFLAGS		+= -I$(dir)
CXXFLAGS		+= -I$(cmndir)

LDFLAGS			:=
LDFLAGS			+= -L.

$(dir)/$(bin): $(dir)/$(obj)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(dir)/$(obj): $(dir)/$(src)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -Rf $(dir)/$(bin) $(dir)/$(obj)
