src = $(wildcard *.cpp) \
	$(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lGL -lz -lm

build: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) build	

