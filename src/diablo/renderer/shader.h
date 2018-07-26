#pragma once
#include <GL/glew.h>
#include <glm/common.hpp>
#include <string>
#include <map>

class Shader {
public:
    Shader();
    Shader(const std::string& vertSource, const std::string& fragSource);
    ~Shader();

public:
    bool attachShaderSource(GLenum shaderType, const std::string& shaderSource, std::string* log = nullptr);
    bool attachShaderFile(GLenum shaderType, const std::string& shaderFilePath, std::string* log = nullptr);
    bool compile(std::string* log = nullptr);
    void use();
    void unuse();
public:
    template<typename T>
    bool setUniform(const std::string& name, T value)
    {
        auto location = glGetUniformLocation(m_program, name.c_str());
        if (-1 == location) {
            return false;
        }
        switch (typeid(T)) {
            case typeid(GLuint) : {
                glUniform1ui(location, value);
            }break;
                case typeid(GLint) :
                    case typeid(bool) : {
                    glUniform1i(location, value);
                }break;
                    case typeid(GLfloat) : {
                        glUniform1f(location, value);
                    }break;
                        case typeid(GLdouble) : {
                            glUniform1d(location, value);
                        }break;
                        default:
                            return false;
                            break;
        }
        return true;
    }
    bool setUniform(const std::string& name, glm::vec2 vec);
    bool setUniform(const std::string& name, glm::vec3 vec);
    bool setUniform(const std::string& name, glm::vec4 vec);

private:
    void clearShaders();

private:
    GLuint m_program = 0;
    std::map<GLenum, GLuint> m_shaderMap;
};
