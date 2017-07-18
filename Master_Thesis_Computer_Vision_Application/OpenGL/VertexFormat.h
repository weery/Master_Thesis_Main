#pragma once

#include "glm\glm.hpp"

namespace OpenGL
{
	struct VertexFormat
	{
		glm::vec3 position;
		glm::vec2 textureCoordinates;

		VertexFormat(const glm::vec3& pos, const glm::vec2& texCoord)
		{
			position = pos;
			textureCoordinates = texCoord;
		}
	};
}