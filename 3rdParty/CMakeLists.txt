include_directories(../src/diablo/)

add_library(Storm SHARED 
	Storm/Source/storm.h
	Storm/Source/storm.cpp
)
if(MSVC)
	SET_TARGET_PROPERTIES(Storm PROPERTIES LINK_FLAGS "/DEF:\"${CMAKE_SOURCE_DIR}/3rdParty/Storm/Source/storm.def\" ")
endif()

add_library(DiabloUI SHARED 
	DiabloUI/diabloui.cpp
	DiabloUI/diabloui.h
)
target_link_libraries(DiabloUI Storm)
if(MSVC)
	SET_TARGET_PROPERTIES(DiabloUI PROPERTIES LINK_FLAGS "/DEF:\"${CMAKE_SOURCE_DIR}/3rdParty/DiabloUI/diabloui.def\" ")
endif()


add_library(PKWare STATIC 
	PKWare/explode.cpp
	PKWare/implode.cpp
	PKWare/pkware.h
)

# set(3rdPartyLibs Storm DiabloUI PKWare)
