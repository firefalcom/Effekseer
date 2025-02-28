
SET RDIR_R=EffekseerRuntime_DXLib

rmdir %RDIR_R%
mkdir %RDIR_R%

echo Copy runtime
mkdir %RDIR_R%\RuntimeSample\
mkdir %RDIR_R%\RuntimeSample\lib
mkdir %RDIR_R%\RuntimeSample\include

mkdir %RDIR_R%\src
mkdir %RDIR_R%\src\include
mkdir %RDIR_R%\src\lib

copy Dev\Cpp\Effekseer\Effekseer.h %RDIR_R%\src\include\.
copy Dev\Cpp\EffekseerRendererDX9\EffekseerRendererDX9.h %RDIR_R%\src\include\.
copy Dev\Cpp\EffekseerRendererDX11\EffekseerRendererDX11.h %RDIR_R%\src\include\.
copy Dev\Cpp\EffekseerRendererGL\EffekseerRendererGL.h %RDIR_R%\src\include\.
copy Dev\Cpp\EffekseerSoundXAudio2\EffekseerSoundXAudio2.h %RDIR_R%\src\include\.
copy Dev\Cpp\EffekseerSoundAL\EffekseerSoundAL.h %RDIR_R%\src\include\.

copy Dev\Cpp\EffekseerRendererDX9.sln %RDIR_R%\src\.
copy Dev\Cpp\EffekseerRendererDX11.sln %RDIR_R%\src\.
copy Dev\Cpp\EffekseerRendererGL.sln %RDIR_R%\src\.

mkdir %RDIR_R%\src\Effekseer
robocopy Dev\Cpp\Effekseer %RDIR_R%\src\Effekseer *.h *.cpp *.filters *.vcxproj *.fx /S

mkdir %RDIR_R%\src\EffekseerRendererDX9
robocopy Dev\Cpp\EffekseerRendererDX9 %RDIR_R%\src\EffekseerRendererDX9 *.h *.cpp *.filters *.vcxproj *.fx /S

mkdir %RDIR_R%\src\EffekseerRendererDX11
robocopy Dev\Cpp\EffekseerRendererDX11 %RDIR_R%\src\EffekseerRendererDX11 *.h *.cpp *.filters *.vcxproj *.fx /S

mkdir %RDIR_R%\src\EffekseerRendererGL
robocopy Dev\Cpp\EffekseerRendererGL %RDIR_R%\src\EffekseerRendererGL *.h *.cpp *.filters *.vcxproj *.fx /S

mkdir %RDIR_R%\src\EffekseerRendererCommon
robocopy Dev\Cpp\EffekseerRendererCommon %RDIR_R%\src\EffekseerRendererCommon *.h *.cpp *.filters *.vcxproj *.fx /S

mkdir %RDIR_R%\src\EffekseerSoundXAudio2
robocopy Dev\Cpp\EffekseerSoundXAudio2 %RDIR_R%\src\EffekseerSoundXAudio2 *.h *.cpp *.filters *.vcxproj *.fx /S

mkdir %RDIR_R%\src\EffekseerSoundAL
robocopy Dev\Cpp\EffekseerSoundAL %RDIR_R%\src\EffekseerSoundAL *.h *.cpp *.filters *.vcxproj *.fx /S

echo VS

mkdir %RDIR_R%\Compiled\

echo Compile VS16
rmdir /S /Q VS16
mkdir VS16

cd VS16
call cmake.bat -G "Visual Studio 16" -A Win32 -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../
cmake.exe -G "Visual Studio 16" -A Win32 -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../

"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Debug
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Release
cd ..

echo Compile VS16WIN64
rmdir /S /Q VS16WIN64
mkdir VS16WIN64

cd VS16WIN64
call cmake.bat -G "Visual Studio 16" -A x64  -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../
cmake.exe -G "Visual Studio 16" -A x64  -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../

"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Debug
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Release
cd ..


echo Compile VS17
rmdir /S /Q VS17
mkdir VS17

cd VS17
call cmake.bat -G "Visual Studio 17" -A Win32 -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../
cmake.exe -G "Visual Studio 17" -A Win32 -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../

"C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Debug
"C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Release
cd ..

