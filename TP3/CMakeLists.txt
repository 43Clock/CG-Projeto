cmake_minimum_required(VERSION 3.5)

# Project Name
#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(engine)
add_executable(${PROJECT_NAME} Structs/Ponto.cpp Structs/Ponto.h Structs/Forma.cpp Structs/Forma.h Engine/main.cpp Engine/tinyxml2.cpp Engine/tinyxml2.h Structs/Grupo.cpp Structs/Grupo.h Structs/Transformacao.cpp Structs/Transformacao.h)
project(generator)
add_executable(${PROJECT_NAME} Generator/generator.cpp Structs/Ponto.cpp Structs/Ponto.h Structs/Forma.cpp Structs/Forma.h Generator/plane.cpp Generator/plane.h Generator/box.cpp Generator/box.h Generator/cone.cpp Generator/cone.h Generator/sphere.cpp Generator/sphere.h Generator/torus.cpp Generator/torus.h Generator/bezier.cpp Generator/bezier.h)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

if  (WIN32)

	message(STATUS "Toolkits_DIR set to: " ${TOOLKITS_FOLDER})
	set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

	if (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
		message(ERROR ": GLUT not found")
	endif (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
	include_directories(${TOOLKITS_FOLDER}/glut )
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} 
										  ${TOOLKITS_FOLDER}/glut/glut32.lib)
	target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_DIR}/glut32.lib )

	if (EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" )
		file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
	endif(EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" )	

	set_property(DIRECTORY .. PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

	
else (WIN32) #Linux and Mac

	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} Wno-deprecated")
	find_package(GLUT REQUIRED)
	include_directories(${GLUT_INCLUDE_DIR})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})
	
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
	target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

	if(NOT GLUT_FOUND)
	   message(ERROR ": GLUT not found!")
	endif(NOT GLUT_FOUND)
	
endif(WIN32)








