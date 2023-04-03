from   conans       import ConanFile, CMake

class EffekseerConan(ConanFile):
    name            = "effekseer"
    version         = "170"
    description     = "Conan package for Effekseer."
    url             = "https://github.com/effekseer/Effekseer"
    license         = "MIT"
    settings        = "arch", "build_type", "compiler", "os"
    generators      = "cmake"
    options         = {
            "shared": [True, False]
            }
    default_options = {
            "shared": False
            }

    scm ={
        "type": "git",
        "url": "auto",
        "revision": "auto",
        "submodule": "shallow"
    }

    def build(self):
        cmake          = CMake(self)
        options = {

            "BUILD_EXAMPLES" : False,
            "BUILD_GL" : False,
            "BUILD_DX9" : False,
            "BUILD_DX11" : False,
            "BUILD_DX12" : False,
            "BUILD_METAL" : False,
            "BUILD_RENDERER" : True,
            "USE_OPENAL" : False,
            "USE_XAUDIO2" : False,
            "USE_DSOUND" : False,
            "BUILD_SHARED_LIBS": self.options.shared,
            "USE_MSVC_RUNTIME_LIBRARY_DLL" : True
            }

        cmake.configure(None, options)
        cmake.build()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["Effekseer", "EffekseerRendererCommon"]
        self.cpp_info.includedirs = ["include","include/Effekseer"]