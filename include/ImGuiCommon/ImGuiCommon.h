#pragma once

//This is just a class wrapper of imgui_impl_sdl.cpp/.h

#include "imgui.h"	//IMGUI_API
#include "imgui_impl_sdl.h"
#include "GLApp/gl.h"
#include <functional>

namespace ImGuiCommon {

struct ImGuiCommon {
	SDL_Window* window;

	ImGuiCommon(SDL_Window* window_)
	: window(window_)
	{
		ImGui_ImplSdl_Init(window);
	}

	virtual ~ImGuiCommon() {
		ImGui_ImplSdl_Shutdown();
	}

	void sdlEvent(SDL_Event& event) {
		ImGui_ImplSdl_ProcessEvent(&event);
	}

	void update(std::function<void()> callback) {
		ImGui_ImplSdl_NewFrame(window);
		callback();	
		glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
		ImGui::Render();
	}
};

}
