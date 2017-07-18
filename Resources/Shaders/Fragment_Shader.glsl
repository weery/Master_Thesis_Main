#version 330 core
layout(location = 0) out vec4 out_color;

in vec2 out_texCoord;

uniform sampler2D texture1;
uniform ivec3 colorSpaceUsage;
uniform int oneChannel;

// Color space conversion functions
vec3 RGB2HSI(vec3);
float RGB2MSAVI(vec3, bool);
float RGB2MSAVI2(vec3, bool);
float RGB2NDVI(vec3, bool);
float RGB2SAVI(vec3, bool);

void main()
{
	float colorSpaces[14];
	vec3 rgbColor = vec3(texture(texture1,out_texCoord));
	colorSpaces[0]= rgbColor.x;
	colorSpaces[1]= rgbColor.y;
	colorSpaces[2]= rgbColor.z;

	vec3 hsiColor = RGB2HSI(rgbColor);
	colorSpaces[3]= hsiColor.x;
	colorSpaces[4]= hsiColor.y;
	colorSpaces[5]= hsiColor.z;

	colorSpaces[6] = RGB2SAVI(rgbColor,true); // SAVi green
	colorSpaces[7] = RGB2SAVI(rgbColor,false); // SAVI blue

	colorSpaces[8] = RGB2NDVI(rgbColor,true); // ndvi green
	colorSpaces[9] = RGB2NDVI(rgbColor,false); // ndvi blue

	colorSpaces[10] = RGB2MSAVI(rgbColor,true); // msavi green
	colorSpaces[11] = RGB2MSAVI(rgbColor,false); // msavi blue

	colorSpaces[12] = RGB2MSAVI2(rgbColor,true); // msavi2 green
	colorSpaces[13] = RGB2MSAVI2(rgbColor,false); // msavi2 blue

	out_color = vec4(0.0f,0.0f,0.0f,1.0f);
	if (colorSpaceUsage[0] > -1 || colorSpaceUsage[0] < 14 )
		out_color[0] = colorSpaces[colorSpaceUsage[0]];
	if (colorSpaceUsage[1] > -1 || colorSpaceUsage[1] < 14)
		out_color[1] = colorSpaces[colorSpaceUsage[1]];
	if (colorSpaceUsage[2] > -1 || colorSpaceUsage[2] < 14)
		out_color[2] = colorSpaces[colorSpaceUsage[2]];

	if(oneChannel <1)
	{
		out_color[1] = out_color[0];
		out_color[2] = out_color[0];
	}
}

vec3 RGB2HSI(vec3 rgbColor)
{
	float R = rgbColor[0];
	float G = rgbColor[1];
	float B = rgbColor[2];

	float M = max(max(R,G),B);

	float m = min(min(R, G),B);

	float C =M-m;

	float Hprime = 0;
	if (C==0)
		Hprime = 0;
	else if (M==R)
		Hprime = (G-B)/C;
		if (Hprime > 6)
		{
			Hprime -= 6;
		}
	else if (M==G)
		Hprime = (B-R)/C +2;
	else
		Hprime = (R-G)/C +4;

	float H = Hprime / 6;

	float I = (R+G+B)/3;

	float S = 0;
	if (I > 0)
		S = 1-m/I;

	return vec3(H,S,I);
}

float RGB2MSAVI(vec3 in_color, bool useGreen)
{
	float r,g,b;
	r=in_color.x;
	g=in_color.y;
	b=in_color.z;

	float s = 0.75; // STRENGTH Parameter
	float bg= g;
	if (!useGreen)
		bg= b;

	float L = 1.0f-2.0f*s*(r-bg)*(r-bg*s)/(r+bg);

	float MSAVI = (r-bg)/(r+bg+L)*(L+1);

	return MSAVI;
}

float RGB2MSAVI2(vec3 in_color, bool useGreen)
{
	float r,g,b;
	r=in_color.x;
	g=in_color.y;
	b=in_color.z;

	float term= (2.0f*r+1.0f);

	float bg = g;
	if (!useGreen)
		bg = b;

	float sq_term = term*term -2.0f*(r-bg);

	float MSAVI2 = (term-sqrt(sq_term))/2.0f;

	return MSAVI2;
}

float RGB2NDVI(vec3 in_color, bool useGreen)
{
	float r,g,b;
	r=in_color.x;
	g=in_color.y;
	b=in_color.z;

	float gb = g;
	if (!useGreen)
		gb = b;

	float L = 0.0f; // With L = 0 => nDVI, L = 1 => SAVI

	float NDVI = (r)/(r+gb+L)*(L+1);

	return NDVI;
}

float RGB2SAVI(vec3 in_color, bool useGreen)
{
	float r,g,b;
	r=in_color.x;
	g=in_color.y;
	b=in_color.z;

	float gb = g;
	if (!useGreen)
		gb = b;
	float L = 1.0f; // With L = 0 => nDVI, L = 1 => SAVI

	float SAVI = (r)/(r+gb+L)*(L+1);

	return SAVI;
}
