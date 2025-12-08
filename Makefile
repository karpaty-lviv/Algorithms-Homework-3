CXX      = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -O3

SRC_DIR   = src
BUILD_DIR = build


ifeq ($(OS),Windows_NT)
    TARGET_NAME = scc_app.exe
    MKDIR_CMD   = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
    RM_FILES    = del /Q $(BUILD_DIR)\*.o
    RM_DIR      = rmdir /Q /S $(BUILD_DIR)
    RM_TARGET   = if exist $(TARGET_NAME) del $(TARGET_NAME)
    FIX_PATH    = $(subst /,\,$1)
else
    TARGET_NAME = scc_app
    MKDIR_CMD   = mkdir -p $(BUILD_DIR)
    RM_FILES    = rm -f $(BUILD_DIR)/*.o
    RM_DIR      = rm -rf $(BUILD_DIR)
    RM_TARGET   = rm -f $(TARGET_NAME)
endif


SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))


all: directories $(TARGET_NAME)

$(TARGET_NAME): $(OBJS)
	@echo Linking...
	$(CXX) $(OBJS) -o $(TARGET_NAME)
	@echo ---------------------------------------
	@echo Build successful! Run with: ./$(TARGET_NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Compiling $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

directories:
	@$(MKDIR_CMD)


clean:
	@echo Cleaning up...
	-@$(RM_FILES)
	-@$(RM_DIR)
	-@$(RM_TARGET)
	@echo Cleaned.


run: all
	./$(TARGET_NAME)

.PHONY: all clean run directories