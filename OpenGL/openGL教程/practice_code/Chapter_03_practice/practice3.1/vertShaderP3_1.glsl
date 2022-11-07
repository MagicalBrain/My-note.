#version 430

uniform float offset;

mat4 buildRotateX(float rad) {
    mat4 xrot = mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, cos(rad), -sin(rad), 0.0,
        0.0, sin(rad), cos(rad), 0.0,
        0.0, 0.0, 0.0, 1.0
    );
    return xrot;
}

// 构建并返回绕Y轴的旋转矩阵
mat4 buildRotateY(float rad) {
    mat4 yrot = mat4(
        cos(rad), 0.0, sin(rad), 0.0,
        0.0, 1.0, 0.0, 0.0,
        -sin(rad), 0.0, cos(rad), 0.0,
        0.0, 0.0, 0.0, 1.0);
    return yrot;
}

// 构建并返回绕Z轴的旋转矩阵
mat4 buildRotateZ(float rad) {
    mat4 zrot = mat4(
        cos(rad), -sin(rad), 0.0, 0.0,
        sin(rad), cos(rad), 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0);
    return zrot;

}

void mainX(void)
//void main(void)
{
	if (gl_VertexID == 0) 
		gl_Position = vec4(0.25, -0.25, 0.0, 1.0) * buildRotateX(offset);
	else if (gl_VertexID == 1) 
		gl_Position = vec4(-0.25, -0.25, 0.0, 1.0) * buildRotateX(offset);
	else 
		gl_Position = vec4(0.25, 0.25, 0.0, 1.0) * buildRotateX(offset);
}

void mainY(void)
//void main(void)
{
    if (gl_VertexID == 0)
        gl_Position = vec4(0.25, -0.25, 0.0, 1.0) * buildRotateY(offset);
    else if (gl_VertexID == 1)
        gl_Position = vec4(-0.25, -0.25, 0.0, 1.0) * buildRotateY(offset);
    else
        gl_Position = vec4(0.25, 0.25, 0.0, 1.0) * buildRotateY(offset);
}


void main(void)
{
    if (gl_VertexID == 0)
        gl_Position = vec4(0.25, -0.25, 0.0, 1.0) * buildRotateZ(offset);
    else if (gl_VertexID == 1)
        gl_Position = vec4(-0.25, -0.25, 0.0, 1.0) * buildRotateZ(offset);
    else
        gl_Position = vec4(0.25, 0.25, 0.0, 1.0) * buildRotateZ(offset);
}