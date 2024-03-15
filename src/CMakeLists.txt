# Create a shared library from source files
add_library(NosoCpp SHARED
noso_crypto.cpp
signer.cpp
#NosoCore.cpp
#NosoUtils.cpp
#VerifySing.cpp
)

# Include directories
target_include_directories(NosoCpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link against Botan
target_link_libraries(NosoCpp PRIVATE Botan::Botan)
