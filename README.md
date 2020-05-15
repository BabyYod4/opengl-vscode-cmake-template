# Barebone OpenGL VScode workspace using CMAKE in windows 10 (and linux)

**THIS ONLY SUPPORTS 32bit applications**

Like the name suggests this VsCode workspace can be used to run `OpenGL` with `GLEW`, `GLFW`, `GLM`, `ImGui`, `stb_image`. 
- Debug mode is accessed by pressing `f5` 
- Normal mode by pressing `f6`
- Cleaning the project is done by pressing `f4`

Be sure to add this keyboard shortcuts to your `keybinding.json` by following this [guide](https://dzone.com/articles/setting-custom-shortcuts-in-visual-studio-code).
``` json
[
    {"key": "f6",
        "command": "workbench.action.tasks.runTask",
        "args": "normalRun"
    },
    {"key": "f4",
        "command": "workbench.action.tasks.runTask",
        "args": "clean"
    },
]
```

Hope you'll enjoy!

## Windows requirements
- You need to create a `bin` and `build` folder in the workspace folder (same folder where the README.md is). 
- You also need to install `cmake` on your windows pc and add it to your `PATH`
- You need to install [MinGW](https://osdn.net/projects/mingw/releases/) with the g++, gcc packages and add it to your `PATH`. follow this [guide](https://www.youtube.com/watch?v=sXW2VLrQ3Bs) 
- You need to rename the `mingw32-make.exe` in `C:\MinGW\bin` to `make.exe`

## Linux requirements
- You need to change `cmake -DCMAKE_BUILD_TYPE=Debug .. -G \"MinGW Makefiles\"` to `cmake -DCMAKE_BUILD_TYPE=Debug .. -G \"Unix Makefiles\"` in the file `.vscode/task.json`
- You need to install `OpenGL3+` (the installation method can differ per distro so look online for a good guide)
- You need to create a `bin` and `build` folder in the workspace folder (same folder where the README.md is). 
- You **DONT** need to instal `cmake`, `gcc`, `g++`, `make` as this *should* already be installed on your linux distro by default. 

# Trouble shooting guide

1: `"CMake Error: Could not create named generator MinGW"`
 - try changing the line `cmake -DCMAKE_BUILD_TYPE=Debug .. -G \"MinGW Makefiles\"` to `cmake -DCMAKE_BUILD_TYPE=Debug .. -G 'MinGW Makefiles'` in `.vscode/task.json`

 2: `cmake not recognized as an internal command`
 - Make sure that you have put the line `C:\Program Files\CMake\bin` in your `PATH` variable

 3: 
 ```bash
 CMake Error: Error: generator : xxx
 Does not match the generator used previously: MinGW Makefiles
 ```
 - Delete all the content in the `build` and `bin` folder and see if you are using the correct cmake prefic in `.vscode/task.json`
     - Linux: `cmake -DCMAKE_BUILD_TYPE=Debug .. -G 'Unix Makefiles'`
     - Windows: `cmake -DCMAKE_BUILD_TYPE=Debug .. -G 'MinGW Makefiles'`

# Change log

**15-05-2020:**
- Removed bash as default terminal because it was showing incorrect text output using cmd as standard now
- Fixed some cmd text output errors
- Cleaned up WindowContext code in single class
- Added support to clean build files with shortcut. 
- Added old `\" \"` quotation back because cmd likes it more

# To do
- Add support for 64 bit system with simple CMAKE setting
- Create basic batch rendering system and "scene selector" for people to easily debug multiple examples. 