echo Compile VS17WIN64
rmdir /S /Q VS17WIN64
mkdir VS17WIN64

cd VS17WIN64
call cmake.bat -G "Visual Studio 17" -A x64  -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../
cmake.exe -G "Visual Studio 17" -A x64  -D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF -D USE_XAUDIO2=ON -D BUILD_EXAMPLES=OFF ../

"C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Debug
"C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe" Effekseer.sln /p:configuration=Release
cd ..


mkdir %RDIR_R%\Compiled\include\
mkdir %RDIR_R%\Compiled\lib\


mkdir %RDIR_R%\Compiled\lib\VS2019\
mkdir %RDIR_R%\Compiled\lib\VS2019WIN64\

robocopy VS16\Dev\Cpp\Effekseer\Debug %RDIR_R%\Compiled\lib\VS2019\Debug *.lib /S
robocopy VS16\Dev\Cpp\Effekseer\Release %RDIR_R%\Compiled\lib\VS2019\Release *.lib /S

robocopy VS16\Dev\Cpp\EffekseerRendererDX9\Debug %RDIR_R%\Compiled\lib\VS2019\Debug *.lib /S
robocopy VS16\Dev\Cpp\EffekseerRendererDX9\Release %RDIR_R%\Compiled\lib\VS2019\Release *.lib /S

robocopy VS16\Dev\Cpp\EffekseerRendererDX11\Debug %RDIR_R%\Compiled\lib\VS2019\Debug *.lib /S
robocopy VS16\Dev\Cpp\EffekseerRendererDX11\Release %RDIR_R%\Compiled\lib\VS2019\Release *.lib /S

robocopy VS16\Dev\Cpp\3rdParty\LLGI\src\Debug %RDIR_R%\Compiled\lib\VS2019\Debug *.lib /S
robocopy VS16\Dev\Cpp\3rdParty\LLGI\src\Release %RDIR_R%\Compiled\lib\VS2019\Release *.lib /S

robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX12\Debug %RDIR_R%\Compiled\lib\VS2019WIN64\Debug *.lib /S
robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX12\Release %RDIR_R%\Compiled\lib\VS2019WIN64\Release *.lib /S

copy VS16\Dev\Cpp\EffekseerSoundXAudio2\Debug\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2019\Debug\.
copy VS16\Dev\Cpp\EffekseerSoundXAudio2\Release\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2019\Release\.

robocopy VS16WIN64\Dev\Cpp\Effekseer\Debug %RDIR_R%\Compiled\lib\VS2019WIN64\Debug *.lib /S
robocopy VS16WIN64\Dev\Cpp\Effekseer\Release %RDIR_R%\Compiled\lib\VS2019WIN64\Release *.lib /S

robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX9\Debug %RDIR_R%\Compiled\lib\VS2019WIN64\Debug *.lib /S
robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX9\Release %RDIR_R%\Compiled\lib\VS2019WIN64\Release *.lib /S

robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX11\Debug %RDIR_R%\Compiled\lib\VS2019WIN64\Debug *.lib /S
robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX11\Release %RDIR_R%\Compiled\lib\VS2019WIN64\Release *.lib /S

robocopy VS16WIN64\Dev\Cpp\3rdParty\LLGI\src\Debug %RDIR_R%\Compiled\lib\VS2019WIN64\Debug *.lib /S
robocopy VS16WIN64\Dev\Cpp\3rdParty\LLGI\src\Release %RDIR_R%\Compiled\lib\VS2019WIN64\Release *.lib /S

robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX12\Debug %RDIR_R%\Compiled\lib\VS2019WIN64\Debug *.lib /S
robocopy VS16WIN64\Dev\Cpp\EffekseerRendererDX12\Release %RDIR_R%\Compiled\lib\VS2019WIN64\Release *.lib /S

copy VS16WIN64\Dev\Cpp\EffekseerSoundXAudio2\Debug\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2019WIN64\Debug\.
copy VS16WIN64\Dev\Cpp\EffekseerSoundXAudio2\Release\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2019WIN64\Release\.


mkdir %RDIR_R%\Compiled\lib\VS2022\
mkdir %RDIR_R%\Compiled\lib\VS2022WIN64\

