# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	Basic.hpp
  Token.hpp
  TT.hpp
  Error.hpp
  Lexer.hpp
)

set(SOURCE_FILES
  Basic.cpp
  Token.cpp
  Error.cpp
  Lexer.cpp
)
add_library(basic_lib ${SOURCE_FILES} ${HEADER_FILES})