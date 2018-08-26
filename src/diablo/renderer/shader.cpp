#include "shader.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>


Shader::Shader()
{
	m_program = glCreateProgram();
}


Shader::Shader(const std::string& vertSource, const std::string& fragSource)
	:Shader()
{
	assert(attachShaderSource(GL_VERTEX_SHADER, vertSource));
	assert(attachShaderSource(GL_FRAGMENT_SHADER, fragSource));
	assert(compile());
}


Shader::~Shader()
{
	clearShaders();
	if (m_program) {
		unuse();
		glDeleteProgram(m_program);
		m_program = 0;
	}
}

void Shader::clearShaders()
{
	for (const auto pair : m_shaderMap) {
		if (pair.second) {
			glDeleteShader(pair.second);
		}
	}
	m_shaderMap.clear();
}

#define ERROR_STRING(str)  if (log) { \
                            *log = str; \
                        } else { \
                            std::cout << str; \
                        }

bool Shader::attachShaderSource(GLenum shaderType, const std::string& shaderSource, std::string* log)
{
	if (m_shaderMap.find(shaderType) != m_shaderMap.end()) {
		ERROR_STRING("shader type already added !");
		return false;
	}
	int success;
	auto shaderId = glCreateShader(shaderType);
	auto shaderStr = shaderSource.c_str();
	glShaderSource(shaderId, 1, &shaderStr, nullptr);
	glCompileShader(shaderId);
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		if (log) {
			int iLen;
			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &iLen);
			log->resize(iLen);
			glGetShaderInfoLog(shaderId, iLen + 1, nullptr, log->data());
		}
	}
	glAttachShader(m_program, shaderId);
	m_shaderMap[shaderType] = shaderId;
	return success;
}

bool Shader::attachShaderFile(GLenum shaderType, const std::string& shaderFilePath, std::string* log)
{
	std::filesystem::path sourceFilePath(shaderFilePath);
	if (!std::filesystem::exists(sourceFilePath)) {
		ERROR_STRING("file not exist !");
		return false;
	}
	std::ifstream fin(sourceFilePath);
	if (!fin) {
		ERROR_STRING("open file failed !");
		return false;
	}
	std::stringstream ss;
	ss << fin.rdbuf();
	std::string strShader(ss.str());
	if (!strShader.length()) {
		ERROR_STRING("file content empty !");
		return false;
	}
	return attachShaderSource(shaderType, strShader.c_str(), log);
}

bool Shader::setUniform(int location, glm::vec3 vec)
{
	if (-1 == location) {
		return false;
	}
	glUniform3f(location, vec.x, vec.y, vec.z);
	return true;
}


bool Shader::setUniform(const std::string& name, glm::vec3 vec)
{
	auto location = glGetUniformLocation(m_program, name.c_str());
	return setUniform(location, vec);
}

bool Shader::setUniform(int location, glm::vec4 vec)
{
	if (-1 == location) {
		return false;
	}
	glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
	return true;
}


bool Shader::setUniform(const std::string& name, glm::vec4 vec)
{
	auto location = glGetUniformLocation(m_program, name.c_str());
	return setUniform(location, vec);
}

bool Shader::setUniform(int location, glm::vec2 vec)
{
	if (-1 == location) {
		return false;
	}
	glUniform2f(location, vec.x, vec.y);
	return true;
}

bool Shader::setUniform(const std::string& name, glm::vec2 vec)
{
	auto location = glGetUniformLocation(m_program, name.c_str());
	return setUniform(location, vec);
}

bool Shader::setUniform(int location, glm::mat4 mat4, bool bNormalize)
{
	if (-1 == location)
		return false;
	glUniformMatrix4fv(location, 1, bNormalize ? GL_TRUE : GL_FALSE, glm::value_ptr(mat4));
	return true;
}

bool Shader::setUniform(const std::string& name, glm::mat4 mat4, bool bNormalize)
{
	auto location = glGetUniformLocation(m_program, name.c_str());
	return setUniform(location, mat4, bNormalize);
}

bool Shader::setUniform(int location, GLint value)
{
	if (-1 == location) {
		return false;
	}
	glUniform1i(location, value);
	return true;
}

bool Shader::setUniform(const std::string& name, GLint value)
{
	auto location = glGetUniformLocation(m_program, name.c_str());
	return setUniform(location, value);
}


void Shader::use()
{
	assert(m_program);
	glUseProgram(m_program);
}

void Shader::unuse()
{
	glUseProgram(0);
}

bool Shader::compile(std::string* log)
{
	GLint success;
	glLinkProgram(m_program);
	clearShaders();
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (!success) {
		if (log) {
			int iLen = 0;
			glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &iLen);
			log->resize(iLen);
			glGetProgramInfoLog(m_program, iLen, nullptr, log->data());
		}
	}
	return success;
}
