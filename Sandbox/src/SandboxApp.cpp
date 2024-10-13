#include "Poor.h"

class Sandbox : public Poor::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Poor::Application* Poor::CreateApplication()
{
	return new Sandbox();
}