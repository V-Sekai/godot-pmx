# How to install

```
# You may need to run
# scoop install llvm
# scoop install go
# go install github.com/google/wuffs/cmd/wuffs-c@latest
# beforehand, to install the wuffs-c compiler.
wuffs-c gen -package_name pmx < pmx.wuffs > pmx.h
```

https://github.com/google/wuffs