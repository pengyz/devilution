#pragma once
#include <GL/glew.h>
#include <glm/common.hpp>
#include <string>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	/*template<typename T>
	bool setUniform(const std::string& name, T value)
	{
		auto location = glGetUniformLocation(m_program, name.c_str());
		if (-1 == location) {
			return false;
		}
		switch (constexpr typeid(T).hash_code()) {
		case typeid(GLuint).hash_code(): {
			glUniform1ui(location, value);
		}break;
		case typeid(GLint).hash_code():
			case typeid(bool) : {
				glUniform1i(location, value);
			}break;
			case typeid(GLfloat).hash_code(): {
				glUniform1f(location, value);
			}break;
			case typeid(GLdouble).hash_code(): {
				glUniform1d(location, value);
			}break;
			default:
				return false;
				break;
		}
		return true;
	}*/
	bool setUniform(int location, glm::vec2 vec);
	bool setUniform(const std::string& name, glm::vec2 vec);
	bool setUniform(int location, glm::vec3 vec);
	bool setUniform(const std::string& name, glm::vec3 vec);
	bool setUniform(int location, glm::vec4 vec);
	bool setUniform(const std::string& name, glm::vec4 vec);
	bool setUniform(int location, glm::mat4 mat4, bool bNormalize = false);
	bool setUniform(const std::string& name, glm::mat4 mat4, bool bNormalize = false);

	bool setUniform(int location, GLint value);
	bool setUniform(const std::string& name, GLint value);


private:
	void clearShaders();

private:
	GLuint m_program = 0;
	std::map<GLenum, GLuint> m_shaderMap;
};
