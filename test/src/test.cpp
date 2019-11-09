#include "ImGuiCommon/ImGuiCommon.h"
#include "GLApp/GLApp.h"
#include <memory>

struct Test : public GLApp::GLApp {
	using Super = ::GLApp::GLApp;
	std::shared_ptr<ImGuiCommon::ImGuiCommon> gui;

	bool show_demo_window = true;
	bool show_another_window = false;
	ImColor clear_color = {{114, 144, 154}};

	virtual int getSDLInitFlags() {
		return SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER;
	}

	//post-sdl and gl init:
	virtual void init() {
		Super::init();
		gui = std::make_shared<ImGuiCommon::ImGuiCommon>(window, context);
	}

	virtual void shutdown() {
		gui = nullptr;	//dealloc and shutdown before sdl shuts down
		Super::shutdown();
	}

	virtual void update() {
		Super::update();

		gui->update([&](){


			// 1. Show a simple window
			// Tip: if we don't call igBegin()/igEnd() the widgets appears in a window automatically called "Debug"
			{
				static float f = 0.0f;
				igText("Hello, world!");
				igSliderFloat("float", &f, 0.0f, 1.0f, "%.3f", 1.0f);
				igColorEdit3("clear color", (float*)&clear_color, 0);
				if (igButton("Test Window", ImVec2{0,0})) show_demo_window ^= 1;
				if (igButton("Another Window", ImVec2{0,0})) show_another_window ^= 1;
				igText("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / igGetIO()->Framerate, igGetIO()->Framerate);
			}

			// 2. Show another simple window, this time using an explicit Begin/End pair
			if (show_another_window)
			{
				igSetNextWindowSize(ImVec2{200,100}, ImGuiCond_FirstUseEver);
				igBegin("Another Window", &show_another_window, 0);
				igText("Hello");
				igEnd();
			}

			// 3. Show the ImGui test window. Most of the sample code is in igShowTestWindow()
			if (show_demo_window)
			{
				igSetNextWindowPos(ImVec2{650, 20}, ImGuiCond_FirstUseEver, ImVec2{0,0});
				igShowDemoWindow(&show_demo_window);
			}
	
		});
	}

	virtual void sdlEvent(SDL_Event& event) {
		Super::sdlEvent(event);
		gui->sdlEvent(event);
	}
};

GLAPP_MAIN(Test)
