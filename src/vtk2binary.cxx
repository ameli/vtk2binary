/*
 * ============================================================================
 *
 *       Filename:  vtk2binary.cxx
 *
 *    Description:  Converts ascii VTK files to binary files
 *
 *        Version:  1.0
 *        Created:  05/15/2014 02:00:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siavash Ameli
 *   Organization:  University Of California, Berkeley
 *
 * ============================================================================
 */


// =======
// Headers
// =======

#include <cstdlib>   // for atio
#include <vtkSmartPointer.h>
#include <vtkStructuredPointsReader.h>
#include <vtkStructuredPointsWriter.h>
#include <vtkXMLImageDataWriter.h>
#include <vtkPolyDataReader.h>
#include <vtkPolyDataWriter.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkStructuredGridReader.h>
#include <vtkStructuredGridWriter.h>
#include <vtkXMLStructuredGridWriter.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkXMLUnstructuredGridWriter.h>


// =====
// Types
// =====

enum ModeType
{
    IMAGEDATA_TO_BINARY_VTK = 1,
    IMAGEDATA_TO_BINARY_VTI,
    POLYDATA_TO_BINARY_VTK,
    POLYDATA_TO_BINARY_VTP,
    STRUCTUREDGRID_TO_BINARY_VTK,
    STRUCTUREDGRID_TO_BINARY_VTS,
    UNSTRUCTUREDGRID_TO_BINARY_VTK,
    UNSTRUCTUREDGRID_TO_BINARY_VTU
};


// ==========
// Prototypes
// ==========

void PrintUsage(char *ExecutableName);
void ImageDataToBinaryVTK(char *InputFileName,char *OutputFileName);
void ImageDataToBinaryVTI(char *InputFileName,char *OutputFileName);
void PolyDataToBinaryVTK(char *InpuFile,char *OutputFileName);
void PolyDataToBinaryVTP(char *InputFileName,char *OutputFileName);
void StructuredGridToBinaryVTK(char *InputFileName,char *OutputFileName);
void StructuredGridToBinaryVTS(char *InputFileName,char *OutputFileName);
void UnstructuredGridToBinaryVTK(char *InputFileName,char *OutputFileName);
void UnstructuredGridToBinaryVTU(char *InputFileName,char *OutputFileName);


// ====
// Main
// ====

int main(int argc, char *argv[])
{
    // Check arguments
    if(argc < 4)
    {
        PrintUsage(argv[0]);
        exit(0);
    }

   // Mode
   int Mode = atoi(argv[1]);

    // File Names
    char *InputFileName = argv[2];
    char *OutputFileName = argv[3];

   // Convert baed on selected mode
   switch(Mode)
   {
       // ImageData to Binary VTK
       case IMAGEDATA_TO_BINARY_VTK:
       {
           ImageDataToBinaryVTK(InputFileName,OutputFileName);
           break;
       }

       // ImageData to Binary VTI
       case IMAGEDATA_TO_BINARY_VTI:
       {
           ImageDataToBinaryVTI(InputFileName,OutputFileName);
           break;
       }

       // PolyData to binary VTK
       case POLYDATA_TO_BINARY_VTK:
       {
           PolyDataToBinaryVTK(InputFileName,OutputFileName);
           break;
       }

       // PolyData to binary VTP
       case POLYDATA_TO_BINARY_VTP:
       {
           PolyDataToBinaryVTP(InputFileName,OutputFileName);
           break;
       }

       // StructuredGrid to binary VTK
       case STRUCTUREDGRID_TO_BINARY_VTK:
       {
           StructuredGridToBinaryVTK(InputFileName,OutputFileName);
           break;
       }

       // StructuredGrid to binary VTS
       case STRUCTUREDGRID_TO_BINARY_VTS:
       {
           StructuredGridToBinaryVTS(InputFileName,OutputFileName);
           break;
       }

       // UnstructuredGrid to binary VTK
       case UNSTRUCTUREDGRID_TO_BINARY_VTK:
       {
           UnstructuredGridToBinaryVTK(InputFileName,OutputFileName);
           break;
       }

       // UnstructuredGrid to binary VTU
       case UNSTRUCTUREDGRID_TO_BINARY_VTU:
       {
           UnstructuredGridToBinaryVTU(InputFileName,OutputFileName);
           break;
       }

       // Invalid Mode
       default:
       {
           std::cerr << "Input mode is invalid.\n" << std::endl;
           PrintUsage(argv[0]);
           exit(0);
       }
   }

    return EXIT_SUCCESS;
}


// ===========
// Print Usage
// ===========

void PrintUsage(char *ExecutableName)
{	
    std::cerr << "Usage:  " << ExecutableName   << "Mode  InputFileName.vtk  OutputFileName.vtx" << std::endl;
	std::cerr << "Modes are:" << std::endl
              << IMAGEDATA_TO_BINARY_VTK        << ": ImageData        ASCII VTK to binary VTK"  << std::endl
              << IMAGEDATA_TO_BINARY_VTI        << ": ImageData        ASCII VTK to binary VTI"  << std::endl
              << POLYDATA_TO_BINARY_VTK         << ": PolyData         ASCII VTK to binary VTK"  << std::endl
              << POLYDATA_TO_BINARY_VTP         << ": PolyData         ASCII VTK to binary VTP"  << std::endl
              << STRUCTUREDGRID_TO_BINARY_VTK   << ": StructuredGrid   ASCII VTK to binary VTK"  << std::endl
              << STRUCTUREDGRID_TO_BINARY_VTS   << ": StructuredGrid   ASCII VTK to binary VTS"  << std::endl
              << UNSTRUCTUREDGRID_TO_BINARY_VTK << ": UnstructuredGrid ASCII VTK to binary VTK"  << std::endl;
}


