add_subdirectory(image_pair_open_widget)
add_subdirectory(image_viewer)
add_subdirectory(depth_map_processor)
add_subdirectory(depth_map_widget)

set(TIGER_SOURCES
  ${TIGER_SOURCES}
  mainwindow/mainwindow.cpp
  mainwindow/mainwindow.hpp
  PARENT_SCOPE
  )
