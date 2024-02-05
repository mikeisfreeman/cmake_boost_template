##Cmake/Boost C++ CLI Project Template
#####A quick-start template for CLI application programming using C++/CMake/Boost.

By no means complete, and probably not perfect, but a good starting template for writing CLI programs with the initial annoyances already mostly taken care of, for those of us who aren't well versed.

I don't work with windows at all, so this is only tested on Linux, but I think it should be cross platform compatible since it's using Boost::program_options rather than GNU getopt() which I read doesn't work on windows without extra effort.

Feel free to suggest changes, I'm putting this here mainly for myself, but maybe others can benefit, and I'm always open to constructive criticism when accompanied by explanation, so maybe I'll learn something.

I use this in VS Code with the C/C++ Extension pack (***ms-vscode.cpptools-extension-pack***) which includes the cmake extension.  I don't particularly like the 'quick start' that it does, as I prefer this simpler approach.

####Usage
- Before making any changes to the files, look through them and figure out how it all works, then build it as is if you're not very familiar with cmake so you can get your environment set up properly based on any errors reported by cmake.

***<small><u>VS CODE:</u></small>***
- Open the directory in VS Code.
- <kbd>CTRL</kbd>+<kbd>SHIFT</kbd>+<kbd>P</kbd> - then type **Cmake:configure** and select your compiler.  This will create the build directory and if your environment is properly set up, should be all you need to do.
- ```cd build && make``` - build the project  ***or*** click the 'Build' button on the Cmake extension bar at the bottom of the screen.

***<small><u>Any text editor + terminal:</u></small>***
- ```cd {project_directory}``` <small>- wherever you cloned or saved the files to</small>
- ```mkdir build && cd build```
- ```cmake ..```
- ```make```  <small>- build the project</small>


***-<small>Test Run:</small>***
 ```./CmakeBoostTemplate```

Once it all works, modify to your hearts content.
- Search and Replace all instances of 'CmakeBoostTemplate' with a project name of your choice.  (This 'project name' will also be the name of the executable)
- after making any changes to the CMakeLists.txt files cmake must reconfigure.  VS Code does this automatically when you save the file if you have the extension installed, but sometimes it still has problems.
    - So in order to avoid any pitfalls, I usually just remove the build dir and recreate it fresh, as it's very quick.
        - ```rm -r ./build```
        - ```mkdir build && cd build```
        - ```cmake .. && make```

- in ```src/main.cpp``` add new options and in the main function add some logic to do something cool. 

### Enjoy!