# Let's start

some important message

Yeah! we have added github actions and workflow

# How to build the code

1. create a directory build(mkdir build)
2. Change directory to build(cd build)

## Release

3. call cmake (cmake ..)

## Debug

4. call cmake with debug build type(cmake -DCMAKE_BUILD_TYPE=Debug ..)
5. build the code(cmake --build .) or (make <target name>)

## for debugging

6. We recommend to use lldb (due to the nice user interface)
    1. run lldb together with executable file (lldb ./main_component/main_component)
    2. inside lldb we can call a command "gui" to have user interface.
    3. run a program with arguemnets (run <arg1> <arg2>)
    run ../main_component/input/main_comp.txt output_maincomp.txt
