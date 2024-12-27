bin			?= day1
dir			:= $(bin)

obj			:= ${bin:=.o}
src			:= ${bin:=.cpp}

cmndir			:= cmn
cmnsrcs			:= $(wildcard $(cmndir)/*.cpp)
cmnobjs			:= $(patsubst %.cpp, %.o, $(cmnsrcs))
cmnarch			:= $(cmndir)/cmn.a

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

$(dir)/$(bin): $(cmnarch) $(dir)/$(obj)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(dir)/$(obj): $(dir)/$(src)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(cmnarch): $(cmnobjs)
	ar rcs $@ $^

.PHONY: clean
clean:
	@rm -Rf $(dir)/$(bin) $(dir)/$(obj) $(cmnarch)
