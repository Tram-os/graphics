#version 330 core
in vec3 aPos;
in vec2 texCoord;

out vec2 v_TexCoord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    v_TexCoord = texCoord;
}