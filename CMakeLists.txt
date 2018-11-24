cmake_minimum_required(VERSION 2.6)
project(TORYENGINE)

include_directories(
src
contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-x86/SDL2_image/include
    contrib/msvc-windows-x86/openal-soft/include
    contrib/msvc-windows-x86/ogg/include
    contrib/msvc-windows-x86/vorbis/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2_image/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/vorbis/lib

  )
else()
  include_directories(
    /usr/X11R6/include
    /usr/local/include
  )

  link_directories(
    /usr/X11R6/lib
    /usr/local/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(ToryEngine
contrib/stb_image/stb_image.h
contrib/stb_image/stb_image.cpp
contrib/collision/tribox.c
src/ToryEngine/toryengine.h
src/ToryEngine/NonCopyable.h
src/ToryEngine/Root.h
src/ToryEngine/Root.cpp
src/ToryEngine/Object.h
src/ToryEngine/Object.cpp
src/ToryEngine/Component.h
src/ToryEngine/Component.cpp
src/ToryEngine/Environment.h
src/ToryEngine/VertexArray.h
src/ToryEngine/VertexArray.cpp
src/ToryEngine/VertexBuffer.h
src/ToryEngine/VertexBuffer.cpp
src/ToryEngine/ShaderProgram.h
src/ToryEngine/ShaderProgram.cpp
src/ToryEngine/MeshRenderer.h
src/ToryEngine/MeshRenderer.cpp
src/ToryEngine/Transform.h
src/ToryEngine/Transform.cpp
src/ToryEngine/Resource.h
src/ToryEngine/Resources.h
src/ToryEngine/Mesh.h
src/ToryEngine/Mesh.cpp
src/ToryEngine/Texture.h
src/ToryEngine/Texture.cpp
src/ToryEngine/Sound.h
src/ToryEngine/Sound.cpp
src/ToryEngine/Exception.h
src/ToryEngine/Exception.cpp
src/ToryEngine/Collider.h
src/ToryEngine/Collider.cpp
src/ToryEngine/BoxCollider.h
src/ToryEngine/BoxCollider.cpp
src/ToryEngine/MeshCollider.h
src/ToryEngine/MeshCollider.cpp
src/ToryEngine/Camera.h
src/ToryEngine/RenderTexture.h
src/ToryEngine/RenderTexture.cpp
src/ToryEngine/Keyboard.h
src/ToryEngine/Keyboard.cpp
src/ToryEngine/RenderTextureComponent.h
src/ToryEngine/RenderTextureComponent.cpp
)

if(MSVC)
  target_link_libraries(ToryEngine
    SDL2 SDL2_image glew32 opengl32 OpenAL32 ogg vorbis vorbisfile
  )
else()
  target_link_libraries(ToryEngine
    SDL2 SDL2_image GLU GLEW GL AL ogg vorbis vorbisfile
  )
endif()

add_executable(game
src/game/main.cpp
src/game/Player.h
src/game/Player.cpp
)

target_link_libraries(game ToryEngine)

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2_image/bin/SDL2_image.dll"
      "$<TARGET_FILE_DIR:game>"
  )
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:game>"
)
endif()