//cards.cpp
//Authors: Student who received full credit
//Implementation of the classes defined in cards.h
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "cards.h"

using namespace std;

//  CLASS CARD

Card::Card(){
	suit = 's';
	value = 'a';
}



void LinkedList::append(Card& card){
	Node* tmp = new Node{card, 0};
	if(!this->first){
		this->first = tmp;
		this->last = tmp;
	}
	else{
		this->last->next = tmp;
		this->last = tmp;
	}
}



bool LinkedList::contains(Card& target) const{
	Node* i = this->first;
	while(i){
		if(i->card == target) return i;
		i = i->next;
	}
	return false;
}

Card* LinkedList::findMatch(LinkedList& other) const{
	Node* target = this->first;
        while(target){
                if(other.contains(target->card)) return &target->card;
                target = target->next;
        }
        return NULL;
}

void LinkedList::remove(Card& target){
	Node* i = this->first;
	Node* prev;
	while(i && !(i->card == target)){
		prev = i;
		i = i->next;
	}
	//at this point either i is pointing at a card or no matching card is found
	if(!i) return;
	//at this point i is pointing at the card
	
	//if i is the first node, delete it
	if(this->first == i){
		this->first = i->next;
		//if also last, set last to NULL
		if(this->last == i) this->last = 0;
		delete i;
		return;
	}
	//at this point i is pointing at the correct node that is not the first one
	prev->next = i->next;
	if(this->last == i) this->last = prev;
	delete i;
}

