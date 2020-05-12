#include "LinkedList.h"

/*
    T E O R I
- List er mer hensiktsmessig særlig ved insert og remove. Fordelen list har, er at den kun trenger oppdatere hva nodene rett før og etter elementet vi legger til/fjerner.
    En vector må derimot oppdatere hele seg selv, noe som blir veldig tydelig med større datasett.
- stack/queue er vel også "non-contiguous", og bruker nodes på samme måte som list?
    vector derimot lagrer hele sin data på samme plass, og vil vel ikke kunne blitt implementert vha nodes    
*/

namespace LinkedList{
    gutta::ostream& operator<<(gutta::ostream& os, const Node& node){
        return os << node.getValue() << gutta::endl;

    }
    Node* LinkedList::insert(Node* pos, const gutta::string& value){
        auto newNode = gutta::make_unique<Node>(value, gutta::move(pos->prev->next), pos->prev);
        pos->prev->next = gutta::move(newNode);
        pos->prev = gutta::move(newNode->getNext());
        return newNode.get();
    }
    Node* LinkedList::remove(Node* pos){
        //Sjekker først om pos er første eller siste element..
        if(pos==head.get()){
            //Hvis vi skal fjerne første node skal vi bare endre head til å peke på vår next
            head = move(pos->next);
            head->prev=nullptr; //prev er bare en raw ptr og må deallokeres manuelt..
            return head.get();
        }
        if(pos->next.get()==tail){
            pos->next->prev = gutta::move(pos->prev);
            return pos->next.get();
        }
        else{
            pos->prev->next = gutta::move(pos->next);
            pos->next->prev = gutta::move(pos->prev);
            return pos->next.get();
        }
    }

    Node* LinkedList::find(const gutta::string& value){
        auto thsNode = head.get();
        while(thsNode!=tail){ //Så lenge vi ikke har iterert ferdig lista
            if(value==thsNode->getValue()){
                return thsNode;
            }
            thsNode = thsNode->next.get();
            //thsNode blir en iterator som går gjennom LinkedList
        }
        return thsNode; //Retunerer evt tail hvis if aldri tilfredsstilles
    }

    void LinkedList::remove(const gutta::string& value){
        Node* rmvNode = find(value);
        if(rmvNode!=tail){ //Vil ikke fjerne tail:)
            remove(rmvNode); //Satser på at dette er lov, selv om remove egetnlig returnerer en Node*
        }
    }

    gutta::ostream& operator<<(gutta::ostream& os, const LinkedList& list){
        //Vil iterere oss gjennom linkedlist og skrive ut hver verdi:
        auto thsNode = list.head.get();
        while(thsNode!=list.tail){
            os << thsNode->getValue() << '\n';
        }
        return os;
    }


}