ImGui wrapper for ImGui, SDL, and OpenGL2 
Uses cimgui / imgui v1.87dock

To get this working:

1) `cmake cimgui`.  Make sure MSVC uses 64-bit via `cmake -DCMAKE_GENERATOR_PLATFORM=x64 <dir>` (unless they finally made this default behavior in Windows cmake).
2) Change solution to include `backends/imgui_impl_sdl.cpp` and `backends/imgui_impl_opengl2.cpp` in the list of source files.
	Don't forget to add `OpenGL.lib`, `SDL.lib`, and `SDLmain.lib` to your project ... and add the appropriate GL and SDL include paths.
3) Build `cimgui.so/.dylib/.dll`.  It doesn't hurt to rename it to `libcimgui_sdl-$version.so`.
4) Put the `cimgui.so/.dylib/.dll` in this project's folder `lib/` folder .
5) put all the `.h` files of `cimgui`, `imgui`, of `backends/imgui_impl_sdl.h`, and of `backends/imgui_impl_opengl2.h` into this project's `include/` folder.
