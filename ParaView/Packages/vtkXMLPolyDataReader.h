/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkXMLPolyDataReader.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkXMLPolyDataReader
// .SECTION Description
// vtkXMLPolyDataReader

#ifndef __vtkXMLPolyDataReader_h
#define __vtkXMLPolyDataReader_h

#include "vtkXMLUnstructuredDataReader.h"

class vtkPolyData;

class VTK_IO_EXPORT vtkXMLPolyDataReader : public vtkXMLUnstructuredDataReader
{
public:
  vtkTypeRevisionMacro(vtkXMLPolyDataReader,vtkXMLUnstructuredDataReader);
  void PrintSelf(ostream& os, vtkIndent indent);  
  static vtkXMLPolyDataReader *New();
  
  // Description:
  // Get/Set the reader's output.
  void SetOutput(vtkPolyData *output);
  vtkPolyData *GetOutput();
  
  // Description:
  // Get the number of verts/lines/strips/polys in the output.
  virtual vtkIdType GetNumberOfVerts();
  virtual vtkIdType GetNumberOfLines();
  virtual vtkIdType GetNumberOfStrips();
  virtual vtkIdType GetNumberOfPolys();
  
protected:
  vtkXMLPolyDataReader();
  ~vtkXMLPolyDataReader();
  
  const char* GetDataSetName();
  void GetOutputUpdateExtent(int& piece, int& numberOfPieces, int& ghostLevel);
  void SetupOutputTotals();
  void SetupNextPiece();
  void SetupPieces(int numPieces);
  void DestroyPieces();
  
  void SetupOutputData();
  int ReadPiece(vtkXMLDataElement* ePiece);
  int ReadPieceData();
  
  // Read a data array whose tuples coorrespond to cells.
  int ReadArrayForCells(vtkXMLDataElement* da, vtkDataArray* outArray);
  
  // The size of the UpdatePiece.
  int TotalNumberOfVerts;
  int TotalNumberOfLines;
  int TotalNumberOfStrips;
  int TotalNumberOfPolys;
  vtkIdType StartVert;
  vtkIdType StartLine;
  vtkIdType StartStrip;
  vtkIdType StartPoly;
  
  // The cell elements for each piece.
  vtkXMLDataElement** VertElements;
  vtkXMLDataElement** LineElements;
  vtkXMLDataElement** StripElements;
  vtkXMLDataElement** PolyElements;
  vtkIdType* NumberOfVerts;
  vtkIdType* NumberOfLines;
  vtkIdType* NumberOfStrips;
  vtkIdType* NumberOfPolys;
  
private:
  vtkXMLPolyDataReader(const vtkXMLPolyDataReader&);  // Not implemented.
  void operator=(const vtkXMLPolyDataReader&);  // Not implemented.
};

#endif
