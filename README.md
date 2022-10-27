### ImGui wrapper for ImGui, SDL, and OpenGL2

[![Donate via Stripe](https://img.shields.io/badge/Donate-Stripe-green.svg)](https://buy.stripe.com/00gbJZ0OdcNs9zi288)<br>
[![Donate via Bitcoin](https://img.shields.io/badge/Donate-Bitcoin-green.svg)](bitcoin:37fsp7qQKU8XoHZGRQvVzQVP8FrEJ73cSJ)<br>

Uses cimgui / imgui v1.87dock

To get this working:

1) `cmake cimgui`
2) It doesn't hurt to rename the base name in windows to `cimgui_sdl` or in unix `libcimgui_sdl-$version.so`.
3) Change solution to include `backends/imgui_impl_sdl.cpp` and `backends/imgui_impl_opengl2.cpp` in the list of source files.
4) Don't forget to add `OpenGL32.lib; SDL2.lib; SDL2main.lib` to your project ... and add the appropriate GL and SDL include paths.
5) Build the `.so/.dylib/.dll`.  
6) Put the `cimgui_sdl.so/.dylib/.dll` in this project's folder `lib/` folder .
7) put all the `.h` files of `cimgui`, `imgui`, of `backends/imgui_impl_sdl.h`, and of `backends/imgui_impl_opengl2.h` into this project's `include/` folder.
