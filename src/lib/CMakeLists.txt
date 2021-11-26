# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	basic.hpp
)

set(SOURCE_FILES
  basic.cpp
)
add_library(basic_lib ${SOURCE_FILES} ${HEADER_FILES})