add_subdirectory(output_view)
add_subdirectory(output_scene)

set(TIGER_SOURCES
  ${TIGER_SOURCES}
  mainwindow/image_viewer/image_viewer.cpp
  mainwindow/image_viewer/image_viewer.hpp
  PARENT_SCOPE
)
