#include "../common/shader.hpp"

static std::string readShader(const char *glsl)
{
    std::ifstream shader(glsl);
    std::stringstream ss;
    
    ss << shader.rdbuf();
    return ss.str();
}

unsigned int Shader::fCompileShader(const unsigned int gShaderType, const std::string s)
{
    unsigned int gShader = glCreateShader(gShaderType);
    const char *gShaderS = s.c_str();

    glShaderSource(gShader, 1, &gShaderS, nullptr);
    glCompileShader(gShader);

    return gShader;
}

Shader::Shader(const char *vp, const char *fp)
{
    const std::string vs = readShader(vp);
    const std::string fs = readShader(fp);

    unsigned int compileVshader = fCompileShader(GL_VERTEX_SHADER, vs);
    unsigned int compileFshader = fCompileShader(GL_FRAGMENT_SHADER, fs);

    id = glCreateProgram();
    glAttachShader(id, compileVshader);
    glAttachShader(id, compileFshader);
    glLinkProgram(id);

    glDeleteShader(compileVshader);
    glDeleteShader(compileFshader);
}

Shader::~Shader()
{
    if(id) { glDeleteProgram(id); }
}

void Shader::shaderUse()
{
    glUseProgram(id);
}