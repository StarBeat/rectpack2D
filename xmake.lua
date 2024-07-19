    

set_languages("c++latest")

add_includedirs("src")
add_requires("python 3.x")

-- swig -python -c++ .\rectpack2d.i

target("_rectpack2d")
    set_kind("shared")
    add_files("swig/*.cxx")
    add_packages("python")
    set_extension(".pyd")
target_end()

target("test")
    set_kind("binary")
    add_files("example/main.cpp")
target_end()
