/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkXMLPUnstructuredDataWriter.h
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
// .NAME vtkXMLPUnstructuredDataWriter - Write image data in a parallel XML format.
// .SECTION Description
// vtkXMLPUnstructuredDataWriter

#ifndef __vtkXMLPUnstructuredDataWriter_h
#define __vtkXMLPUnstructuredDataWriter_h

#include "vtkXMLPDataWriter.h"

class vtkPointSet;
class vtkXMLUnstructuredDataWriter;

class VTK_IO_EXPORT vtkXMLPUnstructuredDataWriter : public vtkXMLPDataWriter
{
public:
  vtkTypeRevisionMacro(vtkXMLPUnstructuredDataWriter,vtkXMLPDataWriter);
  void PrintSelf(ostream& os, vtkIndent indent);  
  
protected:
  vtkXMLPUnstructuredDataWriter();
  ~vtkXMLPUnstructuredDataWriter();
  
  vtkPointSet* GetInputAsPointSet();
  
  virtual vtkXMLUnstructuredDataWriter* CreateUnstructuredPieceWriter()=0;
  vtkXMLWriter* CreatePieceWriter();
  void WritePData(vtkIndent indent);
  
private:
  vtkXMLPUnstructuredDataWriter(const vtkXMLPUnstructuredDataWriter&);  // Not implemented.
  void operator=(const vtkXMLPUnstructuredDataWriter&);  // Not implemented.
};

#endif
