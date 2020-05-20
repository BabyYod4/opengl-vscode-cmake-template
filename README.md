# Barebone OpenGL VScode workspace using CMAKE in Windows, Linux and WSL

Like the name suggests this VsCode workspace can be used to run `OpenGL` with `GLEW`, `GLFW`, `GLM`, `ImGui`, `stb`. 
- Debug mode is accessed by pressing `f5` 
- Normal mode by pressing `f6`
- Cleaning the project is done by pressing `f4`

Each operating system has a different setup before you can use the workspace so be sure to follow those guides. The generic setup needs to be applied the same for each os. 
To test out the workspace i have put some code of a graphic/game engine i am working on in the `engine` folder, but feel free to remove them and change the `engne/LucidyEngine` name, **NOT** the `engine` folder name as this is needed by `cmake`

If there are any problems, feel free to leave a comment as an issue and i will get back to you as soon as i can. 


## Folder Layout
The workspace has the following folder structure with their uses:
```
├───.vscode // main folder where vscode puts it settings
│   └───intelli_fix_cpp // folder containing STL headers because intellisense of vscode seems to sometimes struggle with absolute paths
│   └───c_cpp_properties.json // file where settings of the c++ intellisense are configured (dont modify)
│   └───launch.json // file where debugging settings are configured
│   └───settings.json // file where user defined settings on the workspace are configured (dont modify)
│   └───tasks.json // file where the settings of running and compile commands are configured 
├───build // folder with target subfolder where the build files made by cmake will be outputted (dont modify)
│   ├───linux
│   │   ├───x64
│   │   └───x86
│   └───windows
│       ├───x64
│       └───x86
├───engine // folder where your main engine code resides (dont modify)
│   └───LucidyEngine // include path of your engine when using in a sandbox application. Accesing like #include <LucidyEngine/..hpp>
├───include // folder with target subfolder where external include files used in cmake are (dont modify) 
│   ├───linux 
│   │   ├───x64
│   │   └───x86
│   └───windows
│       ├───x64
│       └───x86
├───lib // folder with target subfolder where external libraries used in cmake are (dont modify) 
│   ├───linux
│   │   ├───x64
│   │   └───x86
│   └───windows
│       ├───x64
│       └───x86
└───src // folder where your sandbox application is 
    └───CmakeList.txt // cmake settings file that apply settings on the include and libraries used, that i refer as <CMAKE_PROJ_SETTINGS>
    └───main.cpp
└───CmakeList.txt // generic cmake settings file that apply settings on what device target to use, that i refer as <CMAKE_TARGET_SETTINGS>
└───lucidy-engine.code-workspace // file where generic settings on the workspace are configured
```

## Generic setup

