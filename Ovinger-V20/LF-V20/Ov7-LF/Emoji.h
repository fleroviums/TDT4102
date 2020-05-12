#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

// Abstract class. Implementing classes has to implement attach_to() as a means
// to attach Shapes to the Window they're to be displayed in.
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

	// Relevant becaues Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course
	virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{
public:
	Face(Point c, int r);
	void attach_to(Graph_lib::Window& win) override = 0;

private:
	Circle face;
};

// A face with two eyes
class EmptyFace : public Face
{
public:
	EmptyFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Circle leftEye;
	Circle rightEye;
};

// A classic smiley face, child of EyeFace
class SmilingFace : public EmptyFace
{
public:
	SmilingFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

protected:
	// Protected access to mouth. The solution guide utilizes that a
	// SadFace, which in this guide derives from SmilingFace, has the
	// same kind of mouth, flipped vertically. The same goes for
	// SurprisedFace which uses the same Arc and completes the circle
	// by adjusting the start_degree and end_degree.
	Arc mouth;
};

// A surprised face, child of SmilingFace. Complete circle mouth, slightly
// offset from middle
class SurprisedFace : public SmilingFace
{
public:
	SurprisedFace(Point c, int r);
	// Reusing the mouth from SmilingFace proves effective in this example,
	// but any change in SmilingFace has to be compensated for in this class.
	// E.g. if the mouth in SmilingFace changes position, width, height or any
	// attribute the changes propagate to this SurprisedFace as well.
	// Worth keeping in mind as it's a possibly unhealthy dependency.
};

// A sad face, child of SmilingFace. Mouth is inverted and slightly offset.
class SadFace : public SmilingFace
{
public:
	SadFace(Point c, int r);
	// Have a look at the comment for SurprisedFace as to why deriving from
	// SmilingFace seems like a good option, but might prove disastrous.
};

// Square mouthed angry face showing teeth.
class AngryFace : public EmptyFace
{
public:
	AngryFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Rectangle mouth;
	Lines teeth;
	Line leftBrow;
	Line rightBrow;
};

// A face with a neutral look - straight lined mouth.
class NeutralFace : public EmptyFace
{
public:
	NeutralFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Line mouth;
};

// A face similar with a winking rightEye (160 deg Arc).
class WinkFace : public Face
{
public:
	WinkFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Circle leftEye;
	Arc rightEye;
	Arc mouth;
};
