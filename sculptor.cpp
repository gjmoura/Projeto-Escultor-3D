#include "sculptor.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //Define a dimensão da escultura

    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    for(int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
            for(int k=0; k< nz; k++) {
                v[i][j][k].isOn = false;
            }

        }
    }




}


Sculptor::~Sculptor() {

    for(int i = 0; i < nx; i++) {

        for(int j = 0; j < ny; j++) {
           delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float red, float green, float blue, float alpha) {
    //Define as cores do voxel atual
    r = red;
    g = green;
    b = blue;
    a = alpha;

}
void Sculptor::putVoxel(int x, int y, int z) {
    //Ativa o voxel atual e altera suas cor
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}
void Sculptor::cutVoxel(int x, int y, int z) {
    //Desativa o Voxel atual
    v[x][y][z].isOn = false;
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    //Usar um for para percorrer a matriz 3D, ativando os Voxels e atribuindo as propriedades em cada voxel
    for(int vetorX = x0; vetorX < x1; vetorX++) {
        for( int vetorY = y0; vetorY < y1; vetorY++) {
            for( int vetorZ = z0; vetorZ < z1; vetorZ++) {
                v[vetorX][vetorY][vetorZ].isOn = true;
                v[vetorX][vetorY][vetorZ].r = r;
                v[vetorX][vetorY][vetorZ].g = g;
                v[vetorX][vetorY][vetorZ].b = b;
                v[vetorX][vetorY][vetorZ].a = a;

            }
        }
    }

}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    //Usar um for para percorrer a matriz 3D e ir desativando os Voxels
    for(int vetorX = x0; vetorX < x1; vetorX++) {
        for( int vetorY = y0; vetorY < y1; vetorY++) {
            for( int vetorZ = z0; vetorZ < z1; vetorZ++) {
                v[vetorX][vetorY][vetorZ].isOn = false;
            }
        }
    }

}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {

    // Válida a posição do voxel pela equação da esfera ativando-o
    for(int vetorX = 0; vetorX < nx; vetorX++) {
        for( int vetorY = 0; vetorY < ny; vetorY++) {
            for( int vetorZ = 0; vetorZ < nz; vetorZ++) {

               int value = (vetorX - xcenter)*(vetorX - xcenter) + (vetorY - ycenter)*(vetorY - ycenter) + (vetorZ - zcenter)*(vetorZ - zcenter);
                if( value <= (radius)*(radius) ) {
                    v[vetorX][vetorY][vetorZ].isOn = true;
                    v[vetorX][vetorY][vetorZ].r = r;
                    v[vetorX][vetorY][vetorZ].g = g;
                    v[vetorX][vetorY][vetorZ].b = b;
                    v[vetorX][vetorY][vetorZ].a = a;

                }

            }
        }
    }

}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {

    // Válida a posição do voxel pela equação da esfera, desativando-o
    for(int vetorX = 0; vetorX < nx; vetorX++) {
        for( int vetorY = 0; vetorY < ny; vetorY++) {
            for( int vetorZ = 0; vetorZ < nz; vetorZ++) {

               int value = (vetorX - xcenter)*(vetorX - xcenter) + (vetorY - ycenter)*(vetorY - ycenter) + (vetorZ - zcenter)*(vetorZ - zcenter);
                if( value <= (radius)*(radius) ) {
                    v[vetorX][vetorY][vetorZ].isOn = false;

                }

            }
        }
    }

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    // Válida a posição do voxel pela equação da elipsóide ativando-o
    for(int vetorX = 0; vetorX < nx; vetorX++) {
        for( int vetorY = 0; vetorY < ny; vetorY++) {
            for( int vetorZ = 0; vetorZ < nz; vetorZ++) {

                int value = ((vetorX - xcenter)*(vetorX - xcenter))/(rx*rx) + ((vetorY - ycenter)*(vetorY - ycenter))/(ry*ry) + ((vetorZ - zcenter)*(vetorZ - zcenter))/(rz*rz);
                if( value <= 1 ) {
                    v[vetorX][vetorY][vetorZ].isOn = true;
                    v[vetorX][vetorY][vetorZ].r = r;
                    v[vetorX][vetorY][vetorZ].g = g;
                    v[vetorX][vetorY][vetorZ].b = b;
                    v[vetorX][vetorY][vetorZ].a = a;

                }

            }
        }
    }

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    // Válida a posição do voxel pela equação da elipsóide, desativando-o
    for(int vetorX = 0; vetorX < nx; vetorX++) {
        for( int vetorY = 0; vetorY < ny; vetorY++) {
            for( int vetorZ = 0; vetorZ < nz; vetorZ++) {

                int value = ((vetorX - xcenter)*(vetorX - xcenter))/(rx*rx) + ((vetorY - ycenter)*(vetorY - ycenter))/(ry*ry) + ((vetorZ - zcenter)*(vetorZ - zcenter))/(rz*rz);
                if( value <= 1 ) {
                    v[vetorX][vetorY][vetorZ].isOn = false;
                }
            }
        }
    }
}
void Sculptor::writeOFF(char* filename) {



    int nVoxels, nFaces = 0;
    ofstream fout;
    fout.open(filename);
    if(fout.is_open()) {
        cout << "Aquivo aberto" << endl;
    }
    fout<<"OFF"<<endl;
    for(int i = 0; i<nx; i++){
         for(int j = 0; j<ny; j++){
             for(int k = 0; k<nz; k++){
                 if(v[i][j][k].isOn){
                   nVoxels++;
                }
            }
        }
      }
    fout  << nVoxels*8 << " " << nVoxels*6 << " " << 0 << endl;

    for(int i = 0; i<nx; i++){
         for(int j = 0; j<ny; j++){
             for(int k = 0; k<nz; k++){
                 if(v[i][j][k].isOn){

                   fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                   fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                   fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                   fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                   fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                   fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                   fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                   fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;

                }
            }
        }
      }

    for(int i = 0; i<nx; i++){
         for(int j = 0; j<ny; j++){
             for(int k = 0; k<nz; k++){
                 if(v[i][j][k].isOn){
                     fout << 4 << " " << 0+(nFaces*8) << " " << 3+(nFaces*8) << " " << 2+(nFaces*8) << " " << 1+(nFaces*8) << " " << v[i][j][k].r  << " " << v[i][j][k].g << " "  << v[i][j][k].b  << " " << v[i][j][k].a << endl;
                     fout << 4 << " " << 4+(nFaces*8) << " " << 5+(nFaces*8) << " " << 6+(nFaces*8) << " " << 7+(nFaces*8) << " " << v[i][j][k].r  << " " << v[i][j][k].g  << " " << v[i][j][k].b  << " " << v[i][j][k].a << endl;
                     fout << 4 << " " << 0+(nFaces*8) << " " << 1+(nFaces*8) << " " << 5+(nFaces*8) << " " << 4+(nFaces*8) << " " << v[i][j][k].r  << " " << v[i][j][k].g  << " " << v[i][j][k].b  << " " << v[i][j][k].a << endl;
                     fout << 4 << " " << 0+(nFaces*8) << " " << 4+(nFaces*8) << " " << 7+(nFaces*8) << " " << 3+(nFaces*8) << " " << v[i][j][k].r  << " " << v[i][j][k].g  << " " << v[i][j][k].b  << " " << v[i][j][k].a << endl;
                     fout << 4 << " " << 3+(nFaces*8) << " " << 7+(nFaces*8) << " " << 6+(nFaces*8) << " " << 2+(nFaces*8) << " " << v[i][j][k].r  << " " << v[i][j][k].g  << " " << v[i][j][k].b  << " " << v[i][j][k].a << endl;
                     fout << 4 << " " << 1+(nFaces*8) << " " << 2+(nFaces*8) << " " << 6+(nFaces*8) << " " << 5+(nFaces*8) << " " << v[i][j][k].r  << " " << v[i][j][k].g  << " " << v[i][j][k].b  << " " << v[i][j][k].a << endl;
                     nFaces++;
                }
            }
        }
      }

    fout.close();
    cout << "Arquivo salvo" << endl;

}
