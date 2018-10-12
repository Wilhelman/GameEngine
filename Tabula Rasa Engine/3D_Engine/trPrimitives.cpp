#include "trDefs.h"
#include "trPrimitives.h"
#include "Glew\include\GL\glew.h"

// ------------------------------------------------------------
trPrimitive::trPrimitive() : transform(math::float4x4::identity), color(White), axis(false), type(PrimitiveTypes::Primitive_Point)
{}

// ------------------------------------------------------------
PrimitiveTypes trPrimitive::GetType() const
{
	return type;
}

// ------------------------------------------------------------
void trPrimitive::Render() const
{
	//glPushMatrix();
	//glMultMatrixf((GLfloat*)transform.ptr());


	if (axis == true)
	{
		// Draw Axis Grid
		glLineWidth(2.0f);

		glBegin(GL_LINES); // todo: this should be in a buffer!

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

		glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.1f, 0.0f); glVertex3f(1.1f, -0.1f, 0.0f);
		glVertex3f(1.1f, 0.1f, 0.0f); glVertex3f(1.0f, -0.1f, 0.0f);

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);

		glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.05f, 1.25f, 0.0f); glVertex3f(0.0f, 1.15f, 0.0f);
		glVertex3f(0.05f, 1.25f, 0.0f); glVertex3f(0.0f, 1.15f, 0.0f);
		glVertex3f(0.0f, 1.15f, 0.0f); glVertex3f(0.0f, 1.05f, 0.0f);

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

		glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.05f, 0.1f, 1.05f); glVertex3f(0.05f, 0.1f, 1.05f);
		glVertex3f(0.05f, 0.1f, 1.05f); glVertex3f(-0.05f, -0.1f, 1.05f);
		glVertex3f(-0.05f, -0.1f, 1.05f); glVertex3f(0.05f, -0.1f, 1.05f);

		glEnd();

		glLineWidth(1.0f);
	}

	glColor3f(color.r, color.g, color.b);

	InnerRender();
}


// ------------------------------------------------------------
void trPrimitive::SetPos(float x, float y, float z)
{
	transform = float4x4::Translate(x, y, z).ToFloat4x4() * transform;
}

// ------------------------------------------------------------
void trPrimitive::SetRotation(float angle, const math::vec &u)
{
	transform = float4x4::RotateAxisAngle(u, angle) * transform;
}

// ------------------------------------------------------------
void trPrimitive::Scale(float x, float y, float z)
{
	transform = float4x4::Scale(x, y, z).ToFloat4x4() * transform;
}
