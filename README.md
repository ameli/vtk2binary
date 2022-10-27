# VTK to Binary

This code converts an ascii VTK file to a binary VTK, VTI, VTP, or VTS file.

## Prerequisites

1. Install *GNU GCC* compiler, *OpenMP*, and *Cmake*:

       sudo apt-get install g++ libomp-dev cmake -y

2. Install *VTK* development:

       sudo apt install libvtk5-dev -y

   Alternatively, [download VTK](https://vtk.org/download/) and compile it.

## Install

Get the source code

    git clone git@github.com:ameli/vtk2binary.git
    cd vtk2binary

Compile in ``./build`` directory

    mkdir build
    cmake -B build .
    make -C build

After the compilation, the executable file is located in ``./bin/vtk2binary``.

## Usage

    ./bin/vtk2binary Mode  InputFileName.vtk  OutputFileName.vt<x>

The integer input argument ``Mode`` and the corresponding output file extension ``*.vt<x>`` is from the following table.

| Mode  | Data Structure   |  Input File Extension     | Output File Extension     |
| ----- | ---------------- | ------------------------- | ------------------------- |
| ``1`` | ImageData        |  ASCII ``vtk``            | binary ``vtk``            |
| ``2`` | ImageData        |  ASCII ``vtk``            | binary ``vti``            |
| ``3`` | PolyData         |  ASCII ``vtk``            | binary ``vtk``            |
| ``4`` | PolyData         |  ASCII ``vtk``            | binary ``vtp``            |
| ``5`` | StructuredGrid   |  ASCII ``vtk``            | binary ``vtk``            |
| ``6`` | StructuredGrid   |  ASCII ``vtk``            | binary ``vts``            |
| ``7`` | UnstructuredGrid |  ASCII ``vtk``            | binary ``vtk``            |

## License

BSD 3-clause.
