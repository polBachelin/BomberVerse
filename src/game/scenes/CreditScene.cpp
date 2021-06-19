/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CreditScene
*/

#include "CreditScene.hpp"

using namespace game::scenes;

CreditScene::CreditScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    _creditText = std::string("Thank you for buying BOMBERVERSE: the Multiverse Bomberman... \n this game was made by : ") +
                  std::string("RedCode Games TM \n Produced for the Epitech Bomberman Project\n\n") +
                  std::string("DEVELOPPERS AND MANAGERS : \n") +
                  std::string("Pol BACHELIN : PHD in game engine architecture and professional non-sleeper\n") +
                  std::string("Antoine COUACAULT: the GUI monster, a clean commit every 2 minutes\n") +
                  std::string("Evan SABRE: the AI katana, creator of the Notion multiverse\n") +
                  std::string("Simon GUYADER: the C++ pianist, his code is alway impec(able) \n") +
                  std::string("Ewen THOMAS: silent but deadly, the asset's Ninja \n") +
                  std::string("(Jules) Omar MARLIN: styling and sounds, the Front End final boss \n\n") +
                  std::string("SPONSORED BY : \n") +
                  std::string("EPITECH University: the less you sleep the stronger you are...\n\n") +
                  std::string("REALISED BY : \n") +
                  std::string("RedCode Games TradeMark All Rights Reserved \n\n") +
                  std::string("SPECIAL THANKS\n") +
                  std::string("Our parents for creating such a handsome and smart team\n") +
                  std::string("Mixamo\n") +
                  std::string("Coffee\n") +
                  std::string("Killian VALETTE : the Fallen AER\n\n");

    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadMusicStreamFromFile("./assets/All/Music/Credits.mp3");
    _audio->loadSoundFromFile("./assets/All/Sound/Button.wav", "button");
    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
    _background.loadFromFile("./assets/Backgrounds/credits_background.png");
}

CreditScene::~CreditScene()
{
}

void CreditScene::start()
{
    _audio->playMusic();

    Vector<float> size(300, 200);
    Vector<float> middle(_windowManager->getWindowSize()._x / 2, _windowManager->getWindowSize()._y / 2);
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("CREDITS", 100, WHITE, Vector3T<float>(middle._x - 250, 60, 0));

    _text = std::make_shared<gameEngine::encapsulation::BText>(_creditText, Vector<float>(310, 1000), DARKBLUE, 35);

    //back to menu
    gameEngine::encapsulation::BText quitText("Back to Menu", Vector<float>(40, 1010), WHITE, 30);
    quitText.setFont(_font);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 50), Vector<float>(20, 1000), quitText, DARKGRAY, WHITE, PLAY_BUTTON);

    _buttonManager.pushButton(buttonQuit);
}

void CreditScene::update()
{
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("Back to Menu")) {
        _audio->playSound("button");
        sleep(1);
        _info->setCurrentScene("menu");
    }
    if (_text->getTransform().getPosition()._y > (-1000)) {
        _text->setTransform().setPosition({_text->getTransform().getPosition()._x,
                                           _text->getTransform().getPosition()._y - 0.5f,
                                           _text->getTransform().getPosition()._z});
    } else
        _text->setTransform().setPosition({_text->getTransform().getPosition()._x,
                                           1000,
                                           _text->getTransform().getPosition()._z});
    _audio->updateMusicStream();
}

void CreditScene::draw()
{
    _background.draw();
    _title->draw();
    _text->draw();
    _buttonManager.drawButtons();
}

