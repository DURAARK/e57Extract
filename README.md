E57 METADATA EXTRACTION
=======================

A utility to extract metadata from E57 point cloud files.

Build instructions
------------------

Everything in this folder is cmake-buildable.

So under *nix in this folder:

    mkdir build
    cd build
    cmake ..
    (optionally: ccmake .)
    make
    sudo make install

Under windows start cmake-gui, choose this folder and a build folder and click "Configure" followed by "Generate"
(Keep in mind to change the CMAKE_INSTALL_PREFIX if you want).

Installation yields extractor executable, header/cs files and the DLL.
