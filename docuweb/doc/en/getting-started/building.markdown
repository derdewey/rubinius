---
layout: doc
title: Building Rubinius
---

You can build and run Rubinius from the source directory. You do not need to
install Rubinius to run it. The directions below will detail both installing
Rubinius and running it from the source directory.

Rubinius uses LLVM for the JIT compiler. Rubinius depends on a particular
version of LLVM. If you have installed LLVM on your system, pass the
'--skip-system' flag to the configure script in the directions below.

### Getting the Source

The Rubinius source code available as a tarball and as a project on Github.
You can [download the tarball here](http://rubini.us/download/latest).

To use Git:

  1. Change your current working directory to your development directory
  2. `git clone git://github.com/evanphx/rubinius.git`


### Installing Rubinius

If you are planning on using Rubinius to run your application, this is a good
option. However, you can also run Rubinius directly from the source directory.
See the next section for more details on that.

We recommend installing Rubinius to a location that does not require `sudo` or
superuser privileges. To install Rubinius:

  1. `./configure --prefix=/path/to/install/dir`
  2. `rake install`
  3. Follow the directions to add the Rubinius _bin_ directory to your PATH


### Running from the Source Directory

If you plan to work on Rubinius itself, you should use this option.

  1. `./configure`
  2. `rake`

If you are just trying out Rubinius, follow the directions to add the _bin_
directory to your PATH.

However, if you are developing Rubinius, you should NOT add the _bin_
directory to your PATH because the Rubinius build system will pick up the
`ruby` and `rake` links to the Rubinius executable. Rubinius needs a separate
Ruby executable to bootstrap itself during the build process.
