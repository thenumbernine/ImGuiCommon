IMGUICOMMON_PATH:=$(dir $(lastword $(MAKEFILE_LIST)))

#technically these, as well as the imgui headers, should be put in some /usr/wherever/ folder
DYNAMIC_LIBS+=$(IMGUICOMMON_PATH)lib/libimgui.dylib
DYNAMIC_LIBS+=$(IMGUICOMMON_PATH)lib/libimgui_impl_sdl.dylib

# and technically all that should be in here is my ImGUICommon wrapper class header
INCLUDE+=$(IMGUICOMMON_PATH)include

#... this should point to wherever the imgui.h file and associates are stored...
#...which I'm putting in this project itself, because I'm being sloppy.
INCLUDE+=$(IMGUICOMMON_PATH)include/ImGUICommon

# I've lumped the ImGUI source into this project rather than keeping it a separate shared object (as per the nature of ImGUI I suppose) 
# just for this library's source files, go ahead and put the include directory in the include list, so #include's don't have to be prefixed
INCLUDE+=$(HOME)/include/SDL2

#i dont get why these aren't being processed automatically, like the other libs are
#then again, looks like not all other libs are being automatically processed 
# ... but at least my own built libs are
post_builddist_osx_app::
	install_name_tool dist/osx/debug/test.app/Contents/MacOS/test -change libimgui.dylib @executable_path/../Resources/lib/libimgui.dylib
	install_name_tool dist/osx/debug/test.app/Contents/MacOS/test -change libimgui_impl_sdl.dylib @executable_path/../Resources/lib/libimgui_impl_sdl.dylib

