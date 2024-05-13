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

Sphere_0 = geompy.MakeSphereR(0.127635)
geompy.TranslateDXDYDZ(Sphere_0, 8.17326, 5.5859, 2.03157)
Sphere_0.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_0, 'Bubble_0' )
Sphere_1 = geompy.MakeSphereR(0.709963)
geompy.TranslateDXDYDZ(Sphere_1, 5.40268, 5.93441, 5.6701)
Sphere_1.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_1, 'Bubble_1' )
Sphere_2 = geompy.MakeSphereR(0.159438)
geompy.TranslateDXDYDZ(Sphere_2, 7.90894, 5.54246, 3.17772)
Sphere_2.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_2, 'Bubble_2' )
Sphere_3 = geompy.MakeSphereR(0.00893617)
geompy.TranslateDXDYDZ(Sphere_3, 2.34265, 1.03309, 9.00022)
Sphere_3.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_3, 'Bubble_3' )
Sphere_4 = geompy.MakeSphereR(0.00144884)
geompy.TranslateDXDYDZ(Sphere_4, 1.33595, 4.36394, 4.83963)
Sphere_4.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_4, 'Bubble_4' )
Sphere_5 = geompy.MakeSphereR(0.461003)
geompy.TranslateDXDYDZ(Sphere_5, 2.82648, 1.90667, 1.19636)
Sphere_5.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_5, 'Bubble_5' )
Sphere_6 = geompy.MakeSphereR(0.0375311)
geompy.TranslateDXDYDZ(Sphere_6, 2.55256, 2.19643, 5.12881)
Sphere_6.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_6, 'Bubble_6' )
Sphere_7 = geompy.MakeSphereR(0.169857)
geompy.TranslateDXDYDZ(Sphere_7, 3.09301, 5.76646, 3.94666)
Sphere_7.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_7, 'Bubble_7' )
Sphere_8 = geompy.MakeSphereR(0.18527)
geompy.TranslateDXDYDZ(Sphere_8, 2.30061, 1.76517, 3.97757)
Sphere_8.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_8, 'Bubble_8' )
Sphere_9 = geompy.MakeSphereR(0.304518)
geompy.TranslateDXDYDZ(Sphere_9, 5.78207, 5.56062, 3.75996)
Sphere_9.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_9, 'Bubble_9' )
Sphere_10 = geompy.MakeSphereR(0.286392)
geompy.TranslateDXDYDZ(Sphere_10, 4.27141, 2.28906, 6.09375)
Sphere_10.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_10, 'Bubble_10' )
Sphere_11 = geompy.MakeSphereR(0.207588)
geompy.TranslateDXDYDZ(Sphere_11, 5.59071, 1.45857, 5.4904)
Sphere_11.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_11, 'Bubble_11' )
Sphere_12 = geompy.MakeSphereR(0.128318)
geompy.TranslateDXDYDZ(Sphere_12, 4.74409, 1.76484, 6.01556)
Sphere_12.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_12, 'Bubble_12' )
Sphere_13 = geompy.MakeSphereR(0.0110013)
geompy.TranslateDXDYDZ(Sphere_13, 5.04571, 1.15263, 4.85295)
Sphere_13.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_13, 'Bubble_13' )
Sphere_14 = geompy.MakeSphereR(0.19172)
geompy.TranslateDXDYDZ(Sphere_14, 5, 1, 5)
Sphere_14.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_14, 'Bubble_14' )
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