robocopy VS17\Dev\Cpp\Effekseer\Debug %RDIR_R%\Compiled\lib\VS2022\Debug *.lib /S
robocopy VS17\Dev\Cpp\Effekseer\Release %RDIR_R%\Compiled\lib\VS2022\Release *.lib /S

robocopy VS17\Dev\Cpp\EffekseerRendererDX9\Debug %RDIR_R%\Compiled\lib\VS2022\Debug *.lib /S
robocopy VS17\Dev\Cpp\EffekseerRendererDX9\Release %RDIR_R%\Compiled\lib\VS2022\Release *.lib /S

robocopy VS17\Dev\Cpp\EffekseerRendererDX11\Debug %RDIR_R%\Compiled\lib\VS2022\Debug *.lib /S
robocopy VS17\Dev\Cpp\EffekseerRendererDX11\Release %RDIR_R%\Compiled\lib\VS2022\Release *.lib /S

robocopy VS17\Dev\Cpp\3rdParty\LLGI\src\Debug %RDIR_R%\Compiled\lib\VS2022\Debug *.lib /S
robocopy VS17\Dev\Cpp\3rdParty\LLGI\src\Release %RDIR_R%\Compiled\lib\VS2022\Release *.lib /S

robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX12\Debug %RDIR_R%\Compiled\lib\VS2022WIN64\Debug *.lib /S
robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX12\Release %RDIR_R%\Compiled\lib\VS2022WIN64\Release *.lib /S

copy VS17\Dev\Cpp\EffekseerSoundXAudio2\Debug\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2022\Debug\.
copy VS17\Dev\Cpp\EffekseerSoundXAudio2\Release\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2022\Release\.

robocopy VS17WIN64\Dev\Cpp\Effekseer\Debug %RDIR_R%\Compiled\lib\VS2022WIN64\Debug *.lib /S
robocopy VS17WIN64\Dev\Cpp\Effekseer\Release %RDIR_R%\Compiled\lib\VS2022WIN64\Release *.lib /S

robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX9\Debug %RDIR_R%\Compiled\lib\VS2022WIN64\Debug *.lib /S
robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX9\Release %RDIR_R%\Compiled\lib\VS2022WIN64\Release *.lib /S

robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX11\Debug %RDIR_R%\Compiled\lib\VS2022WIN64\Debug *.lib /S
robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX11\Release %RDIR_R%\Compiled\lib\VS2022WIN64\Release *.lib /S

robocopy VS17WIN64\Dev\Cpp\3rdParty\LLGI\src\Debug %RDIR_R%\Compiled\lib\VS2022WIN64\Debug *.lib /S
robocopy VS17WIN64\Dev\Cpp\3rdParty\LLGI\src\Release %RDIR_R%\Compiled\lib\VS2022WIN64\Release *.lib /S

robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX12\Debug %RDIR_R%\Compiled\lib\VS2022WIN64\Debug *.lib /S
robocopy VS17WIN64\Dev\Cpp\EffekseerRendererDX12\Release %RDIR_R%\Compiled\lib\VS2022WIN64\Release *.lib /S

copy VS17WIN64\Dev\Cpp\EffekseerSoundXAudio2\Debug\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2022WIN64\Debug\.
copy VS17WIN64\Dev\Cpp\EffekseerSoundXAudio2\Release\EffekseerSoundXAudio2.lib %RDIR_R%\Compiled\lib\VS2022WIN64\Release\.


copy Dev\Cpp\Effekseer\Effekseer.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\Effekseer\Effekseer.Modules.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\Effekseer\Effekseer.SIMD.h %RDIR_R%\Compiled\include\.

copy Dev\Cpp\EffekseerRendererDX9\EffekseerRendererDX9.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\EffekseerRendererDX11\EffekseerRendererDX11.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\EffekseerRendererDX12\EffekseerRendererDX12.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\EffekseerRendererGL\EffekseerRendererGL.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\EffekseerSoundXAudio2\EffekseerSoundXAudio2.h %RDIR_R%\Compiled\include\.
copy Dev\Cpp\EffekseerSoundAL\EffekseerSoundAL.h %RDIR_R%\Compiled\include\.

pause

