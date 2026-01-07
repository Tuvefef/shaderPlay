#ifndef UNIFORM_H
#define UNIFORM_H

#include <glad/glad.h>
#include <cgm/cgm.h>

static void fComputeUniformVec3(unsigned int gId, const char *gName, const vec3 v0)
{
    glUniform3f(glGetUniformLocation(gId, gName), v0.x, v0.y, v0.z);
}

#endif