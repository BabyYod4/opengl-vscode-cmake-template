# Barebone OpenGL VScode workspace using CMAKE in windows 10 (and linux)

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
- You also need to install `cmake` on your windows pc to use the bash terminal and add it to your `PATH`
- You need to install MinGW with the g++, gcc packages and add it to your `PATH`. follow this [guide](https://www.youtube.com/watch?v=sXW2VLrQ3Bs) 
- You need to rename the `mingw32-make.exe` in `C:\MinGW\bin` to `make.exe`

## Linux requirements
- You need to change `cmake -DCMAKE_BUILD_TYPE=Debug .. -G \"MinGW Makefiles\"` to `cmake -DCMAKE_BUILD_TYPE=Debug .. -G \"Unix Makefiles\"` in the file `.vscode/task.json`
- You need to install `OpenGL3+` (the installation method can differ per distro so look online for a good guide)
- You need to create a `bin` and `build` folder in the workspace folder (same folder where the README.md is). 
- You **DONT** need to instal `cmake`, `gcc`, `g++`, `make` as this *should* already be installed on your linux distro by default. 
