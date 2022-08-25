STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} ) 
aux_source_directory(. SRC)
add_executable(${CURRENT_FOLDER} ${SRC})
