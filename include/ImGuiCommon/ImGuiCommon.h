#pragma once

//This is just a class wrapper of imgui_impl_sdl.cpp/.h

#include "cimgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl2.h"
#include "GLApp/gl.h"
#include <functional>
#include <SDL.h>

namespace ImGuiCommon {

struct ImGuiCommon {
	SDL_Window* window = {};

	ImGuiCommon(SDL_Window* window_, SDL_GLContext context)
	: window(window_)
	{
		igCreateContext(nullptr);
		igStyleColorsDark(nullptr);
		ImGui_ImplSDL2_InitForOpenGL(window, context);
		ImGui_ImplOpenGL2_Init();
	}

	virtual ~ImGuiCommon() {
		ImGui_ImplOpenGL2_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		igDestroyContext(nullptr);
	}

	void onSDLEvent(SDL_Event& event) {
		ImGui_ImplSDL2_ProcessEvent(&event);
	}

	void onUpdate(std::function<void()> callback) {
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplSDL2_NewFrame(window);
		igNewFrame();
	
		callback();	
		glViewport(0, 0, (int)igGetIO()->DisplaySize.x, (int)igGetIO()->DisplaySize.y);
		
		igRender();
		ImGui_ImplOpenGL2_RenderDrawData(igGetDrawData());
	}
};

}
