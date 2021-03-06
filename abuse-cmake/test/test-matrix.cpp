#include "catch.hpp"
#include "../src/lol/matrix.h"

using namespace lol;

TEST_CASE("BIDON")
{
    int i = 5;
    REQUIRE( i == 5);
    REQUIRE( 0 == 0);
}
TEST_CASE("BIDON 2")
{
    int c = 3;
    REQUIRE(c == 3);
}
TEST_CASE("Vecteur2 -operations de base vectorielle")
{
    vec2i vecteur1(3);
    vec2i vecteur2(4,5);
    vec3i vecteur3(10,11,12);      //Necessaire pour tester le cast en 2D

    int scalaire = 2;

    vec2i add = vecteur1 + vecteur2;
    vec2i sub = vecteur1 - vecteur2;
    vec2i prod = vecteur1 * vecteur2;
    vec2i div = vecteur1 / vecteur2;
    
    vec2i scalaireAdd = scalaire + vecteur2;
    vec2i scalaireSub  = scalaire - vecteur2;
    vec2i scalaireProd  = scalaire * vecteur2;
    vec2i scalaireDiv  = scalaire / vecteur2;
    vec2i addScalaire = vecteur2 + scalaire;
    vec2i subScalaire  = vecteur2 - scalaire;
    vec2i prodScalaire  = vecteur2 * scalaire;
    vec2i divScalaire  = vecteur2 / scalaire;

    vec2i cast2D = (vec2i)vecteur3;
    vec4i cast4D = (vec4i)vecteur3;

// TEST VECTOR_OP

    //Addition de 2 Vecteurs 2D 
    REQUIRE(add.x == (3+4));
    REQUIRE(add.y == (3+5));
    
    //Soustraction de 2 Vecteurs 2D 
    REQUIRE(sub.x == (3-4));
    REQUIRE(sub.y == (3-5));

    //Soustraction de 2 Vecteurs 2D
    REQUIRE(prod.x == (3*4));
    REQUIRE(prod.y == (3*5));
    
    //Division de 2 Vecteurs 2D
    REQUIRE(div.x == (3/4));
    REQUIRE(div.y == (3/5));

// TEST BOOL_OP

    //Egalite
    REQUIRE((vecteur1 == vecteur1) == true);
    REQUIRE((vecteur1 == vecteur2) == false);

    //Different
    REQUIRE((vecteur1 != vecteur2) == true);
    REQUIRE((vecteur1 != vecteur1) == false);

    //Inferieure ou egale
    REQUIRE((vecteur1 <= vecteur1) == true);
    REQUIRE((vecteur1 <= vecteur2) == true);
    REQUIRE((vecteur2 <= vecteur1) == false);

    //Inferieure strictement
    REQUIRE((vecteur1 < vecteur1) == false);
    REQUIRE((vecteur1 < vecteur2) == true);
    REQUIRE((vecteur2 < vecteur1) == false);

    //Superieur ou egale
    REQUIRE((vecteur1 >= vecteur1) == true);
    REQUIRE((vecteur1 >= vecteur2) == false);
    REQUIRE((vecteur2 >= vecteur1) == true);

    //Superieure strictement
    REQUIRE((vecteur1 > vecteur1) == false);
    REQUIRE((vecteur1 > vecteur2) == false);
    REQUIRE((vecteur2 > vecteur1) == true);

// TEST SCALAR_OP

    //Addition Scalaire + Vecteur 2D
    REQUIRE(scalaireAdd.x == (2+4));
    REQUIRE(scalaireAdd.y == (2+5));

    //Soustraction de Scalaire + Vecteur 2D
    REQUIRE(scalaireSub.x == (2-4));
    REQUIRE(scalaireSub.y == (2-5));

    //Produit de Scalaire * Vecteur 2D
    REQUIRE(scalaireProd.x == (2*4));
    REQUIRE(scalaireProd.y == (2*5));

    //Division de Scalaire * Vecteur 2D
    REQUIRE(scalaireDiv.x == (2/4));
    REQUIRE(scalaireDiv.y == (2/5));
    
    //Addition Vecteur 2D + Scalaire
    REQUIRE(addScalaire.x == (4+2));
    REQUIRE(addScalaire.y == (5+2));

    //Soustraction Vecteur 2D - Scalaire
    REQUIRE(subScalaire.x == (4-2));
    REQUIRE(subScalaire.y == (5-2));

    //Produit de Vecteur 2D * Scalaire
    REQUIRE(prodScalaire.x == (4*2));
    REQUIRE(prodScalaire.y == (5*2));

    //Division de Vecteur 2D / Scalaire
    REQUIRE(divScalaire.x == (4/2));
    REQUIRE(divScalaire.y == (5/2));

// TEST CAST_OP

    //TEST sur contenu
    REQUIRE(cast2D.x == 10);
    REQUIRE(cast2D.y == 11);

    /*REQUIRE(cast4D.x == 10);
    REQUIRE(cast4D.y == 11);
    REQUIRE(cast4D.z == 12);
    REQUIRE(cast4D.w == 2);??????????????????????????????????????????????????????????????????????????????????????*/

    //TEST sur racine valeur de sqlen (somme des carré des coordonnées du vecteur)
    REQUIRE(cast2D.sqlen() == (10*10+11*11));

    //TEST sur racine de lenql
    REQUIRE(cast2D.len() == (float)(sqrt(10*10+11*11))); 

    //TEST sur taille
    REQUIRE(cast2D == vecteur3);     // Cast auto
}

