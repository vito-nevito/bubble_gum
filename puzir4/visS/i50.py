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

Sphere_0 = geompy.MakeSphereR(0.548302)
geompy.TranslateDXDYDZ(Sphere_0, 5.74754, 4.71186, 3.95941)
Sphere_0.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_0, 'Bubble_0' )
Sphere_1 = geompy.MakeSphereR(0.158323)
geompy.TranslateDXDYDZ(Sphere_1, 1.00617, 3.18541, 5.55635)
Sphere_1.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_1, 'Bubble_1' )
Sphere_2 = geompy.MakeSphereR(0.0832089)
geompy.TranslateDXDYDZ(Sphere_2, 3.66439, 9.00256, 1.73602)
Sphere_2.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_2, 'Bubble_2' )
Sphere_3 = geompy.MakeSphereR(0.0418201)
geompy.TranslateDXDYDZ(Sphere_3, 5.08893, 1.97551, 4.79686)
Sphere_3.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_3, 'Bubble_3' )
Sphere_4 = geompy.MakeSphereR(0.29113)
geompy.TranslateDXDYDZ(Sphere_4, 5.08754, 1.28137, 4.27567)
Sphere_4.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_4, 'Bubble_4' )
Sphere_5 = geompy.MakeSphereR(1.10249)
geompy.TranslateDXDYDZ(Sphere_5, 5.66494, 2.35492, 6.07282)
Sphere_5.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_5, 'Bubble_5' )
Sphere_6 = geompy.MakeSphereR(0.226642)
geompy.TranslateDXDYDZ(Sphere_6, 4.94358, 1.31995, 5.2462)
Sphere_6.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_6, 'Bubble_6' )
Sphere_7 = geompy.MakeSphereR(0.289805)
geompy.TranslateDXDYDZ(Sphere_7, 5, 1, 5)
Sphere_7.SetColor(SALOMEDS.Color(0, 1, 1))
geompy.addToStudy(Sphere_7, 'Bubble_7' )
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

