#version 460 core
out vec4 FragColor;

in vec3 v_worldPos;
in vec3 v_normal;

uniform mat4 u_view;
float GetAttenuation(vec3 lightPos, vec3 fragPos, float lightRadius)
{
	vec3 lightDir = lightPos - fragPos;
	float dist = length(lightDir);
	float invSqr = 1.0 / (dot(lightDir, lightDir) + 1.0);
	float factor = dist/lightRadius;
	float smoothWindow = max(1.0 - factor * factor * factor * factor, 0.0);
	smoothWindow = smoothWindow * smoothWindow;
	return invSqr * smoothWindow;
}

void main()
{
	vec3 lightPos = vec3(-1, 1, -0.5);
	vec3 L = normalize(lightPos - v_worldPos);
	vec3 N = normalize(v_normal);
	float ndotl = dot(N, L);
	vec3 lightColor = vec3(0.5f, 0.0f, 0.0f);
	float lightIntensity = 2000;
	float lightRadius = 10.0;

	mat4 inverseView = inverse(u_view);
	vec3 camForward = inverseView[2].xyz;
	vec3 viewPos = inverseView[3].xyz;
	
	// Diffuse
	float dist = distance(lightPos, v_worldPos);
	float attenuation = GetAttenuation(lightPos, v_worldPos, lightRadius);
	vec3 diffuse = vec3(ndotl * attenuation * lightIntensity) * lightColor;	
	
	// Specular
	float specIntensity = 10.5f;
	vec3 viewDir = normalize(viewPos - v_worldPos);
	vec3 reflectDir = reflect(-L, N);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specIntensity * spec *  lightColor;

	// final fragment output
	vec3 lighting = diffuse * specular;
	FragColor = vec4(vec3(specular), 1.0);
}