# Barebone OpenGL VScode workspace using CMAKE in windows 10 (and linux)

![TestImage](https://user-images.githubusercontent.com/59289792/81974765-4e9c2100-9626-11ea-8e14-0d26d3b3b2b7.png)

**THIS ONLY SUPPORTS 32bit applications**

Like the name suggests this VsCode workspace can be used to run `OpenGL` with `GLEW`, `GLFW`, `GLM`, `ImGui`, `stb_image` in both debug mode or normal mode. 
Debug mode is accessed by pressing `f5` and nomal mode by pressing `ctrl+d`. 

Be sure to add this keyboard shortcuts to your `keybinding.json` by following this [guide](https://dzone.com/articles/setting-custom-shortcuts-in-visual-studio-code).
```json
[
    // ... add other keybindings
    {
        "key": "ctrl+d",
        "command": "workbench.action.tasks.runTask",
        "args": "normalRun"
    }
]
```

Hope you'll enjoy!

## Windows requirements
- You need to create a `bin` and `build` folder in the workspace folder (same folder where the README.md is). 
- You also need to install `git` on your windows pc to use the bash terminal and add it to your `PATH`
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
 - try changing the line `cmake -DCMAKE_BUILD_TYPE=Debug .. -G 'MinGW Makefiles'` to `cmake -DCMAKE_BUILD_TYPE=Debug .. -G \"MinGW Makefiles\"` in `.vscode/task.json`

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
