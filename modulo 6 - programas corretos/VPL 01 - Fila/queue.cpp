#include "queue.h"

struct Node {
  	int key;
  	Node* next;
};

Queue::Queue() {
	this->size = 0;
	this->back_ = nullptr;
	this->front_ = nullptr;
}

void Queue::push(int k) {
	Node* node = new Node;
	node->key = k;

	if(this->size == 0){
		this->front_ = node;
		this->back_ = node;
	}
	if(this->size == 1){
		this->back_ = node;
		this->front_->next = this->back_;
	}
	
	Node* aux_var = this->back_;
	this->back_ = node;
	aux_var->next = this->back_;
	
	this->size++;
}

void Queue::pop() {
	if(this->size == 0){
		throw EmptyException();
	}
	else{
		Node* node = this->front_;
		this->front_ = node->next;
		this->size--;
		delete node;
	}
}

int Queue::front() const {
	if(this->size == 0){
		throw EmptyException();
	}
	else{
		return this->front_->key;
	}
}

int Queue::back() const {
	if(this->size == 0){
		throw EmptyException();
	}
	else{
		return this->back_->key;
	}
}

int Queue::count() const {
	return this->size;
}