/*#ifndef __DEMO_SPACESHIP_H__
#define __DEMO_SPACESHIP_H__

#include "GameUtil.h"
#include "GameObject.h"
#include "Shape.h"
#include "Bullet.h"

class DemoSpaceship : public GameObject
{
public:
	DemoSpaceship();
	DemoSpaceship(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r);
	DemoSpaceship(const DemoSpaceship& ds);
	virtual ~DemoSpaceship(void);

	virtual void Update(int t);
	virtual void Render(void);

	virtual void Thrust(float t);
	virtual void Rotate(float r);
	virtual void Shoot(void);

	void SetDemoSpaceshipShape(shared_ptr<Shape> demo_spaceship_shape) { mDemoSpaceshipShape = demo_spaceship_shape; }
	void SetThrusterShape(shared_ptr<Shape> thruster_shape) { mThrusterShape = thruster_shape; }
	void SetBulletShape(shared_ptr<Shape> bullet_shape) { mBulletShape = bullet_shape; }

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

private:
	float mThrust;

	shared_ptr<Shape> mDemoSpaceshipShape;
	shared_ptr<Shape> mThrusterShape;
	shared_ptr<Shape> mBulletShape;
};

#endif
*/