#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <unordered_map>

class Shader
{
private:
    unsigned int m_RendererID;
    std::string m_VertexPath;
    std::string m_FragmentPath;

    //caching for uniforms
    std::unordered_map<std::string, int> m_UniformLocationCache;

public:

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    // Set uniforms
    void SetUniform1i(const std::string& name, int value);
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

    inline const unsigned int getID() { return m_RendererID; }

private:

    void checkCompileErrors(unsigned int shader, std::string type);
    int GetUniformLocation(const std::string& name);
};

#endif