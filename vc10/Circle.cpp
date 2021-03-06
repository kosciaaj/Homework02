/*
 * @file Circle.cpp
 * A circle that can contain multiple circles in itself.
 *
 * @author Mike Marsden
 * @date 2012-09-23
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */ 
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "Circle.h"
#include "cinder/Rand.h";

using namespace ci;
using namespace ci::app;
using namespace std;


Circle::Circle(int depth, Vec2f position, Vec2f offset, float radius){
	//This is a circular list, so a list of length 1 has
	// next and prev pointing to itself
	next_ = prev_ = this;
	children_ = NULL;
}

// Referenced from the notes from class
void insertAfter(Circle* new_item, Circle* insert_here){
	new_item->next_ = insert_here->next_;
	new_item->prev_ = insert_here;
	insert_here->next_->prev_ = new_item;
	insert_here->next_ = new_item;
}

