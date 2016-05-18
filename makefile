CC       := g++
CXXFLAGS := `pkg-config --cflags --libs gtkmm-3.0`
CPPFLAGS := -Iclasses/
SRCS     := $(wildcard classes/source/*.cc)
OBJS     := $(SRCS:classes/source/%.cc=build/release/objs/%.o)
Os       := $(build/release/objs/$(wildcard *.o))
OUTPUT   := game_of_life

.PHONY: all
all: $(OBJS) | compile_main
clean:
	rm -rf build

$(OBJS): build/release/objs/%.o: classes/source/%.cc | build/release/objs
	    $(COMPILE.cc) $(OUTPUT_OPTION) $<

build/release/objs: ; mkdir -p $@

compile_main:
	$(CC) $(CPPFLAGS) -o build/release/$(OUTPUT) main.cc $(OBJS) $(CXXFLAGS)
