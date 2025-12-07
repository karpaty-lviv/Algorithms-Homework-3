CXX      = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -g

SRC_DIR   = src
BUILD_DIR = build

TARGET    = scc_app.exe

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

all: create_dir $(TARGET)

$(TARGET): $(OBJS)
	@echo Linking...
	$(CXX) $(OBJS) -o $(TARGET)
	@echo Build successful! Run with: ./$(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Compiling $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

create_dir:
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

clean:
	@echo Cleaning up...
	@if exist $(BUILD_DIR) del /Q $(BUILD_DIR)\*.o
	@if exist $(BUILD_DIR) rmdir $(BUILD_DIR)
	@if exist $(TARGET) del $(TARGET)

run: all
	./$(TARGET)