#pragma once

//This is just a class wrapper of imgui_impl_sdl.cpp/.h

#include "imgui.h"
#include "imgui_internal.h"
#include "cimgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "GLCxx/gl.h"
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
		ImGui_ImplOpenGL3_Init(nullptr);
	}

	virtual ~ImGuiCommon() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		igDestroyContext(nullptr);
	}

	void onSDLEvent(SDL_Event& event) {
		ImGui_ImplSDL2_ProcessEvent(&event);
	}

	void onUpdate(std::function<void()> callback) {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		igNewFrame();
	
		callback();	
		glViewport(0, 0, (int)igGetIO()->DisplaySize.x, (int)igGetIO()->DisplaySize.y);
		
		igRender();
		ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
	}
};

}