1. **Add keybinding to code workspace**

    - Be sure to add this keyboard shortcuts to your `keybinding.json` by following this [guide](https://dzone.com/articles/setting-custom-shortcuts-in-visual-studio-code).
    ``` JSON
    // Place your key bindings in this file to override the defaults
    [
        {"key": "f6",
            "command": "workbench.action.tasks.runTask",
            "args": "normalRun"
        },
        {"key": "f4",
            "command": "workbench.action.tasks.runTask",
            "args": "cleanTask"
        },
    ]
    ```

2. **Chose your target device in the CMake**
    - In the `<CMAKE_TARGET_SETTINGS>` change the following lines to reflect your target device (be aware that for now Linux has so x86 target, will add in the future):
    ```cmake
    set ( OS_TARGET_ "Windows" ) # Choose between "Linux" and "Windows"
    set ( AT_TARGET_ "x64" ) # Choose between "x64" and "x86"
    ```

2. **Chose your target device in the vscode settings**
    - In the file `.vscode/tasks.json` you will see 4 lines where 3 are commented out:
    ```javascript
        "cwd": "${workspaceRoot}/build/windows/x64"
        // "cwd": "${workspaceRoot}/build/windows/x86"
        // "cwd": "${workspaceRoot}/build/linux/x64"
        // "cwd": "${workspaceRoot}/build/linux/x86"
    ```
    - Comment out the os and target you are **not** using, (so for example when using Window x64, comment out the other 3 options besides: `"cwd": "${workspaceRoot}/build/windows/x64"` )

All done!, now proceed to the OS specific setups below. 

## OS specific setup

### Windows
- You also need to install `cmake` on your windows pc and add it to your `PATH`
- You need to either install [MinGW](https://osdn.net/projects/mingw/releases/) (for 32bit) or [MinGW64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download) (for 64 bit) and add it to your `PATH`. 
    - [MinGW guide](https://www.youtube.com/watch?v=sXW2VLrQ3Bs) 
    - Mingw64: simple installer does not need a guide, but be sure to have this settings:

        ![mingw64](https://user-images.githubusercontent.com/59289792/82444037-dbb9fc80-9aa2-11ea-914d-0865e64304bd.png)


All done!, you can test the application by pressing `f6`. 

## Linux requirements
- You need to install `OpenGL3+` (the installation method can differ per distro so look online for a good guide i cant give you one guide for them all)
- You need to instal `cmake`. 

All done!, you can test the application by pressing `f6`. 

## WSL (Windows subsystem for Linux)
This is quite a big quide so perform these steps in order, be sure you have configured your workspace as a 64bit Linux build (see `Generic setup`). Also keep in mind you are stuck with shitty meso drivers for now (Microsoft is making an update in WSL2), so be sure to run in OpenGL 3.3 Core or 3.2 Compat mode. 

1. Join windows insider program but chose the **Slow** option to not break your system: [guide](https://www.youtube.com/watch?v=7N8D8LR-qak)
2. Open powershell and run the following commands: 
    - `dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart`
    - `dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart`
3. Restart your computer:
4. Now press `WindowsKey + R` and type `optionalfeatures.exe`, this will bring a menu up with some tick boxes. Be sure that the following features are enabled: 
    - `Hyper-V`, `Virtual Machine Platform`, `Windows Subsystem for Linux`
5. Now go to the microsoft store and install a linux version (i prefer arch but its not officially supported so i will use Ubuntu in this guide).
    - [Ubuntu WSL](https://www.microsoft.com/store/productId/9NBLGGH4MSV6)
6. If installed correcly you will see an Ubuntu desktop icon or start menu (try search for Ubuntu in windows). Click it and an terminal will open asking you to create an username with details. Once enter the following commands: 
    - `sudo apt-get update && sudo apt-get upgrade -y && sudo apt-get upgrade -y && sudo apt-get dist-upgrade -y && sudo apt-get autoremove -y`
    - `sudo apt install -y ca-certificates findutils command-not-found vim nano curl openssh-client less screen apt-utils top htop whois git python3-pip`
    - `sudo apt install ubuntu-desktop yad x11-apps cmake mesa-utils extra-cmake-modules xorg-dev libxi-dev libxcursor-dev libxinerama-dev libxrandr-dev libx11-dev libxext-dev build-essential libgl-dev libxmu-dev libosmesa-dev`

7. Once everything is finnally installed, you want to install a window server **ON WINDOWS** to output graphical windows to your display. To do that download something called [VcXsrv](https://sourceforge.net/projects/vcxsrv/). Once download follow this setup:

    ![1](https://user-images.githubusercontent.com/59289792/82441874-e96d8300-9a9e-11ea-97d3-07083fbe95fa.png)

    ![2](https://user-images.githubusercontent.com/59289792/82441875-e96d8300-9a9e-11ea-8d7e-7703245a6396.png)

    ![3](https://user-images.githubusercontent.com/59289792/82441876-ea061980-9a9e-11ea-87eb-21a93b68b074.png)

    ![4](https://user-images.githubusercontent.com/59289792/82441872-e8d4ec80-9a9e-11ea-8b0b-fe45a8f1d904.png)

    - Before hitting finish, click on "Save Configuration" and save the file in the folder `%appdata%\Microsoft\Windows\Start Menu\Programs\Startup`. Also **DONT** enable `native opengl`. After that click finish.  

8. Okay good now you have the core things setup, its time to talk about the development side (a.k.a. using vscode as a remote editor). To do this, open vscode in a new window and download an extention called `Remote - WSL`. Once downloaded reload your window. You will now see a litle computer monitor icon with a bal logo on the right panel. Click on it and press a button called `Add Target` or `Add distro` (sometimes the logo of your linux distro will be there instead, just click it). 
9. Once done this should open a new window with a bash terminal as the default windows terminal. Be sure that your window has a little green indicater saying something like "WSL Ubuntu" on the bottom

    ![image](https://user-images.githubusercontent.com/59289792/82442690-6fd69480-9aa0-11ea-8aac-9e58557143ab.png)
    
    ![image](https://user-images.githubusercontent.com/59289792/82442711-782ecf80-9aa0-11ea-9701-f3e1cb56c673.png)

10. Okay great now you can run applications from the terminal in vscode on WSL, but we are not done yet. The last thing you need to do is configure WSL to be able to use OpenGL properly. You also want to set up a shared workspace so you more easiy acces windows drives from WSL. 
11. First create a folder somewhere you will code from (for example `C:/dev/workspace/linuxshare` ) in windows. 
12. Next create a folder in linux where you want the symbolic link tot he window drive to be stored (for example `~/whome`)
13. Now use this command to create a symbolic link: `ln -s /mnt/c/{windowsFolder} {linuxFolder}`
14. Great now that is done you can more easily acces windows files from linux. Now we can setup the window manager stuff
15. Run these commands in linux:

    - `echo "export DISPLAY=localhost:0.0" >> ~/.bashrc`
    - `source ~/.bashrc`

16. Open the file `/etc/environment` with `sudo nano /etc/environment` and put this inside of it:

    ```bash
    export LIBGL_ALWAYS_INDIRECT=Yes
    export DISPLAY=localhost:0.0
    ```

17. Open the file `/etc/wsl.conf` with `sudo nano /etc/wsl.conf` and put this inside of it:

    ```bash
    [automount]
    options = "metadata"
    enabled = true
    ```

18. Finally done, now close VScode, open powershell and run the following command: `wsl.exe -t Ubuntu // (or other e.g. Debian)`

19. Reboot your PC. After your back in windows, now you can copy the workspace folder (so the folder `opengl-vscode-cmake-template`) inside the shared folder you are using linux. In my example I have a folder named: `C:/dev/workspace/linuxshare/opengl-vscode-cmake-template`

20. Now open VSCode, connect to your linux device using WSL, check for the green text to say "WSL Ubuntu" (or similar) and select open folder. From there just select your workspace folder and your set. Everything works from now. 

21. Just to be sure, test out openGL by using this command `xeyes`. and try to run the application in your workspace by pressing `f6`



# VSCode extention recommendations

To help you speed up your coding and making the workspace a little easier on the eyes, consider installing these extentions (C# is not needed):

![vscode-reccomendations](https://user-images.githubusercontent.com/59289792/82444778-08badf00-9aa4-11ea-865b-0431642f825a.png)

- Another good extention is `vscode-shader` for `HSL` and `GLSL` shader highlighting and error checking. 


If you are using a WSL build, make sure you also instaled these extiontions on your target device. Go to the extention tab and select "Install in WSL"

![wsl_vscode](https://user-images.githubusercontent.com/59289792/82444942-461f6c80-9aa4-11ea-82eb-6db319e7ea66.png)




# Trouble shooting guide

For any other errors you get, please leave an issue in github will get with you within a week at most. 

# Change log

**15-05-2020:**

- Removed bash as default terminal because it was showing incorrect text output using cmd as standard now
- Fixed some cmd text output errors
- Cleaned up WindowContext code in single class
- Added support to clean build files with shortcut. 
- Added old `\" \"` quotation back because cmd likes it more
- *To Do*
    - Add support for 64 bit system with simple CMAKE setting
    - Create basic batch rendering system and "scene selector" for people to easily debug multiple examples.

**20-05-2020:**

- Added Linux, WSL and Windows support
- Added x86 and x64 support 
- Added example code from own Engine to test workspace
- Added Documentation on how to use workspace
- *To Do*
    - Auto detect target device in `CMake`
    - Auto detect target device in `VsCode`



