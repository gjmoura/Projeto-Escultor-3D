#ifndef SCULPTOR_H
#define SCULPTOR_H

/*! \brief Voxel do tipo Struct, é um dado que representa um cubo na matriz.
 *
 *  O Voxel é um cubo representado pelos padrões de cores RGB, esse cubo é encontrado dentro de uma matriz. 
 */
struct Voxel {
  // Colors
  float r; /*!< O dado r do tipo float representa a cor vermelha. */
  float g; /*!< O dado g do tipo float representa a cor verde. */
  float b; /*!< O dado b do tipo float representa a cor azul. */
  float a; /*!< O dado a do tipo float representa a transparência. */
// Transparency
  bool isOn; /*!< O dado isOn do tipo boolean informa se o Voxel é visível ou não. */
};

/*! \brief Sculptor é uma classe que manipula os pixels da matriz tridimensional com seus métodos.
*
*/
class Sculptor {
    protected:
      Voxel ***v;
      // 3D matrix
      int nx; /*!< O dado nx do tipo int representa a dimensão da matriz no eixo x. */
      int ny; /*!< O dado ny do tipo int representa a dimensão da matriz no eixo y. */
      int nz; /*!< O dado nz do tipo int representa a dimensão da matriz no eixo z. */
      float r; /*!< O dado r do tipo float representa a cor vermelha atual que será aplicada ao voxel. */
      float g; /*!< O dado g do tipo float representa a cor verde atual que será aplicada ao voxel. */
      float b; /*!< O dado b do tipo float representa a cor azul atual que será aplicada ao voxel. */
      float a; /*!< O dado a do tipo float representa a transparência atual que será aplicada ao voxel. */
    public:
      Sculptor(int _nx,int _ny,int _nz); 
      ~Sculptor();
      void setColor(float r, float g, float b, float alpha); /*!< Função para adicionar cor ao Voxel. */
      void putVoxel(int x, int y, int z); /*!< Função para ativar o Voxel atual. */
      void cutVoxel(int x, int y, int z); /*!< Função para desativar o Voxel atual. */
      void putBox(int x0, int x1, int y0, int y1, int z0, int z1); /*!< Função para ativar um intervalo de Voxel. */
      void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); /*!< Função para desativar um intervalo de Voxel */
      void putSphere(int xcenter, int ycenter, int zcenter, int radius); /*!< Função para criar uma esfera. */
      void cutSphere(int xcenter, int ycenter, int zcenter, int radius); /*!< Função para cortar uma esfera. */
      void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); /*!< Função para criar uma elipse. */
      void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); /*!< Função para cortar uma elipse. */
      void writeOFF(char* filename); /*!< Função para criar um arquivo com os dados da escultura. */
    };

#endif // SCULPTOR_H
