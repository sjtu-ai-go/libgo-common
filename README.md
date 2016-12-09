# libgo-common

## Usage
```
git submodule add {{repo_url}} vendor/libgo-common
git submodule update --recursive --init
```
Then, in `CMakeLists.txt`:
```
add_subdirectory(vendor/libgo-common)
include_directories(${libgo-common_INCLUDE_DIR})

# After add_executable(your_prog)
target_link_libraries(your_prog go-common)
```

Enable test with `libgo-common_enable_tests`, default `OFF`.

Fetch with:
```
git clone {{repo_url}} --recursive
```

Update by:
```
git submodule update --init
```
