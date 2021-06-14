/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#include "MainMenuScene.hpp"
#include "InputButton.hpp"
#include "Vector.hpp"

using namespace game::scenes;

#define BACKGROUND "./resources/backgrounds/cyberpunk_street_background.png"
#define MIDGROUND "./resources/backgrounds/cyberpunk_street_midground.png"
#define FOREGROUND "./resources/backgrounds/cyberpunk_street_foreground.png"
#define PLAY_BUTTON "./resources/UI-Elements/PlayButton.png"

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info)
: AScene(windowManager, info)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::start()
{
    Vector<float> size(300, 200);
    Vector<float> middle1(_windowManager->getWindowSize()._x/3 - size._x / 2, _windowManager->getWindowSize()._y/3 - size._y / 2);
    Vector<float> middle2(_windowManager->getWindowSize()._x/3 - size._x / 2 + size._x, _windowManager->getWindowSize()._y/3 - size._y / 2);
    Vector<float> zero(0, 0);

    std::shared_ptr<gameEngine::encapsulation::BRectangle> rect = std::make_shared<gameEngine::encapsulation::BRectangle>(size, zero);
    std::shared_ptr<gameEngine::encapsulation::BText> text = std::make_shared<gameEngine::encapsulation::BText>("hello");

    // text->loadFromImgRelRect(PLAY_BUTTON, size);
    // text->setPos(Vector<int>(middle._x, middle._y));

    std::shared_ptr<gameEngine::object::InputButton> input =
    std::make_shared<gameEngine::object::InputButton>(size, middle1, gameEngine::encapsulation::BText("Input Name"), LIGHTGRAY, RED);

    gameEngine::encapsulation::BText strText("PLAY", Vector<float>(middle2._x + size._x / 2, middle2._y), WHITE, 30);
    strText.setTextPosition(Vector<float>(middle2._x + size._x / 2 - strText.getTextSize(), middle2._y));
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(size, middle2, strText, LIGHTGRAY);

    gameEngine::encapsulation::BText strText2("PLAY", Vector<float>(10, 10), WHITE, 30);
    strText.setTextPosition(Vector<float>(10, 10));
    std::shared_ptr<gameEngine::object::CheckBox> box =
    std::make_shared<gameEngine::object::CheckBox>(rect, text);


    _parallax.initParallax(BACKGROUND, MIDGROUND, FOREGROUND);
    _buttonManager.pushButton(button);
    _buttonManager.pushButton(input);
    _buttonManager.pushButton(box);
}

std::string MainMenuScene::update()
{
    _parallax.calculateParallax(0.1f, 0.5f, 1.0f);
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PLAY")) {
        std::cout << "Clicked play button\n";
        return "";
    }
    // if (_checkboxManager.isClicked("checkBox")) {
    //     std::cout << "Swithch" << std::endl;
    // }
    return "";
}

void MainMenuScene::draw()
{
    _parallax.drawParallax();
    _buttonManager.drawButtons();
}
