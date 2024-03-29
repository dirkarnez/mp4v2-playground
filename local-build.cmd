REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOADS_DIR=%USERPROFILE%\Downloads
set DOWNLOADS_DIR_LINUX=%DOWNLOADS_DIR:\=/%

SET PATH=^
%DOWNLOADS_DIR%\PortableGit\bin;^
%DOWNLOADS_DIR%\x86_64-8.1.0-release-posix-seh-rt_v6-rev0;^
%DOWNLOADS_DIR%\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\bin;^
%DOWNLOADS_DIR%\cmake-3.22.2-windows-x86_64\bin;

@REM set PATH=^
@REM D:\Softwares\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64;^
@REM D:\Softwares\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin;^
@REM D:\Softwares\cmake-3.23.0-rc1-windows-x86_64\bin;

cmake.exe -G"MinGW Makefiles" ^
-DCMAKE_BUILD_TYPE=Debug ^
-Dmp4v2_ROOT="%DOWNLOADS_DIR_LINUX%/mp4v2-v2.1.1-mingw64-x86_64-posix-seh-rev0-8.1.0" ^
-DX264_ROOT="%DOWNLOADS_DIR_LINUX%/x264-cbaee400fa9ced6f5481a728138fed6e867b0ff7f-x86_64-posix-seh-rev0-8.1.0" ^
-B./build &&^
cd build &&^
cmake --build . &&^
echo "Successful build"
pause