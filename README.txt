Copyright 2003, 2004, 2008 The Marrowmoon Group

A simple OpenGL apllication using cpp and featuring hierarchical
transformations.

Authors: Markus Klinik and Simon Hengel

Dependencies: libsdl-dev freeglut3-dev

Build and run:
$ make && ./main

key bindings:
<space>      stop animation
<1> .. <7>   switch scene
<ESC>        quit


----------------------------------------------------------------------
Comments from the authors:

This program was written for a cg-course at the University of       
Applied Sciences - Georg-Simon-Ohm Fachhochschule Nuernberg. As we    
think, it may be useful getting started with OpenGL. Feel free to   
use it for any purpose you like (in accordance with the GNU General 
Public License, see COPYING).                                         
                                                                    
The following features may be implemented in the future (as we think
they coul be useful):                                               
                                                                    
- LoadableMesh, a MeshObject, which gets its geometry defenition    
  from a file.                                                      
                                                                    
- Additional materials like metal, plastic, glass, ...               
                                                                    
- Advanced scene-management by the World class.                      
                                                                    
Known Bugs:                                                         
                                                                    
- The hierarchical transformations work not in the right way, if    
  the camera is a sub-object.                                       
                                                                    
If you have implemented one of the above or other useful features or
if you have done a bug fix, please let us know.                     
                                                                    
Bug reports and additional comments are welcome.                    
                                                                    
Contact: markus.klinik@gmx.de or simon.hengel@web.de                

----------------------------------------------------------------------
This program was extended by Simon Hengel in 2004.                  
                                                                    
New features are:                                                   
                                                                    
- A LoadableMesh class                                              
