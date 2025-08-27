from conan import ConanFile
from conan.tools.files import copy
from os.path import join
from conan.tools.cmake import CMake
from conan.tools.scm import Git
from conan.tools.files import load, update_conandata


class EffekseerConan(ConanFile):
    name            = "effekseer"
    version         = "170-1"
    description     = "Conan package for Effekseer."
    url             = "https://github.com/effekseer/Effekseer"
    license         = "MIT"
    settings        = "arch", "build_type", "compiler", "os"
    generators      = "CMakeDeps", "CMakeToolchain"
    options         = {
            "shared": [True, False],
            "network_enabled" : [True, False],
            }
    default_options = {
            "shared": False,
            "network_enabled" : True,
            }


    def export(self):
        git = Git(self, self.recipe_folder)
        scm_url, scm_commit = git.get_url_and_commit()
        update_conandata(self, {"sources": {"commit": scm_commit, "url": scm_url}})

    def source(self):

        sources = self.conan_data["sources"]

        git = Git(self)
        git.clone(url=sources["url"], target=".")
        git.checkout(commit=sources["commit"])
        self.run("git submodule update --init --recursive")

    def build(self):
        cmake = CMake(self)
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
            "NETWORK_ENABLED" : self.options.network_enabled,
            "BUILD_SHARED_LIBS": self.options.shared,
            "USE_MSVC_RUNTIME_LIBRARY_DLL" : True,
            }

        cmake.configure(options)
        cmake.build()

    def package(self):
        cmake  = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["EffekseerRendererCommon", "Effekseer"]
        self.cpp_info.includedirs = ["include","include/Effekseer"]
