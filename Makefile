.PHONY: all clean test debug log prepare

CXX := g++
CXXFLAGS = -Wall -Wextra -std=c++2c
CXXLIBS := -lwkhtmltox


SRC_EXT := .cpp
HDR_EXT := .hpp
OBJ_EXT := .o
BUILD_DIR := ./build/
SRC_DIR := ./src/

PROJECTNAME := $(shell basename $(PWD))
SRCS := $(wildcard $(SRC_DIR)*$(SRC_EXT))
OBJS := $(SRCS:$(SRC_DIR)%$(SRC_EXT)=$(BUILD_DIR)%$(OBJ_EXT))

ifneq (,$(filter debug,$(MAKECMDGOALS)))
    CXXFLAGS += -DDEBUGGING
    DO_CLEAN = true
endif
debug: all
	@:


ifneq (,$(filter log,$(MAKECMDGOALS)))
    CXXFLAGS += -DLOGGING
    DO_CLEAN = true
endif
log: all
	@:

all: prepare $(BUILD_DIR)$(PROJECTNAME)

prepare:
ifdef DO_CLEAN
	@echo "Changement de mode détecté : Nettoyage forcé..."
	@rm -rf $(BUILD_DIR)/*.o
endif
	@mkdir -p $(BUILD_DIR)



$(BUILD_DIR)$(PROJECTNAME) :$(OBJS)
	@echo "Linking $(PROJECTNAME)..."
	$(CXX) $(OBJS) -o $(BUILD_DIR)$(PROJECTNAME)


$(BUILD_DIR)%$(OBJ_EXT): $(SRC_DIR)%$(SRC_EXT) | prepare
	@echo "Compiling $@..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@


test: $(SRCS)
	@echo $(shell seq 1 10 )
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(PROJECTNAME)
	@echo $(MAKECMDGOALS)

clean:
	@echo "Cleaning ./build repository..."
	rm -rf ./build/*
	@echo "Build is now clean!"