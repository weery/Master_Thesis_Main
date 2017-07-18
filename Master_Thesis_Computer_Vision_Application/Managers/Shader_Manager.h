#pragma once 

#include "glew.h"
#include <QString>
#include <map>
#include <vector>

namespace Managers
{
	class Shader_Manager
	{
	public:
		Shader_Manager();
		~Shader_Manager();

		void Initialize();
		bool LoadAndCompileShaders(
			const QString& shaderName,
			const QString& vertexShaderName,
			const QString& tesselationControlName,
			const QString& tesselationEvaluationName,
			const QString& geometryShaderName,
			const QString& fragmentShaderName,
			const QString& computeShaderName);
		GLuint GetShaderProgram(const QString& shaderName);

	private:
		QString LoadShaderCode(const QString& fileName);
		static const QString ShaderResourceLocation;
		GLuint CompileShader(GLenum shaderType,
			const QString& sourceCode,
			const QString& shaderName);
		static std::map<QString, GLuint> _shader_maps;


	};
}