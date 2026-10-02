CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Usage: make run EX=classes/exercise1
EX  ?=
SRC := $(wildcard $(EX)/*.cpp)
BIN := $(EX)/main.exe

.PHONY: build run clean check

check:
ifeq ($(EX),)
	$(error Specify an exercise, e.g. make run EX=classes/exercise1)
endif

build: check $(BIN)

$(BIN): $(SRC) $(wildcard $(EX)/*.h)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

run: build
	./$(BIN)

clean:
	find . -name '*.exe' -delete
