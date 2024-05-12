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

Sphere_0 = geompy.MakeSphereR(0.0432891)
geompy.TranslateDXDYDZ(Sphere_0, 0.293202, 8.42971, 1.46199)
Sphere_0.SetColor(SALOMEDS(0, 1, 1))
geompy.addToStudy(Sphere_0, 'Bubble_0' )
Sphere_1 = geompy.MakeSphereR(0.208818)
geompy.TranslateDXDYDZ(Sphere_1, 8.46105, 6.95051, 7.94856)
Sphere_1.SetColor(SALOMEDS(0, 1, 1))
geompy.addToStudy(Sphere_1, 'Bubble_1' )
Sphere_2 = geompy.MakeSphereR(0.688327)
geompy.TranslateDXDYDZ(Sphere_2, 5.1164, 3.25884, 6.23837)
Sphere_2.SetColor(SALOMEDS(0, 1, 1))
geompy.addToStudy(Sphere_2, 'Bubble_2' )
Sphere_3 = geompy.MakeSphereR(0.570754)
geompy.TranslateDXDYDZ(Sphere_3, 5.18502, 4.95782, 4.02377)
Sphere_3.SetColor(SALOMEDS(0, 1, 1))
geompy.addToStudy(Sphere_3, 'Bubble_3' )
Sphere_4 = geompy.MakeSphereR(0.424628)
geompy.TranslateDXDYDZ(Sphere_4, 8.17473, 2.63742, 4.55177)
Sphere_4.SetColor(SALOMEDS(0, 1, 1))
geompy.addToStudy(Sphere_4, 'Bubble_4' )
Vertex_1 = geompy.MakeVertex(5, 1, 5)
Vertex_1.SetColor(SALOMEDS(1, 0, 0))
geompy.addToStudy(Vertex_1, 'Source' )
Face_0 = geompy.MakeFaceHW(10, 10, 1)
Face_0.SetColor(SALOMEDS(0.666667, 0.333333, 0))
Face_1 = geompy.MakeFaceHW(10, 10, 2)
Face_1.SetColor(SALOMEDS(0.666667, 0.333333, 0))
Face_2 = geompy.MakeFaceHW(10, 10, 3)
Face_2.SetColor(SALOMEDS(0.666667, 0.333333, 0))
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

