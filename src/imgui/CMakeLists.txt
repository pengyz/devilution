add_executable(imgui-demo
	main.cpp
	imgui.cpp
	imgui_demo.cpp
	imgui_draw.cpp
	imgui_impl_glfw.cpp
	imgui_impl_opengl3.cpp
	)

target_link_libraries(imgui-demo ${HUNTER_LIBS})
