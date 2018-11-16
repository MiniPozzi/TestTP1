#include "catch.hpp"
#include "../src/imlib/linked.cpp"

TEST_CASE("Noeud")
{
    linked_node * link1 = new linked_node();
    linked_node * link2 = new linked_node();

    // à l'initialisation d'un noeud (link1)
    REQUIRE(link1 != nullptr);
    REQUIRE(link1->Next() == nullptr);
    REQUIRE(link1->Prev() == nullptr);

    // ajout du noeud link2 après le noeud link1
    link1->SetNext(link2);
    REQUIRE(link1->Next() == link2);
    REQUIRE(link1->Prev() == nullptr);

    // ajout du neud link1 avant le neud link2
    link2->SetPrev(link1);
    REQUIRE(link2->Prev() == link1);
    REQUIRE(link2->Next() == nullptr);

    // suppression des noeuds
    delete(link1);
    delete(link2);
}

TEST_CASE("Liste de noeuds, ajouts au début et à la fin de la liste")
{
    linked_list * list = new linked_list();
    linked_node * link1 = new linked_node();
    linked_node * link2 = new linked_node();
    linked_node * link3 = new linked_node();
    linked_node * link4 = new linked_node();

    // à l'initialisation de la liste list
    REQUIRE(list->Count() == 0);
    REQUIRE(list->first() == nullptr);

    // ajout du noeud link1 au début
    list->add_front(link1);
    REQUIRE(list->Count() == 1);
    REQUIRE(list->first() == link1);
    REQUIRE(list->prev() == link1);

    // ajout du noeud link2 au début
    list->add_front(link2);
    REQUIRE(list->Count() == 2);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->first())->Next() == link1);
    REQUIRE((list->prev())->Next() == link2);
    REQUIRE((list->first())->Next()->Prev() == link2);

    // ajout du noeud link3 au début
    list->add_front(link3);
    REQUIRE(list->Count() == 3);
    REQUIRE(list->first() == link3);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->first())->Prev() == link1);
    REQUIRE((list->first())->Next() == link2);
    REQUIRE((list->prev())->Next() == link3);
    REQUIRE((list->first())->Next()->Prev() == link3);

    // ajout du noeud link4 à la fin
    list->add_end(link4);
    REQUIRE(list->Count() == 4);
    REQUIRE(list->first() == link3);
    REQUIRE(list->prev() == link4);
    REQUIRE((list->first())->Next() == link2);
    REQUIRE((list->prev())->Next() == link3);
    REQUIRE((list->first())->Next()->Prev() == link3);

     delete(list); // les noeuds de la liste sont détruits dans le destructeur de la liste
}

TEST_CASE("Liste de noeuds, suppressions de noeud dans la liste")
{
    linked_list * list = new linked_list();
    linked_node * link1 = new linked_node();
    linked_node * link2 = new linked_node();
    linked_node * link3 = new linked_node();
    linked_node * link4 = new linked_node();
    linked_node * link5 = new linked_node();

    // ajout des noeuds dans la liste
    list->add_front(link1);
    list->add_front(link2);
    list->add_front(link3);
    list->add_end(link4);

    // suppression du noeud link5, ne faisant pas parti de la liste
    REQUIRE(list->unlink(link5) == 0); 

    // suppression du noeud de début link3 (m_first)
    REQUIRE(list->unlink(link3) == 1);
    REQUIRE(list->Count() == 3);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link4);
    REQUIRE((list->first())->Next() == link1);
    REQUIRE((list->prev())->Next() == link2);
    REQUIRE((list->first())->Next()->Prev() == link2);

    // suppression du noeud link4, juste avant le noeud du début
    REQUIRE(list->unlink(link4) == 1);
    REQUIRE(list->Count() == 2);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->prev())->Next() == link2);
    REQUIRE((list->first())->Next()->Prev() == link2);

    // suppression du noeud link1, juste après le noeud de début
        // il ne reste ainsi qu'un noeud qui doit boucler sur lui-même
    REQUIRE(list->unlink(link1) == 1);
    REQUIRE(list->Count() == 1);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link2);
    REQUIRE((list->first())->Next() == link2);
    REQUIRE((list->prev())->Next() == link2);
    REQUIRE((list->first())->Next()->Prev() == link2);

    // suppression du dernier noeud link2
    REQUIRE(list->unlink(link2) == 1);
    REQUIRE(list->Count() == 0);
    REQUIRE(list->first() == nullptr);
    // Lorsque la liste est vide, il faudrait lever une exception quand on appel la fonction prev(),
        // puisque il retourne m_first->Prev(), qui n'existe plus, ou alors retourner nullptr
    //REQUIRE_THROWS(list->prev());
    
    // suppression quand il n'y pas de neud
    REQUIRE(list->unlink(link1) == 0);

    delete(list); // les noeuds de la liste sont détruits dans le destructeur de la liste
    delete(link5);
}

TEST_CASE("Liste de noeuds, destructeur de la liste")
{
    linked_list * list = new linked_list();
    linked_node * link1 = new linked_node();
    linked_node * link2 = new linked_node();

    // ajout de noeuds
    list->add_front(link1);
    list->add_front(link2);

    delete(list); // les noeuds de la liste sont détruits dans le destructeur de la liste
    REQUIRE(list->Count() == 0);
    // list2->first devrait être égale à nullptr !! Cependant, list2->first() retourne une adresse
    //REQUIRE(list2->first() == nullptr);
}

TEST_CASE("Liste de noeuds, ajouter une deuxième fois un même noeud")
{
    linked_list * list = new linked_list();
    linked_node * link1 = new linked_node();
    linked_node * link2 = new linked_node();

    // ajout du noeud link1 au début
    list->add_front(link1);
    REQUIRE(list->Count() == 1);
    REQUIRE(list->first() == link1);
    REQUIRE(list->prev() == link1);

    // ajout du noeud link2 au début
    list->add_front(link2);
    REQUIRE(list->Count() == 2);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->first())->Next() == link1);

    // ajout d'un noeud déjà dans la liste à son début : link1
        // il manque une exeption ici, puisque quand on ajoute un noeud qui existe déjà, l'intégrité de la liste n'est pas préservée actuellement
    list->add_front(link1);
    REQUIRE(list->Count() == 3);
    REQUIRE(list->first() == link1);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->first())->Next() == link1);

    delete(list); // les noeuds de la liste sont détruits dans le destructeur de la liste
    delete(link2);
}