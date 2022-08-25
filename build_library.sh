# We create a release target starting with our current directory
cmake -S ./lib_sources -B build/build_lib
cmake --build build/build_lib --config Release

