#pragma once

//This is just a class wrapper of imgui_impl_sdl.cpp/.h

#include "imgui.h"	//IMGUI_API
#include "ImGUICommon/imgui_impl_sdl.h"
#include <OpenGL/gl.h>	//glViewport
#include <functional>

namespace ImGUICommon {

struct ImGUICommon {
	SDL_Window* window;

	ImGUICommon(SDL_Window* window_)
	: window(window_)
	{
		ImGui_ImplSdl_Init(window);
	}

	virtual ~ImGUICommon() {
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
