#version 330 core

out vec4 fo_Color;
in vec4 vo_Color;
void main()
{
	fo_Color = vo_Color;
};