# We create a release target starting with our current directory
cmake -S ./executable_sources -B build/build_executable
cmake --build build/build_executable --config Release