// =======================
// ImageData To Binary VTK
// =======================

// Description:
// Filetype is vtkStructuredPoints
// InputFile is ascii vtk
// OutputFile is binary vtk

void ImageDataToBinaryVTK(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkStructuredPointsReader> Reader = \
            vtkSmartPointer<vtkStructuredPointsReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTK
    vtkSmartPointer<vtkStructuredPointsWriter> Writer = \
            vtkSmartPointer<vtkStructuredPointsWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetFileTypeToBinary();
    Writer->Update(); 
}


// =======================
// ImageData To Binary VTI
// =======================

// Description:
// Data type:  vtkStructuredPoints
// InputFile:  ascii vtk
// OutputFile: binary vti

void ImageDataToBinaryVTI(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkStructuredPointsReader> Reader = \
            vtkSmartPointer<vtkStructuredPointsReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTI
    vtkSmartPointer<vtkXMLImageDataWriter> Writer = \
            vtkSmartPointer<vtkXMLImageDataWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetDataModeToBinary();
    Writer->Update();
}


// ======================
// PolyData To Binary VTK
// ======================

// Description:
// Data type:  vtkPolyData
// InputFile:  ascii vtk
// OutputFile: binary vtk

void PolyDataToBinaryVTK(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkPolyDataReader> Reader = \
            vtkSmartPointer<vtkPolyDataReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTK
    vtkSmartPointer<vtkPolyDataWriter> Writer = \
            vtkSmartPointer<vtkPolyDataWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetFileTypeToBinary();
    Writer->Update(); 
}


// ======================
// PolyData To Binary VTP
// ======================

// Description:
// Data type:  vtkPoyData
// InputFile:  ascii vtk
// OutputFile: binary vtp

void PolyDataToBinaryVTP(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkPolyDataReader> Reader = \
            vtkSmartPointer<vtkPolyDataReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTP
    vtkSmartPointer<vtkXMLPolyDataWriter> Writer = \
            vtkSmartPointer<vtkXMLPolyDataWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetDataModeToBinary();
    Writer->Update(); 
}


// ============================
// StructuredGrid To Binary VTK
// ============================

// Description:
// Data type:  vtkStructuredGrid
// InputFile:  ascii vtk
// OutputFile: binary vtk

void StructuredGridToBinaryVTK(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkStructuredGridReader> Reader = \
            vtkSmartPointer<vtkStructuredGridReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTK
    vtkSmartPointer<vtkStructuredGridWriter> Writer = \
            vtkSmartPointer<vtkStructuredGridWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetFileTypeToBinary();
    Writer->Update(); 
}


// ============================
// StructuredGrid To Binary VTS
// ============================

// Description:
// Data type:  vtkStructuredGrid
// InputFile:  ascii vtk
// OutputFile: binary vts

void StructuredGridToBinaryVTS(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkStructuredGridReader> Reader = \
            vtkSmartPointer<vtkStructuredGridReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTS
    vtkSmartPointer<vtkXMLStructuredGridWriter> Writer = \
            vtkSmartPointer<vtkXMLStructuredGridWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetDataModeToBinary();
    Writer->Update(); 
}


// ==============================
// UnstructuredGrid To Binary VTK
// ==============================

// Description:
// Datat type: vtkUnstructuredGrid
// InputFile:  ascii vtk
// OutputFile: binary vtk

void UnstructuredGridToBinaryVTK(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkUnstructuredGridReader> Reader = \
            vtkSmartPointer<vtkUnstructuredGridReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTK
    vtkSmartPointer<vtkUnstructuredGridWriter> Writer = \
            vtkSmartPointer<vtkUnstructuredGridWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetFileTypeToBinary();
    Writer->Update(); 
}


// ==============================
// UnstructuredGrid To Binary VTU
// ==============================

// Description:
// Data type:  vtkUnstructuredGrid
// InputFile:  ascii vtk
// OutputFile: binary vtu

void UnstructuredGridToBinaryVTU(char *InputFileName,char *OutputFileName)
{
    // Read Data
    vtkSmartPointer<vtkUnstructuredGridReader> Reader = \
            vtkSmartPointer<vtkUnstructuredGridReader>::New();
    Reader->SetFileName(InputFileName);
    Reader->Update();

    // Write to Binary VTU
    vtkSmartPointer<vtkXMLUnstructuredGridWriter> Writer = \
            vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
    Writer->SetInputConnection(Reader->GetOutputPort());
    Writer->SetFileName(OutputFileName);
    Writer->SetDataModeToBinary();
    Writer->Update(); 
}
