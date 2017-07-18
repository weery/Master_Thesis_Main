#include "Shader_Manager.h"
#include <iostream>
#include <fstream>

using namespace Managers;

//const QString Shader_Manager::ShaderResourceLocation = 
//	"d:/programming/Master_Thesis/Master_Thesis_Computer_Vision_Application/Resources/Shaders/";

const QString Shader_Manager::ShaderResourceLocation =
	"./Resources/Shaders/";

//const QString Shader_Manager::ShaderResourceLocation =
//"../Resources/Shaders/";
std::map<QString, GLuint> Shader_Manager::_shader_maps;

Shader_Manager::Shader_Manager() {}

Shader_Manager::~Shader_Manager() 
{
	std::map<QString, GLuint>::iterator i;
	for (i = _shader_maps.begin(); i != _shader_maps.end(); i++)
	{
		GLuint program = i->second;
		glDeleteProgram(program);
	}
	_shader_maps.clear();
}

void Shader_Manager::Initialize() 
{
	glewInit();
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		std::cout << "Main error : " << error << std::endl;
	}


	QString vertex_shader_location = ShaderResourceLocation + "Vertex_Shader.glsl";
	QString fragment_shader_location = ShaderResourceLocation + "Fragment_Shader.glsl";

	LoadAndCompileShaders("colorTexturedShader", vertex_shader_location, "", "",
		"", fragment_shader_location, "");
}

bool Shader_Manager::LoadAndCompileShaders(
	const QString& shaderName,
	const QString& vertexShaderName,
	const QString& tesselationControlName,
	const QString& tesselationEvaluationName,
	const QString& geometryShaderName,
	const QString& fragmentShaderName,
	const QString& computeShaderName) 
{
	

	bool useVertexShader = (vertexShaderName != "");
	bool useTesselationcControl = (tesselationControlName != "");
	bool useTesselationEvaluation = (tesselationEvaluationName != "");
	bool useGeometryShader = (geometryShaderName != "");
	bool useFragmentShader = (fragmentShaderName != "");
	bool useComputeShader = (computeShaderName != "");

	int link_result = 0;

	GLuint shaderProgram = glCreateProgram();

	if (useVertexShader)
	{
		QString vertex_shader_code = LoadShaderCode(vertexShaderName);
		GLuint vertex_shader = CompileShader(GL_VERTEX_SHADER,
			vertex_shader_code, "Vertex_Shader");
		glAttachShader(shaderProgram, vertex_shader);
	}
	if (useTesselationcControl)
	{
		QString tesselation_control_code = LoadShaderCode(tesselationControlName);
		GLuint tesselation_control_shader = CompileShader(GL_TESS_CONTROL_SHADER,
			tesselation_control_code, "Tesselation_Control");
		glAttachShader(shaderProgram, tesselation_control_shader);
	}
	if (useTesselationEvaluation)
	{
		QString tesselation_evaluation_code = LoadShaderCode(tesselationEvaluationName);
		GLuint tesselation_evaluation_shader = CompileShader(GL_TESS_EVALUATION_SHADER,
			tesselation_evaluation_code, "Tesselation_Evalutaion");
		glAttachShader(shaderProgram, tesselation_evaluation_shader);
	}

	if (useGeometryShader)
	{
		QString geometry_shader_code = LoadShaderCode(geometryShaderName);
		GLuint geometry_shader = CompileShader(GL_GEOMETRY_SHADER,
			geometry_shader_code, "Geometry_Shader");
		glAttachShader(shaderProgram, geometry_shader);
	}
	if (useFragmentShader)
	{
		QString fragment_shader_code = LoadShaderCode(fragmentShaderName);
		GLuint fragment_shader = CompileShader(GL_FRAGMENT_SHADER,
			fragment_shader_code, "Fragment_Shader");
		glAttachShader(shaderProgram, fragment_shader);
	}
	if (useComputeShader)
	{
		QString compute_shader_code = LoadShaderCode(computeShaderName);
		GLuint compute_shader = CompileShader(GL_COMPUTE_SHADER,
			compute_shader_code, "Compute_Shader");
		glAttachShader(shaderProgram, compute_shader);
	}

	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &link_result);
	if (link_result == GL_FALSE)
	{
		int info_log_length = 0;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> program_log(info_log_length);
		if (program_log.size() > 0)
		{
			glGetProgramInfoLog(shaderProgram, info_log_length, NULL, &program_log[0]);
			std::cout << "Shader Loader: LINK ERROR " << std::endl;
			std::cout << &program_log[0] << std::endl;
		}
		return false;
	}

	glValidateProgram(shaderProgram);

	if (_shader_maps.find(shaderName) != _shader_maps.end())
	{
		std::cout << "Shader Loader : Loading Erro, shader already loaded " << std::endl;
		std::cout << &shaderName << std::endl;
		return false;
	}

	_shader_maps[shaderName] = shaderProgram;
	return true;
}

GLuint Shader_Manager::GetShaderProgram(const QString& shaderName) 
{
	if (_shader_maps.find(shaderName) != _shader_maps.end())
		return _shader_maps[shaderName];
	return 0;

}

QString Shader_Manager::LoadShaderCode(const QString& fileName)
{
	std::string shaderCode;
	std::ifstream file(fileName.toStdString(), std::ios::in);

	// maybe i should enable error handling
	if (!file.good())
	{
		std::cout << "Invalid Shader file: " << fileName.toStdString() << std::endl;
		return "";
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();

	return QString::fromStdString(shaderCode);
}


GLuint Shader_Manager::CompileShader(GLenum shaderType,
	const QString& sourceCode,
	const QString& shaderName) {

	int result = 0;

	GLuint shader = glCreateShader(shaderType);
	std::string data = sourceCode.toStdString();
	const char* shader_code_ptr = (char*)data.c_str();
	const int shader_code_size = sourceCode.size();


	glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		std::cout << "Shader Manager: " << error << std::endl;
	}
	// Who t.f. cares about errors
	if (result == GL_FALSE)
	{
		std::cout << "Error in compiling shader " << error << std::endl;
		glDeleteShader(shader);
		return 0;
	}

	return shader;
}