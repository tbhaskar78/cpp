SRC := lang
BIN := bin
CPP := g++
SOURCES := $(wildcard $(SRC)/*.cpp)
BINS := $(patsubst $(SRC)/%.cpp, $(BIN)/%, $(SOURCES))

createBinDir:
	@if [ ! -d $(BIN) ] ; then mkdir -p $(BIN) ; fi

# set dependencies on createBinDir and BINS
all: createBinDir $(BINS) 

# Wild card build of all files, created under bin folder
$(BIN)/%: $(SRC)/%.cpp
	$(CPP) -std=c++17 $< -o $@

clean:
	@rm -rf bin
