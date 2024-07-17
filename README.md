### ImGui wrapper for ImGui, SDL2, and OpenGL3

[![Donate via Stripe](https://img.shields.io/badge/Donate-Stripe-green.svg)](https://buy.stripe.com/00gbJZ0OdcNs9zi288)<br>

Uses cimgui v1.89.7dock / imgui v1.89.7-docking

- Apply the patch to the cimgui makefile and then make.
- Copy `.so/.dll/.dylib` into wherever you keep your libraries.
- Copy `cimgui/cimgui.h, cimgui/imgui/*.h, cimgui/imgui/backends/imgui_impl_sdl2.h, cimgui/imgui/backends/imgui_impl_opengl3.h` into an include folder of your liking.
- Make sure those paths are added to the buildinfo environment
