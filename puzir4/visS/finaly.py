# -*- coding: utf-8 -*-

###
### This file is generated automatically by SALOME v8.3.0 with dump python functionality
###

import sys
import salome

salome.salome_init()
theStudy = salome.myStudy

import salome_notebook
notebook = salome_notebook.NoteBook(theStudy)
sys.path.insert( 0, r'C:/Users/Public/SALOME-8.3.0-WIN64/WORK')

###
### GEOM component
###

import GEOM
from salome.geom import geomBuilder
import math
import SALOMEDS


geompy = geomBuilder.New(theStudy)

O = geompy.MakeVertex(0, 0, 0)
OX = geompy.MakeVectorDXDYDZ(1, 0, 0)
OY = geompy.MakeVectorDXDYDZ(0, 1, 0)
OZ = geompy.MakeVectorDXDYDZ(0, 0, 1)

Sphere_0 = geompy.MakeSphereR(0.118885)
geompy.TranslateDXDYDZ(Sphere_0, 7.07585, 8.02432, 8.7637)
Sphere_0.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_0, 'Bubble_0' )
Sphere_1 = geompy.MakeSphereR(0.944246)
geompy.TranslateDXDYDZ(Sphere_1, 4.5024, 2.39389, 6.05482)
Sphere_1.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_1, 'Bubble_1' )
Vertex_1 = geompy.MakeVertex(5, 1, 5)
Vertex_1.SetColor(SALOMEDS.Color(1, 0, 0))
geompy.addToStudy(Vertex_1, 'Source' )
Face_0 = geompy.MakeFaceHW(10, 10, 1)
Face_0.SetColor(SALOMEDS.Color(0.666667, 0.333333, 0))
Face_1 = geompy.MakeFaceHW(10, 10, 2)
Face_1.SetColor(SALOMEDS.Color(0.666667, 0.333333, 0))
Face_2 = geompy.MakeFaceHW(10, 10, 3)
Face_2.SetColor(SALOMEDS.Color(0.666667, 0.333333, 0))
geompy.TranslateDXDYDZ(Face_0, 5, 5, 0)
geompy.TranslateDXDYDZ(Face_1, 0, 5, 5)
geompy.TranslateDXDYDZ(Face_2, 5, 0, 5)
geompy.addToStudy(Face_0, 'Wall_0' )
geompy.addToStudy(Face_1, 'Wall_1' )
geompy.addToStudy(Face_2, 'Wall_2' )

geompy.addToStudy( O, 'O' )
geompy.addToStudy( OX, 'OX' )
geompy.addToStudy( OY, 'OY' )
geompy.addToStudy( OZ, 'OZ' )


if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(True)

