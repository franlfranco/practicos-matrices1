//Guia trabajos practicos matrices
/*1. Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por completo.
2. Hacer una función que reciba como parámetro una matriz de números enteros y la muestre por pantalla (en formato matricial).
3. Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios (sin intervención del usuario). La función debe cargar la matriz por completo.
4. Hacer una función tipo int que sume el contenido total de una matriz de números enteros.
5. Hacer una función tipo int que calcule el promedio de una matriz de números enteros.
6. Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros. La función recibe la matriz y el dato a buscar.
7. Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.
8. Hacer una función que muestre un arreglo de palabras.
9. Hacer una función que determine si una palabra se encuentra dentro de un arreglo de palabras. La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
10. Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por selección o inserción, el que más te guste)
11. Hacer una función que retorne el determinante de una matriz de 2x2.
12. Función que verifique si una matriz de 2x2 tiene inversa.
13. Hacer una función que multiplique una matriz de 2x2 por una matriz de 2x10.
14. Hacer una función que calcule la matriz inversa de una matriz de 2x2.
15. Los resultados de las últimas elecciones a Intendente en el pueblo “La Matrix” han sido los siguientes:
Escribir un programa que haga las siguientes tareas:
a. Imprimir la tabla anterior con cabeceras incluidas.
b. Calcular e imprimir el número total de votos recibidos por cada candidato y el porcentaje
total de votos emitidos. Así mismo, visualizar el candidato más votado.
c. Si algún candidato recibe más del 50% de los votos, el programa imprimirá un mensaje
declarándose ganador.
d. Si algún candidato recibe menos del 50% de los votos, el programa debe imprimir el
nombre de los dos candidatos más votados que serán los que pasen a la segunda ronda de las elecciones.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

const int maxC=5;//Cantidad de columnas en matriz de enteros
const int maxDim=100;//Maxima dimension de string
const int maxCol=100;//Maxima cantidad de columnas en matriz que almacena palabras
const int maxP=10;//Maximo de palabras que puede almacenar la matriz que almacena palabras

//Funcion ejercicio 1 cargar matriz hecha en clase
int cargarMatrizManual(int mat[][maxC], int dimF){
  char control = 's';
  int i = 0;
  while(control == 's'&&i<dimF){
    for(int j=0;j<maxC;j++){
      printf("Ingrese un valor para F%i,C%i: ",i,j);
      fflush(stdin);
      scanf("%i",&mat[i][j]);
    }
    i++;
    printf("Desea ingresar otra fila? s/n\n");
    fflush(stdin);
    scanf(" %c",&control);
  }
  return i;
}

//Funcion del ejercicio 2
void mostrarMatriz(int mat[][maxC], int valF){
  printf("\n");
  for (int i=0;i<valF;i++){
    for(int j=0;j<maxC;j++){
      printf("|%i| ",mat[i][j]);
    }
    printf("\n");
  }
}

//Funcion del ejercicio 3
int cargarMatrizAleatorio(int mat[][maxC], int dimF){
  char control = 's';
  int i = 0;

  while(control == 's'&&i<dimF){
    for(int j=0;j<maxC;j++){
      mat[i][j] = rand()%10;
    }
    i++;
    printf("Se cargó %i fila/s\n",i );
    printf("Desea ingresar otra fila? s/n\n");
    fflush(stdin);
    scanf(" %c",&control);
  }
  return i;
}

//Funcion del ejercicio 4
int sumarMatriz(int mat[][maxC],int valF){
  int suma = 0;
  for(int i=0;i<valF;i++){
    for(int j=0;j<maxC;j++){
      suma = suma + mat[i][j];
    }
  }
  return suma;
}

//Funciones del ejercicio 5
int contarMatriz(int mat[][maxC],int valF){
  int cont = 0;
  for(int i=0;i<valF;i++){
    for(int j=0;j<maxC;j++){
      cont++;
    }
  }
  return cont;
}

float promedioMatriz(int mat[][maxC], int valF){
  float prom = 0;
  if(contarMatriz(mat,valF)>0){
    prom = sumarMatriz(mat,valF)/(float)contarMatriz(mat,valF);
  }
  return prom;
}

//Funcion del ejercicio 6
bool buscar(mat[][maxC], int valF, int dato){
  bool flag = 0;
  int i = 0;
  int j = 0;
  while(i<valF&&!flag){
    j=0;
    while(j<maxC&&!flag){
      if(dato == mat[i][j]){
        flag = 1;
      }
      j++;
    }
    i++;
  }
  return flag;
}

//Funcion del ejercicio 7
int cargarString(char string[maxDim]){
  char control = 's';
  char aux[maxDim] = "";
  int i =0;
  while(control == 's'&&strlen(string)<maxDim){
    printf("Ingrese una palabra\n" );
    fflush(stdin);
    scanf(" %s",aux);
    strcat(string,aux);
    printf("Desea cargar otra palabra? s/n\n" );
    fflush(stdin);
    scanf(" %c",&control);
    if(control == 's'){
      strcat(string," ");
    }
    i++;
  }
  return i;
}

//Funcion del ejercicio 8
void mostrarString(char string[]){
  printf("\n%s\n", string);
}

//Funcion del ejercicio 9
bool buscarString(char s[],char t[]){
  bool flag =0;
  if(strstr(s,t)){
    flag=1;
  }
  return flag;
}

//Funcion del ejercicio 10
void stringToMatriz(char string[],char matriz[][maxCol], int cant){//Esta funcion pasa las palabras de un string a una matriz de palabras
  int i=0;
  for(int j=0;j<cant;j++){
    i = 0;
    while(string[i]>='a'){
      matriz[j][i] = string[i];
      i++;
    }
  }
}

void mostrarMatrizStr(char matrizS[][maxCol],int cant){
  for(int i=0;i<cant;i++){
    printf("\n%s\n",matrizS[i]);
  }
}

int main() {
  int matriz[10][maxC];
  int valF;
  srand(time(0));
  char string[maxDim] = "";
  int valS;
  char matrizS[maxP][maxCol];

  //Matrices
  /*
  valF = cargarMatrizAleatorio(matriz,10);
  mostrarMatriz(matriz, valF);
  printf("\nTodos los elementos de la matriz suman: %i\n",sumarMatriz(matriz,valF));
  printf("\nEl promedio de los elementos en la matriz es: %.2f\n", promedioMatriz(matriz,valF));
  if(buscar(matriz,valF,8)){
    printf("\nEl elemento está en la matriz\n");
  }else{
    printf("\nEl elemento NO está en la matriz\n");
  }
  */

  //Strings

  valS = cargarString(string);
  mostrarString(string);
  if(buscarString(string,"hola")){
    printf("\nLa palabra esta en el string\n");
  }else{
    printf("\nLa palabra NO esta en el string\n");
  }
  stringToMatriz(string,matrizS,valS);
  mostrarMatrizStr(matrizS,valS);
  return 0;
}