TEST_CASE("Vecteur3 -operations de base vectorielle")
{
    vec3i vecteur1(3);
    vec3i vecteur2(4,5,6);
    vec4i vecteur3(10,11,12,13);
    int scalaire = 2;

    vec3i add = vecteur1 + vecteur2;
    vec3i sub = vecteur1 - vecteur2;
    vec3i prod = vecteur1 * vecteur2;
    vec3i div = vecteur1 / vecteur2;
    
    vec3i scalaireAdd = scalaire + vecteur2;
    vec3i scalaireSub  = scalaire - vecteur2;
    vec3i scalaireProd  = scalaire * vecteur2;
    vec3i scalaireDiv  = scalaire / vecteur2;
    vec3i addScalaire = vecteur2 + scalaire;
    vec3i subScalaire  = vecteur2 - scalaire;
    vec3i prodScalaire  = vecteur2 * scalaire;
    vec3i divScalaire  = vecteur2 / scalaire;

    vec3i cast3D = (vec3i)vecteur3;
    vec2i cast2D = (vec2i)vecteur3;

// TEST VECTOR_OP

    //Addition de 2 Vecteurs 3D 
    REQUIRE(add.x == (3+4));
    REQUIRE(add.y == (3+5));
    REQUIRE(add.z == (3+6));
    
    //Soustraction de 2 Vecteurs 3D 
    REQUIRE(sub.x == (3-4));
    REQUIRE(sub.y == (3-5));
    REQUIRE(sub.z == (3-6));

    //Soustraction de 2 Vecteurs 3D
    REQUIRE(prod.x == (3*4));
    REQUIRE(prod.y == (3*5));
    REQUIRE(prod.z == (3*6));

    //Division de 2 Vecteurs 3D
    REQUIRE(div.x == (3/4));
    REQUIRE(div.y == (3/5));
    REQUIRE(div.z == (3/6));

// TEST BOOL_OP

    //Egalite
    REQUIRE((vecteur1 == vecteur1) == true);
    REQUIRE((vecteur1 == vecteur2) == false);

    //Different
    REQUIRE((vecteur1 != vecteur2) == true);
    REQUIRE((vecteur1 != vecteur1) == false);

    //Inferieure ou egale
    REQUIRE((vecteur1 <= vecteur1) == true);
    REQUIRE((vecteur1 <= vecteur2) == true);
    REQUIRE((vecteur2 <= vecteur1) == false);

    //Inferieure strictement
    REQUIRE((vecteur1 < vecteur1) == false);
    REQUIRE((vecteur1 < vecteur2) == true);
    REQUIRE((vecteur2 < vecteur1) == false);

    //Superieur ou egale
    REQUIRE((vecteur1 >= vecteur1) == true);
    REQUIRE((vecteur1 >= vecteur2) == false);
    REQUIRE((vecteur2 >= vecteur1) == true);

    //Superieure strictement
    REQUIRE((vecteur1 > vecteur1) == false);
    REQUIRE((vecteur1 > vecteur2) == false);
    REQUIRE((vecteur2 > vecteur1) == true);

// TEST SCALAR_OP

    //Addition Scalaire + Vecteur 3D
    REQUIRE(scalaireAdd.x == (2+4));
    REQUIRE(scalaireAdd.y == (2+5));
    REQUIRE(scalaireAdd.z == (2+6));

    //Soustraction de Scalaire + Vecteur 3D
    REQUIRE(scalaireSub.x == (2-4));
    REQUIRE(scalaireSub.y == (2-5));
    REQUIRE(scalaireSub.z == (2-6));

    //Produit de Scalaire * Vecteur 3D
    REQUIRE(scalaireProd.x == (2*4));
    REQUIRE(scalaireProd.y == (2*5));
    REQUIRE(scalaireProd.z == (2*6));

    //Division de Scalaire * Vecteur 3D
    REQUIRE(scalaireDiv.x == (2/4));
    REQUIRE(scalaireDiv.y == (2/5));
    REQUIRE(scalaireDiv.z == (2/6));
    
    //Addition Vecteur 3D + Scalaire
    REQUIRE(addScalaire.x == (4+2));
    REQUIRE(addScalaire.y == (5+2));
    REQUIRE(addScalaire.z == (6+2));

    //Soustraction Vecteur 3D - Scalaire
    REQUIRE(subScalaire.x == (4-2));
    REQUIRE(subScalaire.y == (5-2));
    REQUIRE(subScalaire.z == (6-2));

    //Produit de Vecteur 3D * Scalaire
    REQUIRE(prodScalaire.x == (4*2));
    REQUIRE(prodScalaire.y == (5*2));
    REQUIRE(prodScalaire.z == (6*2));

    //Division de Vecteur 3D / Scalaire
    REQUIRE(divScalaire.x == (4/2));
    REQUIRE(divScalaire.y == (5/2));
    REQUIRE(divScalaire.z == (6/2));

// TEST CAST_OP

    //TEST sur contenu
    REQUIRE(cast3D.x == 10);
    REQUIRE(cast3D.y == 11);
    REQUIRE(cast3D.z == 12);

    REQUIRE(cast2D.x == 10);
    REQUIRE(cast2D.y == 11);

    //TEST sur racine valeur de sqlen (somme des carré des coordonnées du vecteur)
    REQUIRE(cast3D.sqlen() == (10*10+11*11+12*12));

    //TEST sur racine de lenql
    REQUIRE(cast3D.len() == (float)sqrt(10*10+11*11+12*12));     

    //TEST sur taille
    REQUIRE(cast3D == vecteur3);     // Cast auto
}
TEST_CASE("Vecteur4 -operations de base vectorielle")
{
    vec4i vecteur1(3);
    vec4i vecteur2(4,5,6,7);
    //vector<int> vecteur3(5,10,11,12,13,14);
    int scalaire = 2;

    vec4i add = vecteur1 + vecteur2;
    vec4i sub = vecteur1 - vecteur2;
    vec4i prod = vecteur1 * vecteur2;
    vec4i div = vecteur1 / vecteur2;
    
    vec4i scalaireAdd = scalaire + vecteur2;
    vec4i scalaireSub  = scalaire - vecteur2;
    vec4i scalaireProd  = scalaire * vecteur2;
    vec4i scalaireDiv  = scalaire / vecteur2;
    vec4i addScalaire = vecteur2 + scalaire;
    vec4i subScalaire  = vecteur2 - scalaire;
    vec4i prodScalaire  = vecteur2 * scalaire;
    vec4i divScalaire  = vecteur2 / scalaire;

    //vec4i cast4D = (vec4i)vecteur3;

// TEST VECTOR_OP

    //Addition de 2 Vecteurs 4D 
    REQUIRE(add.x == (3+4));
    REQUIRE(add.y == (3+5));
    REQUIRE(add.z == (3+6));
    REQUIRE(add.w == (3+7));
    
    //Soustraction de 2 Vecteurs 4D 
    REQUIRE(sub.x == (3-4));
    REQUIRE(sub.y == (3-5));
    REQUIRE(sub.z == (3-6));
    REQUIRE(sub.w == (3-7));

    //Soustraction de 2 Vecteurs 4D
    REQUIRE(prod.x == (3*4));
    REQUIRE(prod.y == (3*5));
    REQUIRE(prod.z == (3*6));
    REQUIRE(prod.w == (3*7));

    //Division de 2 Vecteurs 4D
    REQUIRE(div.x == (3/4));
    REQUIRE(div.y == (3/5));
    REQUIRE(div.z == (3/6));
    REQUIRE(div.w == (3/7));

// TEST BOOL_OP

    //Egalite
    REQUIRE((vecteur1 == vecteur1) == true);
    REQUIRE((vecteur1 == vecteur2) == false);

    //Different
    REQUIRE((vecteur1 != vecteur2) == true);
    REQUIRE((vecteur1 != vecteur1) == false);

    //Inferieure ou egale
    REQUIRE((vecteur1 <= vecteur1) == true);
    REQUIRE((vecteur1 <= vecteur2) == true);
    REQUIRE((vecteur2 <= vecteur1) == false);

    //Inferieure strictement
    REQUIRE((vecteur1 < vecteur1) == false);
    REQUIRE((vecteur1 < vecteur2) == true);
    REQUIRE((vecteur2 < vecteur1) == false);

    //Superieur ou egale
    REQUIRE((vecteur1 >= vecteur1) == true);
    REQUIRE((vecteur1 >= vecteur2) == false);
    REQUIRE((vecteur2 >= vecteur1) == true);

    //Superieure strictement
    REQUIRE((vecteur1 > vecteur1) == false);
    REQUIRE((vecteur1 > vecteur2) == false);
    REQUIRE((vecteur2 > vecteur1) == true);

// TEST SCALAR_OP

    //Addition Scalaire + Vecteur 4D
    REQUIRE(scalaireAdd.x == (2+4));
    REQUIRE(scalaireAdd.y == (2+5));
    REQUIRE(scalaireAdd.z == (2+6));
    REQUIRE(scalaireAdd.w == (2+7));

    //Soustraction de Scalaire + Vecteur 4D
    REQUIRE(scalaireSub.x == (2-4));
    REQUIRE(scalaireSub.y == (2-5));
    REQUIRE(scalaireSub.z == (2-6));
    REQUIRE(scalaireSub.w == (2-7));

    //Produit de Scalaire * Vecteur 4D
    REQUIRE(scalaireProd.x == (2*4));
    REQUIRE(scalaireProd.y == (2*5));
    REQUIRE(scalaireProd.z == (2*6));
    REQUIRE(scalaireProd.w == (2*7));

    //Division de Scalaire * Vecteur 4D
    REQUIRE(scalaireDiv.x == (2/4));
    REQUIRE(scalaireDiv.y == (2/5));
    REQUIRE(scalaireDiv.z == (2/6));
    REQUIRE(scalaireDiv.w == (2/7));

    //Addition Vecteur 4D + Scalaire
    REQUIRE(addScalaire.x == (4+2));
    REQUIRE(addScalaire.y == (5+2));
    REQUIRE(addScalaire.z == (6+2));
    REQUIRE(addScalaire.w == (7+2));

    //Soustraction Vecteur 4D - Scalaire
    REQUIRE(subScalaire.x == (4-2));
    REQUIRE(subScalaire.y == (5-2));
    REQUIRE(subScalaire.z == (6-2));
    REQUIRE(subScalaire.w == (7-2));

    //Produit de Vecteur 4D * Scalaire
    REQUIRE(prodScalaire.x == (4*2));
    REQUIRE(prodScalaire.y == (5*2));
    REQUIRE(prodScalaire.z == (6*2));
    REQUIRE(prodScalaire.w == (7*2));

    //Division de Vecteur 4D / Scalaire
    REQUIRE(divScalaire.x == (4/2));
    REQUIRE(divScalaire.y == (5/2));
    REQUIRE(divScalaire.z == (6/2));
    REQUIRE(divScalaire.w == (7/2));

// TEST CAST_OP

    //TEST sur contenu
    /*REQUIRE(cast4D.x == 10);
    REQUIRE(cast4D.y == 11);
    REQUIRE(cast4D.z == 12);
    REQUIRE(cast4D.w == 13);*/

    //TEST sur racine valeur de sqlen (somme des carré des coordonnées du vecteur)
    //REQUIRE(cast4D.sqlen() == 534);

    //TEST sur racine de lenql
    //REQUIRE(cast4D.len() == 23.10844f);     // A Tester

    //TEST sur taille
    //REQUIRE(cast4D.size() == 4;     // A Tester
}

