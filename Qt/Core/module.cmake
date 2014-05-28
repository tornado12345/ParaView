if (PARAVIEW_ENABLE_QT_GUI OR PARAVIEW_ENABLE_QT_SUPPORT)
  vtk_module(pqCore
    GROUPS
      ParaViewQt
    DEPENDS
      pqWidgets
      vtkGUISupportQt
      vtkPVServerManagerApplication
      vtkPVServerManagerDefault
    PRIVATE_DEPENDS
      vtksys
    EXCLUDE_FROM_WRAPPING
    TEST_LABELS
      PARAVIEW
  )
endif ()
