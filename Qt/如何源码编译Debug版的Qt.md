# 如何源码编译Qt

## release编译

## debug版本编译

### Windows 系统
Windows Graphics Drivers
The full feature set of Qt Quick 2 requires OpenGL 2.1 or higher or OpenGL ES 2.0 to work. Several options are available:

Using the native OpenGL driver for your graphics card (Note: The stock Windows driver only supports OpenGL 1.1, which is insufficient).
Using the ANGLE-library to translate OpenGL calls into DirectX. A copy of ANGLE is bundled in Qt 5.
Using a software rasterizer shipped in the Qt SDK. See MesaLlvmpipe for instructions on how that is built.
Starting with Qt 5.8, many Qt Quick applications can also be run with the built-in software backend (previously known as the Qt Quick 2D Renderer). This is not the same as running through a full OpenGL software rasterizer, and is a lot more lightweight. See the documentation on how to request a specific backend.

Qt can be built to dynamically choose the OpenGL implementation (see Dynamically Loading Graphics Drivers) by passing the option -opengl dynamic to configure. To build Qt to always use the native OpenGL driver, pass -opengl desktop. To build Qt to always use ANGLE, pass -opengl es2.

ANGLE dependencies
MSVC
Qt < 5.12: Building ANGLE with Windows SDKs prior to Windows Kit 8 requires the DirectX SDK to be installed, and the path to the d3d_compiler<xx>.dll to be added to the PATH variable.
Qt >= 5.12: Qt needs at least a Windows 10 SDK in order to build ANGLE. No additional manual setup is needed
MinGW
Building ANGLE with Windows SDKs prior to Windows Kit 8 requires the DirectX SDK to be installed, and the path to the d3d_compiler<xx>.dll to be added to the PATH variable.
Any project that uses run-time shader compilation must have D3DCOMPILER_xx.DLL copied to the local executable path for the project. This DLL is available in this sub-directory of the Windows SDK installation under %ProgramFiles(x86)%\Windows Kits\<version>\Redist\D3D\<arch> where <arch> is x86 and x64 (see [1]).

Supported Compilers on Windows
Visual Studio 2019
Visual Studio 2017 (might need a recent service pack, especially for QtWebEngine)
MinGW-w64 based compiler with g++ version 7.3 or higher (e.g. MinGW-builds, see also MinGW-64-bit).
Notes:

Add the compiler to the PATH environment variable. Visual Studio usually ships .bat files named vcvarsall.bat or similar that can be called with a command line parameter for choosing the toolchain (/x86, /x64, etc) to set up the environment.
Windows SDK v6.0A/v7.0A contains the same compiler as Visual Studio 2008/2010.
Windows SDK 8.0 and later do not include a compiler.
As of 16.3.2012, if you wish to install both Visual Studio 2010 and the standalone SDK, you need to follow this order (see readme.html provided with the service pack):
Install Visual Studio 2010
Install Windows SDK 7.1. See also the Cannot Install Windows SDK page.
Install Visual Studio 2010 SP1
Install Visual C++ 2010 SP1 Compiler Update for the Windows SDK 7.1
Windows Build environment
We recommend creating a command prompt that provides the build environment (see the Qt Creator README ). In this environment, Python (e.g. Active Python 2.7 later) and Perl (e.g. StrawberryPerl 5.12 or later) should be in the PATH. Ruby is required for WebKit.

Hint: If you installed git with the non-recommended setting to add git's entire Unix environment to PATH, make sure that Perl is added to the path in front of git, since that ships an incompatible build of perl, which would cause the scripts to fail. Also, MinGW builds of Qt become Msys builds due to the presence of sh.exe; and those who've tried have had more success configuring and building for MinGW in MS's cmd.exe Command Prompt than in the Git Bash shell.

Multicore building: To speed up building when using nmake, the compiler can be instructed to use all available CPU cores in one of the following ways:

Pass the option -mp to Qt's configure
Set the environment variable CL (specifying Visual Studio compiler options) to /MP (On the command line: set CL=/MP)
Use the tool jom instead of nmake. (Using jom instead of nmake reduces compile time quite a bit)
Configuring Visual Studio 2013 on Windows 8, 8.1 & 10
Setting the environment variables to properly build Qt can be done by following the steps below:

Create a file called qt5vars.bat, paste the following inside it and save it
Hint: Remember to change <arch> to your desired platform and double-check that the paths are correct for Qt and Visual Studio

@echo off

