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

Sphere_0 = geompy.MakeSphereR(1.45926)
geompy.TranslateDXDYDZ(Sphere_0, 7.38614, 6.13901, 4.24186)
geompy.addToStudy( Sphere_0, 'Sphere_0' )
Sphere_1 = geompy.MakeSphereR(0.54009)
geompy.TranslateDXDYDZ(Sphere_1, 9.0731, 4.51936, 3.07709)
geompy.addToStudy( Sphere_1, 'Sphere_1' )
Sphere_2 = geompy.MakeSphereR(0.561382)
geompy.TranslateDXDYDZ(Sphere_2, 2.75359, 5.40311, 8.83383)
geompy.addToStudy( Sphere_2, 'Sphere_2' )
Sphere_3 = geompy.MakeSphereR(0.789532)
geompy.TranslateDXDYDZ(Sphere_3, 4.30023, 3.37099, 5.83599)
geompy.addToStudy( Sphere_3, 'Sphere_3' )

geompy.addToStudy( O, 'O' )
geompy.addToStudy( OX, 'OX' )
geompy.addToStudy( OY, 'OY' )
geompy.addToStudy( OZ, 'OZ' )


if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(True)

