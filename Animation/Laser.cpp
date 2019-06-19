#include "GrandChains.h"
#include "Laser.h"
#include "Level1.h"
#include "Level2.h"

Laser::Laser(int startX, int startY, uint direction, float fireTime, float fireOut, Game* actualLevel, uint level) {
	type = ENEMY;
	MoveTo(startX, startY, Layer::FRONT);

	switch (direction) {
		case UP:
			ejector = new Sprite("Resources/ejectorUp.png");
			fire = new TileSet("Resources/fireUp.png", 98, 146, 1, 2);
			detectArea = new DetectArea(x, y, -30, -200, 30, 0, actualLevel, level, this, LASER);
			break;

		case DOWN:
			ejector = new Sprite("Resources/ejectorDown.png");
			fire = new TileSet("Resources/fireDown.png", 98, 146, 1, 2);
			detectArea = new DetectArea(x, y, -30, 0, 30, -200, actualLevel, level, this, LASER);
			break;

		case RIGHT:
			ejector = new Sprite("Resources/ejectorRight.png");
			fire = new TileSet("Resources/fireRight.png", 146, 98, 2, 2);
			detectArea = new DetectArea(x, y, 0, -30, 200, 30, actualLevel, level, this, LASER);
			break;

		case LEFT:
			ejector = new Sprite("Resources/ejectorLeft.png");
			fire = new TileSet("Resources/fireLeft.png", 146, 98, 2, 2);
			detectArea = new DetectArea(x, y, -200, -30, 0, 30, actualLevel, level, this, LASER);
			break;
	}

	Laser::fireTime	= fireTime;
	Laser::fireOut	= fireOut;
	Laser::direction = direction;
	Laser::actualLevel = actualLevel;
	Laser::level = level;

	Level1* l1 = (Level1*)actualLevel;
	Level2* l2 = (Level2*)actualLevel;
	switch (level) {
		case LEVEL1:
			l1->scene->Add(detectArea, STATIC);
			break;
		
		case LEVEL2:
			l2->scene->Add(detectArea, STATIC);
			break;
	}

	fireAnim = new Animation(fire, 0.2 / 2, true);
}

Laser::~Laser() {
	delete ejector;
	delete fire;

	Level1* l1 = (Level1*)actualLevel;
	Level2* l2 = (Level2*)actualLevel;
	switch (level) {
		case LEVEL1:
			l1->scene->Delete(detectArea, STATIC);
			break;

		case LEVEL2:
			l2->scene->Delete(detectArea, STATIC);
			break;

	}
}

void Laser::Update() {
	if (countFireOut < fireOut && countFireTime == 0) {
		countFireOut += gameTime;
		firing = false;
	} else {
		countFireOut = 0;

		firing = true;
		countFireTime += gameTime;

		if (countFireTime >= fireTime) {
			countFireTime = 0;
		}
	}
}

void Laser::Draw() {
	if (firing) {

		switch (direction) {
			case UP:
				fireAnim->Draw(x, y - 100, Layer::MIDBACK);
				fireAnim->NextFrame();
				break;

			case DOWN:
				fireAnim->Draw(x, y + 100, Layer::MIDBACK);
				fireAnim->NextFrame();
				break;

			case RIGHT:
				fireAnim->Draw(x + 100, y, Layer::MIDBACK);
				fireAnim->NextFrame();
				break;

			case LEFT:
				fireAnim->Draw(x - 100, y, Layer::MIDBACK);
				fireAnim->NextFrame();
				break;
		}


	}

	ejector->Draw(x,y, Layer::MIDFRONT);
}

bool Laser::isFiring() {
	return firing;
}