REM Set up \Microsoft Visual Studio 2015, where <arch> is \c amd64, \c x86, etc.
CALL "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" <arch>

REM Edit this location to point to the source code of Qt
SET _ROOT=C:\qt5

SET PATH=%_ROOT%\qtbase\bin;%_ROOT%\gnuwin32\bin;%PATH%

REM Uncomment the below line when using a git checkout of the source repository
SET PATH=%_ROOT%\qtrepotools\bin;%PATH%

REM Uncomment the below line when building with OpenSSL enabled. If so, make sure the directory points
REM to the correct location (binaries for OpenSSL).
REM SET PATH=C:\OpenSSL-Win32\bin;%PATH%

REM When compiling with ICU, uncomment the lines below and change <icupath> appropriately:
REM SET INCLUDE=<icupath>\include;%INCLUDE%
REM SET LIB=<icupath>\lib;%LIB%
REM SET PATH=<icupath>\lib;%PATH%

REM Contrary to earlier recommendations, do NOT set QMAKESPEC.

SET _ROOT=

REM Keeps the command line open when this script is run.
cmd /k
Complete the steps below after you have cloned Qt5 from Git

After having cloned Qt5 from Git (assuming it's at C:\Qt5), move qt5vars.bat to the Qt5 folder
Double-click on the script to run it. Once it runs the script, the command prompt will stay open to enter additional commands.
Navigate to C:\Qt5 in the command prompt
The working directory should be c:\Qt5.

All the required environment variables are now correctly set up and building Qt5 with nmake should work now. You have to run qt5vars.bat and use the command prompt every time you build Qt5 with nmake.

The above steps also work for setting up nmake to build jom.


Configuring MinGW on Windows 8, 8.1 & 10
The configuration process is similar to above except for a few minor changes in the qt5vars.bat script:

@echo off

REM Edit this location to point to the source code of Qt
SET _ROOT=C:\qt5

SET PATH=%_ROOT%\qtbase\bin;%_ROOT%\gnuwin32\bin;%PATH%

REM Uncomment the below line when using a git checkout of the source repository
SET PATH=%_ROOT%\qtrepotools\bin;%PATH%

REM Uncomment the below line when building with OpenSSL enabled. If so, make sure the directory points
REM to the correct location (binaries for OpenSSL).
REM SET PATH=C:\OpenSSL-Win32\bin;%PATH%

REM When compiling with ICU, uncomment the lines below and change <icupath> appropriately:
REM Note that -I <icupath>\include and -L <icupath>\lib need to be passed to
REM configure separately (that works for MSVC as well).
REM SET PATH=<icupath>\lib;%PATH%

REM Contrary to earlier recommendations, do NOT set QMAKESPEC.

SET _ROOT=

REM Keeps the command line open when this script is run.
cmd /k

ICU on Windows
Qt 5 can make use of the ICU library for UNICODE and Localization support. This is required for building Qt WebKit. You can use pre-compiled versions of ICU with a Visual Studio 2010 dependency from the website, get pre-compiled versions for different compilers from download.qt.io, or compile ICU on your own.

The absolute paths of include and lib folders of the ICU installation must be passed with -I and -L option to Qt's configure. In addition, uic.exe needs to find the ICU DLLs during compilation, for which the lib folder of the ICU installation must be added to the PATH environment variable.

At run-time, the ICU DLLs need to be found. This can be achieved by copying the DLLs to the application folder or adding the lib folder of the ICU installation to the PATH environment variable.

Getting the source code
First, cd into the directory where you want the "qt5" directory to live. Then, clone the top-level Qt 5 git repository:

$ git clone git://code.qt.io/qt/qt5.git
or (if you're behind a firewall and want to use the https protocol):

$ git clone https://code.qt.io/qt/qt5.git
This creates a local branch that tracks "origin/dev". If you plan to submit changes to Qt, stay on this branch. Otherwise, check out the target branch (see Branch Guidelines):

$ cd qt5
$ git checkout 5.12
For commercial-only modules and commercial-only branches of public modules, see Getting Commercial Qt Sources.

Getting the submodule source code
As described in the README.git, initialize the repository using the init-repository script, which clones the various sub-modules of Qt 5.

Relevant options for init-repository:

--module-subset=default,-qtwebengine : Consider skipping the web module (Qt WebEngine) by passing this option. It is quite big and takes a long time to compile (and is often a source of compile errors), so it is recommended to only download it if you intend to use it. You can always re-run init-repository later on to add it.
--branch : Check out the branch tips instead of the SHA1s of the latest successful integration build.
--codereview-username <Jira/Gerrit username> : If you plan to contribute to Qt, you may specify your codereview username (pay attention to capitalization!) so that the git remotes are properly set up. Note that it is recommended to adjust your ssh configuration instead.
$ cd qt5
$ perl init-repository
In order to build a specific release of Qt, you can checkout the desired tag:

$ cd qt5
$ git checkout 5.12.0
$ perl init-repository
Note: init-repository is currently unable to initialize tags that are too old. An alternative way to build a specific release or branch of Qt5 (although without linking of the gerrit account for code reviewing) is to use git submodule update --init in place of the init-repository script. That translates to:

$ git clone https://code.qt.io/qt/qt5.git                     # cloning the repo
$ cd qt5
$ git checkout v5.8.0                                         # checking out the specific release or branch
$ git submodule update --init --recursive                     # updating each submodule to match the supermodule
More information can be found in Get The Source.

Configuring and Building
The Qt5 build system should be fairly resilient against any "outside distractions" - it shouldn't matter whether you have other Qt versions in PATH, and QTDIR is entirely ignored. However, make sure that you have no qmake-specific environment variables like QMAKEPATH or QMAKEFEATURES set, and the qmake -query output does not refer to any other Qt versions ($HOME/.config/Qt/QMake.conf should be empty).

For more configure options, see Qt Configure Options.

Note: To build qdoc and Qt documentation in future you should set LLVM_INSTALL_DIR environment variable pointing to directory where LLVM is installed (it should be top level directory, the configuration scripts use relative path tracing from this directory). For example, in Linux with LLVM installed in isolated directory (/usr/llvm), at a bash prompt:

$ export LLVM_INSTALL_DIR=/usr/llvm
A build script called configure (or configure.bat for Windows) will be in the directory that you git cloned the source code into (~/qt5 if you followed the directions above). You will want to call that script from a different, parallel-level directory, because (unless you are using a Qt Autotest Environment) you do not want to build Qt in the directory that holds the source code. Instead, you should use a "shadow build," meaning you should not build into the source directory.

For Linux / macOS, to install in ~/qt5-build (an arbitrary name), assuming you are in ~:

$ mkdir qt5-build
$ cd qt5-build
$ ../qt5/configure -developer-build -opensource -nomake examples -nomake tests
For Windows, again assuming you are in ~:

$ mkdir qt5-build
$ cd qt5-build
$ ..\\qt5\configure -developer-build -opensource -nomake examples -nomake tests
The -developer-build option causes more symbols to be exported in order to allow more classes and functions to be unit tested than in a regular Qt build. It also defaults to a 'debug' build, and installs the binaries in the current directory, avoiding the need for 'make install'. '-opensource' sets the license to be GPL/LGPL. The -nomake examples and -nomake tests parameters make sure examples and tests aren't compiled by default. You can always decide to compile them later by hand.

Some Hints

You can add -confirm-license to get rid of the question whether you agree to the license.
On Windows, you might not be able to build if sh.exe is in your PATH (for example due to a git or msys installation). Such an error is indicated by qt5-src\qtbase\bin\qmake.exe: command not found and alike. In this case, make sure that sh.exe is not in your path. You will have to re-configure if your installation is already configured.
If you are planning to make contributions with git, it is advised to configure and build the source in a separate directory so the binaries are not seen by git. This can be done by navigating to the desired build directory and calling configure/make in that directory. (But shadow builds are discouraged in Qt Autotest Environment.)
Note: If you do a shadow build, follow the instructions above for creating a build directory that is parallel to the source directory. Do NOT make the build directory a subdirectory of the source tree. The build will probably fail in weird ways if the build directory is not exactly parallel to the source directory.
Now trigger the build from within the build directory by running:

$ make -j$(nproc)
For Windows (MSVC), choose one of the following, depending on your setup/environment:

$ nmake
or

$ jom
or

$ mingw32-make
Or only build a specific module, e.g. declarative, and modules it depends on:

$ make module-qtdeclarative
Building Qt WebKit
Windows
WebKit.org has instructions for building WebKit on Windows. ICU is required for building.

The tools bison, flex and gperf which are required for building are provided for convenience in the folder gnuwin32\bin. If you are using shadow builds, you must add this directory to your PATH, else no special actions need to be done manually in order to use them.

## 参考链接

[Qt5官方文档](https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code)
