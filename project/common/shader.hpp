#ifndef SHADER_HPP
#define SHADER_HPP  

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>

class Shader
{
    public:
        unsigned int id;

        Shader(const char *vp, const char *fp);
        unsigned int fCompileShader(const unsigned int gShaderType, const std::string s);
        void shaderUse();
        ~Shader();
};

#endif