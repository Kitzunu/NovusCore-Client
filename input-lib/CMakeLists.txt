project(input VERSION 1.0.0 DESCRIPTION "Input Library")

file(GLOB_RECURSE INPUT_LIB_FILES "*.cpp" "*.h")

add_library(input ${INPUT_LIB_FILES})
add_library(input::input ALIAS input)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${ROOT_FOLDER}/libs)

find_assign_files(${INPUT_LIB_FILES})

target_include_directories(input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(input PUBLIC
	common::common
	glfw ${GLFW_LIBRARIES}
)

add_compile_definitions(NOMINMAX _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)