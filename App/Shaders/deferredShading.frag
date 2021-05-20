#version 330 core
layout(location = 0) out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedoSpec;

struct PointLight 
{
    vec3 Position;
    vec3 Color;
    float Linear;
    float Quadratic;
};

struct DirectionalLight
{
    vec3 Color;
    vec3 Direction;
};

const int NR_LIGHTS = 10;
float shininess = 30;
uniform PointLight PointLights[NR_LIGHTS];
uniform DirectionalLight DirectionalLights[NR_LIGHTS];
uniform vec3 viewPos;

void main()
{             
    vec3 FragPos = texture(gPosition, TexCoords).rgb;
    vec3 Normal = texture(gNormal, TexCoords).rgb;
    vec3 Diffuse = texture(gAlbedoSpec, TexCoords).rgb;
    float Specular = texture(gAlbedoSpec, TexCoords).a;
    
    vec3 lighting  = Diffuse * 0.3;
    vec3 normal = normalize(Normal);
    vec3 viewDir  = normalize(viewPos - FragPos);

    for(int i = 0; i < NR_LIGHTS; ++i)
    {
        vec3 lightDir = normalize(PointLights[i].Position - FragPos);
        vec3 auxDiffuse = dot(Normal, lightDir) * Diffuse * PointLights[i].Color;
        vec3 diffuse = clamp(auxDiffuse, 0.0, 1.0);
        
        vec3 halfwayDir = normalize(lightDir + viewDir);  
        float spec = pow(max(dot(Normal, halfwayDir), 0.0), shininess);
        vec3 specular = PointLights[i].Color * spec * Specular;
        
        float distance = length(PointLights[i].Position - FragPos);
        float attenuation = 1.0 / (1.0 + PointLights[i].Linear * distance + PointLights[i].Quadratic * distance * distance);
        diffuse *= attenuation;
        specular *= attenuation;
        lighting += diffuse + specular;  
    }

    for(int i = 0; i < NR_LIGHTS; ++i)
    {
        vec3 lightDir = normalize(DirectionalLights[i].Direction);  
        vec3 auxDiffuse = dot(normal, lightDir) * Diffuse * DirectionalLights[i].Color;
        vec3 diffuse = clamp(auxDiffuse, 0.0, 1.0);

        vec3 reflection = normalize(reflect(-lightDir, normal));
        vec3 vector = normalize(vec3(0) - FragPos);
        float spec = dot(reflection, vector);
        spec = pow(max(spec,0), shininess);
        vec3 specular = clamp(DirectionalLights[i].Color * spec * Specular, 0, 1);
        
        lighting += diffuse + specular;

    }
    FragColor = vec4(lighting, 1.0);
}