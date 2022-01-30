# ZIA DOCUMENTATION
\
by Samuel Parayre.
You can generate this documentation in PDF format using ```Markdown PDF``` visual extension. (CTRL + SHIFT + P , "export" and choose "PDF")
<p>&nbsp;</p>

## Summary
1. [Remotes](#REMOTES)
2. [Create Conan build folder](#create-conan-build-folder)
3. [Cmake](#cmake)
4. [.gitignore](#.gitignore)
5. [Use the project](#use-the-project)

<p>&nbsp;</p>

## REMOTES

to add remotes to conan you need to do :
conan remote add <NAME> <URL>

and the only remote to add is :
https://api.bintray.com/conan/conan-community/conan
https://api.bintray.com/conan/conan-center
https://api.bintray.com/conan/bincrafters/public-conan

name it randomly ;)
<p>&nbsp;</p>

## CREATE CONAN BUILD FOLDER

In order to create conan build architecture, you may need this command:

>mkdir build && cd build && conan install .. --build missing && cmake .. -G “UnixMakefiles” && cmake –build

This command will download and install all the libs contain in "conanfile.txt".
Three files will be created "conanbuildinfo.cmake", "conaninfo.txt" and "conanbuildinfo.txt" and they are necessary to compile so copy them to the root of the repo.

In build folder, run:
>cp conanbuildinfo.cmake  conanbuildinfo.txt conaninfo.txt ..
<p>&nbsp;</p>

## CMAKE

Then you are ready to compile !

>cmake CMakeLists.txt

>make
<p>&nbsp;</p>

## .gitignore

Some files are undesirable on github ! Don't forget to add all of these files to your ```.gitignore``` file.

- a.out
- .vscode
- CMakeCache.txt
- cmake_install.cmake
- conanbuildinfo.cmake
- conanbuildinfo.txt
- conaninfo.txt
- CMakeFiles
- README.pdf
- build
- Makefile
- *.so
<p>&nbsp;</p>

## Use the project

The project works as follow:

Execute the binary, you can specify a path for a config file, otherwise one will be used by default. 

>./zia_server CONFIG_FILE_PATH

You can also modify the Config file as much as you want, if a paramter is wrong, a default one will be used.

<p>&nbsp;</p>