TEST_CASE("MATRICE4 Operator")
{
    Mat4<int> matrice1();
    Mat4<int> matrice2(2);
    vec4i vecteur5(4,4,4,4);
    Mat4<int> matrice3(vecteur5,vecteur5,vecteur5,vecteur5);
    vec4i vecteur1(3);
    vec4i vecteur2(4,5,6,7);
    vec4i vecteur3(3);
    vec4i vecteur4(4,5,6,7);
    
    Mat4<int> matriceOp(vecteur1,vecteur2,vecteur3,vecteur4);
    REQUIRE(matriceOp[0] == vecteur1);
    REQUIRE(matrice3[0][0] == 4);
    REQUIRE(matrice3[0] == matrice3.v[0]);
    REQUIRE((matrice3+matriceOp)[0][0] == 7);
    REQUIRE((matrice3-matriceOp)[0][0] == 1);
    Mat4<int> test = matrice3*matriceOp;
    REQUIRE(test.v[0][0] == 48);

    REQUIRE((matrice3 *= matriceOp)[0][0] == 48 );
    REQUIRE((matrice3 += matriceOp)[0][0] == 51);
    REQUIRE((matrice3 -= matriceOp)[1][1] == 88); 
}

TEST_CASE("FUNCTION MATRICE 4")
{
    vec4i vecteur1(3,3,-5,3);
    vec4i vecteur2(4,5,6,7);
    vec4i vecteur3(3,8,-8,3);
    vec4i vecteur4(4,7,6,7);
    mat4 matrice1(vecteur1,vecteur2,vecteur3,vecteur4);
    REQUIRE(matrice1.det() == 54);
    REQUIRE((matrice1.invert())[0][0] == 74.0f/27.0f);
    REQUIRE(matrice1.ortho(0,0,3,4,5,6)[0][0] == 0.0f);
    REQUIRE(matrice1.frustum(0,0,2,3,0,0)[2][1] == 5.0f);
    REQUIRE(matrice1.perspective(1,2,1,3,2)[2][3] == -1.0f);
    REQUIRE(matrice1.translate(5,10,4)[3][1] == 10);
    REQUIRE(matrice1.rotate(1,2,3,0)[2][2] == (cosf(1)));
    REQUIRE_NOTHROW(matrice1.printf());

} 