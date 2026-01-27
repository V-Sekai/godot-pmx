#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
env.Append(CPPPATH=["src/thirdparty"])
env.Append(CPPPATH=["src/thirdparty/ksy"])
env.Append(CPPPATH=["src/thirdparty/ksy/kaitai"])
sources = Glob("src/*.cpp")+Glob("src/thirdparty/*.cpp")+Glob("src/thirdparty/ksy/*.cpp")+Glob("src/thirdparty/ksy/kaitai/*.cpp")
env.Append(CPPDEFINES=["KS_STR_ENCODING_SHIFT_JIS"])

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/addons/mmd-plugin/mmd-plugin.{}.{}.framework/mmd-plugin.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/addons/mmd-plugin/mmd-plugin.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/addons/mmd-plugin/mmd-plugin.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "demo/addons/mmd-plugin/mmd-plugin{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
