#pragma once

#ifdef PR_PlATFORM_WINDOWS

extern Poor::Application* Poor::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Poor::CreateApplication();
	app->Run();
	delete app;
}

#endif // PR_PlATFORM_WINDOWS
