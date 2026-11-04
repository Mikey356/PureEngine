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
	vec3 lightPos = vec3(0, 0.5, -1);
	vec3 L = normalize(lightPos - v_worldPos);
	vec3 N = normalize(v_normal);
	
	vec3 lightColor = vec3(.50196078431372549019607843137255, .0, .0);
	float lightIntensity = 1;
	float lightRadius = 10.0;
	
	float dist = distance(lightPos, v_worldPos);
	float attenuation = GetAttenuation(lightPos, v_worldPos, lightRadius);

	mat4 inverseView = inverse(u_view);
	vec3 camForward = inverseView[2].xyz;
	vec3 viewPos = inverseView[3].xyz;
	
	// Diffuse
	float ndotl = dot(N, L);
	vec3 diffuse = vec3(ndotl) * lightColor;	
	
	// Specular
	vec3 viewDir = normalize(viewPos - v_worldPos);
	vec3 reflectDir = reflect(-L, N);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular =  spec *  lightColor;

	// final fragment output
	vec3 lighting = (diffuse + specular) * attenuation * lightIntensity;
	FragColor = vec4(vec3(lighting), 1.0);
}