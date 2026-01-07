SRC = src/main.cpp src/shader.cpp src/glad.c
BIN = shaderPlay
CXX = g++
CXXFLAGS = -Iinclude

#-lGL -lGLEW -lglfw

all: my_program
my_program: 
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SRC) -lGL -lGLEW -lglfw

run: my_program
	./$(BIN)

clean:
	rm -f $(BIN)