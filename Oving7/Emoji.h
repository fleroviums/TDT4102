#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji{
	private:
		Circle faceCirc; // defined in .cpp
	public:
		virtual void attach_to(Graph_lib::Window&) = 0;
		Face(Point c, int r);
};

class EmptyFace : public Face{
	private:
		Ellipse lEye;
		Ellipse rEye;
	public:
		void attach_to(Graph_lib::Window&) override;
		EmptyFace(Point c, int r);
};

class SmilingFace : public EmptyFace{
	private:
		Arc smileMouth;
	public:
		void attach_to(Graph_lib::Window&);
		SmilingFace(Point c, int r, int smileDegree);
};

class SadFace : public EmptyFace{
	private:
		Arc sadMouth;
	public:
		void attach_to(Graph_lib::Window&);
		SadFace(Point c, int r, int smileDegree);
};

class AngryFace : public SadFace{
	private:
		Arc lBrow;
		Arc rBrow;
	public:
		void attach_to(Graph_lib::Window&);
		AngryFace(Point c, int r);
};

class WinkingFace : public SmilingFace{
	private:
		Line upperWinkLine;
		Line lowerWinkLine;
		Ellipse eyeCover;
	public:
		void attach_to(Graph_lib::Window&);
		WinkingFace(Point c, int r);
};

class SurprisedFace : public SmilingFace{
	private:
		//Arc wowMouth;
	public:
		void attach_to(Graph_lib::Window&);
		SurprisedFace(Point c, int r);

};