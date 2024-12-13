#include "sgg/graphics.h"
#include "stdio.h"
#include "string"
#include "gamestate.h"
using namespace graphics;

void draw() {
	GameState::getInstance()->draw();
}

void update(float dt) {
	GameState::getInstance()->update(dt);
}

void init() {
	GameState::getInstance()->init();
}

int main(int argc, char** argv) {

	graphics::createWindow(800, 800, "Stage 1");

	init();
		
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);


	graphics::setCanvasSize(GameState::getInstance()->getCanvasWidth(), GameState::getInstance()->getCanvasHeight());
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


	graphics::startMessageLoop();



	return 1;
}