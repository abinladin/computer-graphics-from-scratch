CC := clang

INCLUDE_DIRS := -I ./include
LINK_DIRS := -L ./lib/SDL2 
LIBS := -lSDL2
OPT := -O0

CFLAGS := $(INCLUDE_DIRS) $(OPT)
LDFLAGS := $(LINK_DIRS) $(LIBS)

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

BINARY := $(BIN_DIR)/main

all: directories $(BINARY)

$(BINARY): $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)