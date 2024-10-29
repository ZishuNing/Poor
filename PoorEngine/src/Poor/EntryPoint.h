#pragma once

#ifdef PR_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	Poor::Log::Init();
	auto app = Poor::CreateApplication();
	app->Run();
	delete app;
}

#endif // PR_PlATFORM_WINDOWS
