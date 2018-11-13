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
    //REQUIRE(link1 == nullptr);
    //REQUIRE(link2 == nullptr);
}

TEST_CASE("Liste de noeuds")
{
    linked_list * list = new linked_list();
    linked_list * list2 = new linked_list();
    linked_node * link1 = new linked_node();
    linked_node * link2 = new linked_node();
    linked_node * link3 = new linked_node();
    linked_node * link4 = new linked_node();
    linked_node * link5 = new linked_node();

    linked_node * link6 = new linked_node();
    linked_node * link7 = new linked_node();

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

    // ajout du noeud link3 au début
    list->add_front(link3);
    REQUIRE(list->Count() == 3);
    REQUIRE(list->first() == link3);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->first())->Prev() == link1);
    REQUIRE((list->first())->Next() == link2);

    // ajout du noeud link4 à la fin
    list->add_end(link4);
    REQUIRE(list->Count() == 4);
    REQUIRE(list->first() == link3);
    REQUIRE(list->prev() == link4);
    REQUIRE((list->first())->Next() == link2);

    // suppression du noeud link5, ne faisant pas parti de la liste
    REQUIRE(list->unlink(link5) == 0); 

    // suppression du noeud de début link3 (m_first)
    REQUIRE(list->unlink(link3) == 1);
    REQUIRE(list->Count() == 3);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link4);
    REQUIRE((list->first())->Next() == link1);

    // suppression du noeud link4, juste avant le noeud du début
    REQUIRE(list->unlink(link4) == 1);
    REQUIRE(list->Count() == 2);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link1);

    // suppression du noeud link1, juste après le noeud de début
    // il ne reste ainsi qu'un noeud qui doit boucler sur lui-même
    REQUIRE(list->unlink(link1) == 1);
    REQUIRE(list->Count() == 1);
    REQUIRE(list->first() == link2);
    REQUIRE(list->prev() == link2);
    REQUIRE((list->first())->Next() == link2);

    // suppression du dernier noeud link2
    REQUIRE(list->unlink(link2) == 1);
    REQUIRE(list->Count() == 0);
    REQUIRE(list->first() == nullptr);
   // REQUIRE(list->prev() == nullptr);                     // IL MANQUE UNE EXCEPTION

    // suppression quand il n'y pas de neud
    REQUIRE(list->unlink(link1) == 0);

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

    // ajout du noeud link1 au début
    // il manque une exeption ici, puisque quand on ajoute un noeud qui existe déjà, l'intégrité de la liste n'est pas préservé
    list->add_front(link1);
    REQUIRE(list->Count() == 3);
    REQUIRE(list->first() == link1);
    REQUIRE(list->prev() == link1);
    REQUIRE((list->first())->Next() == link1);

    delete(list);

    // ajout du noeud link6 au début
    list2->add_front(link6);
    REQUIRE(list2->Count() == 1);
    REQUIRE(list2->first() == link6);
    REQUIRE(list2->prev() == link6);

    // ajout du noeud link2 au début
    list2->add_front(link7);
    REQUIRE(list2->Count() == 2);
    REQUIRE(list2->first() == link7);
    REQUIRE(list2->prev() == link6);
    REQUIRE((list2->first())->Next() == link6);

    delete(list2);
    REQUIRE(list2->Count() == 0);
    //REQUIRE(list2->first() == nullptr);                   // ERREUR, list2->first devrait être égale à nullptr !!, et c'est encore un objet
}