include_directories(src)
include_directories(src/incl)
include_directories(src/capdrop)

add_library(rpstr ${LIBTYPE}
${SNP_SRC}
src/capdrop/cap_drop.c 
src/incl/cor_incl.c 
src/cor_spel.c 
src/rpstr.c 
src/vertstr.cpp)
set_property(TARGET rpstr PROPERTY COMPILE_DEFINITIONS __RPSTR__)

target_link_libraries(rpstr
ccom
cstr
rling
rstr
std32
)

library_hook(rpstr)
