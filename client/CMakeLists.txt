project(client-demo VERSION 1.0.0 DESCRIPTION "Wow demo client for NovusCore")

file(GLOB_RECURSE CLIENT_DEMO_FILES "*.cpp" "*.h")

add_executable(client-demo ${CLIENT_DEMO_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${ROOT_FOLDER})

find_assign_files(${CLIENT_DEMO_FILES})

include_directories(../../dep/glfw/include)

add_compile_definitions(NOMINMAX _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)

target_link_libraries(client-demo PRIVATE
	asio::asio
	common::common
	render::render
	network::network
	input::input
	glfw ${GLFW_LIBRARIES}
)

install(TARGETS client-demo DESTINATION ${CMAKE_CURRENT_BINARY_DIR})