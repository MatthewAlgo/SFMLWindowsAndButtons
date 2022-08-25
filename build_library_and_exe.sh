# We create a release target starting with our current directory
cmake -S . -B build/build_combo
cmake --build build/build_combo --config Release


# Copy everything from res
cp -r ./res ./build/build_combo/executable_sources