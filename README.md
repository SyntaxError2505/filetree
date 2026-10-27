# ftree
a unix-tree-like script to display file structures.

## usage
```sh
# print contents of current directory
ftree

# print contents of a specific directory
ftree path/to/directory
```

## build
### requirements
- Make
- A libc like glibc or musl
- A C compiler
- Unix-like system (unistd.h exposed)

### build process
clone the repo and run `make` inside. An executable will be produced.