#version 330 core
layout(location=0) in vec2 position;
layout(location=1) in vec3 color;

uniform mat4 PVM;

out vec3 fragColor;

void main(){
    gl_Position = PVM*vec4(position, 0.0, 1.0);
    fragColor = color;
}
