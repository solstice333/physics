/*
 * datatypes.h
 *
 *  Created on: Aug 25, 2013
 *      Author: Alles Rebel
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <SDL/SDL.h>
#include <cmath>
#include <cfloat>
#include <string>

using namespace std;

/*
 * simple 2d position vector
 */
struct Vec2 {
	float x;
	float y;
	//bool operator=(const Vec2&); auto gen by compiler with 5 other func
	bool operator==(const Vec2&);
	bool operator!=(const Vec2&);
	float getMagnitude();
};

/*
 * 	Axis Aligned Bounding Boxes - basically a box
 *	that we will be checking for collisions in.
 *	I don't think we'll be supporting circles?
 */
struct AABB {
	Vec2 tLeftCorner; 	//top left
	Vec2 tRightCorner;	//top right
	Vec2 bLeftCorner;	//bottom left
	Vec2 bRightCorner;	//bottom right
	Vec2 Position;		//middle of the AABB
};

/*
 * Class to represent all assests loaded
 * from images. Text isn't counted here
 * The figure will probably be composed of
 * a ton of these
 * Each will be specifying it's own hit box (AABB)
 * only if physics applys to the object
 * TODO: Load from a file
 * TODO: Possibly a priority system to limit overlap
 */
class GraphicsObject {
	public:
	GraphicsObject(SDL_Surface*, int, int, int, SDL_Rect);
	//~GraphicsObject();
	void draw();
	void setPosition(SDL_Rect);
	SDL_Rect getPosition();
	void setFrame(int);

	AABB* getAABB();
	public:
	SDL_Surface* sprite;	//total sheet
	SDL_Rect* frameClip;		//clip rect
	SDL_Rect* location;		//location to blit to
	public:
	//cliping information
	int currentFrame;
	int frameWidth;	//properties of a single clip
	int frameHeight;	//properties of a single clip
	bool sheet;
};

/*
 * Physics object
 * These will be containers for the the physics
 * properties of an object
 *
 */
struct PhysicsObject {
	float mass;
	float invMass;

	float resitution;
	float density;

	Vec2 velocity;
	float angle;
};

/*
 * Figure class - basically combines
 * data needed for physics and graphics engines
 * TODO: More stuff here someday
 */
class Figure: public GraphicsObject {
	public:
	Figure(SDL_Surface*, int, int, int, SDL_Rect);

	AABB generateAABBs();
	public:
	//local data

	public:
	Vec2 velocity;
	Vec2 force;
};

/*
 * Simple Circle primitive - nothing special about it yet
 */
struct Circle {
	float r;	//radius
	Vec2 pos;	//position vec
};

#endif /* DATATYPES_H_ */
