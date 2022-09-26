IMGUICOMMON_PATH:=$(dir $(lastword $(MAKEFILE_LIST)))

#technically these, as well as the imgui headers, should be put in some /usr/wherever/ folder
#Nah I guess I'm putting it in the system lib folder
#DYNAMIC_LIBS_linux+=$(IMGUICOMMON_PATH)lib/libcimgui$(LIB_SUFFIX)

# and technically all that should be in here is my ImGuiCommon wrapper class header
INCLUDE+=$(IMGUICOMMON_PATH)include

#... this should point to wherever the imgui.h file and associates are stored...
#...which I'm putting in this project itself, because I'm being sloppy.
#INCLUDE+=$(IMGUICOMMON_PATH)include/ImGuiCommon

# I've lumped the ImGui source into this project rather than keeping it a separate shared object (as per the nature of ImGui I suppose) 
# just for this library's source files, go ahead and put the include directory in the include list, so #include's don't have to be prefixed
#INCLUDE+=$(HOME)/include/SDL2
#INCLUDE_linux+=/usr/include/SDL2

MACROS+=IMGUI_DISABLE_OBSOLETE_FUNCTIONS
# With this, it's finding duplicate defs of ImS64 from ImGuiCommon.h => imgui_impl_sdl.h => imgui.h ...
# Without this, it gets errors in cimgui.h ...
#MACROS+=CIMGUI_DEFINE_ENUMS_AND_STRUCTS

# This has a space in the lmake version, but escaping it in make might mean tweaking Base.mk
MACROS_linux+="IMGUI_IMPL_API=extern\"C\""
MACROS_msvc+="IMGUI_IMPL_API=extern\"C\" __declspec(dllexport)"

LIBS+=cimgui_sdl
LIBS_msvc+=user32 imm32	# these are .lib'd for msvc right?

# I dont get why these aren't being processed automatically, like the other libs are
# Then again, looks like not all other libs are being automatically processed 
# ... but at least my own built libs are
post_builddist_osx_app::
	install_name_tool -change libimgui$(LIB_SUFFIX) @executable_path/../Resources/lib/libimgui$(LIB_SUFFIX) $(DIST)
