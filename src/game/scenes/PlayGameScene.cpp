/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#include "PlayGameScene.hpp"

using namespace game::scenes;
#define ANIMWALK_PATH "assets/All/Animations/CharacterWalk.iqm"
#define ANIMIDLE_PATH "assets/All/Animations/CharacterIdle.iqm"

static const gameEngine::component::Transform BOT_LEFT_SPAWN(Vector3T<float>(10, 10, 10), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));
static const gameEngine::component::Transform TOP_LEFT_SPAWN(Vector3T<float>(130, 10, 10), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));
static const gameEngine::component::Transform BOT_RIGHT_SPAWN(Vector3T<float>(130, 10, 150), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));
static const gameEngine::component::Transform TOP_RIGHT_SPAWN(Vector3T<float>(10, 10, 150), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));

PlayGameScene::PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _map(_info->getUniverse(), 15), _pause(false)
{
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    std::string textStr = "assets/" + _info->getUniverse() + "/Textures/Character.png";
    std::string modelStr = "assets/" + _info->getUniverse() + "/Models/Character.iqm";
    std::vector<gameEngine::component::Transform> SPAWNS = {
        BOT_LEFT_SPAWN,
        BOT_RIGHT_SPAWN,
        TOP_LEFT_SPAWN,
        TOP_RIGHT_SPAWN
    };
    std::array<std::string, 3> botNames = {"Bob", "Michel", "Jacquie"};
    std::vector<gameEngine::component::Transform>::iterator spawnIt = SPAWNS.begin();

    _map.dump();
    std::srand(_map.getSeed());
    for (auto &tile : _map.getTiledMap()) {
        _tiles.push_back(std::make_shared<game::objects::Tile>(tile));
    }

    for (auto it : _info->_players) {
        std::shared_ptr<game::objects::Player> player =
        std::make_shared<game::objects::Player>(std::to_string(it->Id), it->name, textStr, modelStr, ANIMWALK_PATH, ANIMIDLE_PATH, it);
        player->setTransform().setScale(spawnIt->getScale());
        player->setTransform().setPosition(spawnIt->getPosition());
        player->setTransform().setRotation(spawnIt->getRotation());
        player->setCollider();
        spawnIt++;
        _players.push_back(player);
    }
    for (size_t i = 0; i < (size_t)_info->nbBots; i++) {
        std::shared_ptr<game::objects::Bot> bot =
        std::make_shared<game::objects::Bot>(std::to_string(i + 1), botNames.at(i), textStr, modelStr, ANIMWALK_PATH, ANIMIDLE_PATH, _tiles, 0, Vector<int>(15, 17));
        bot->setTransform().setScale(spawnIt->getScale());
        bot->setTransform().setPosition(spawnIt->getPosition());
        bot->setTransform().setRotation(spawnIt->getRotation());
        bot->setCollider();
        spawnIt++;
        _players.push_back(bot);
    }

    this->setupCamera();
    std::string nb(std::to_string(std::rand() % 3));
    _audio.loadMusicStreamFromFile("./assets/All/Music/Game" + nb + ".wav");
    _audio.loadSoundFromFile("./assets/All/Sound/Button.wav");

    std::shared_ptr<gameEngine::encapsulation::BModel> healthModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/HealthUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> healthTex = std::make_shared<gameEngine::encapsulation::BTexture2D>("assets/All/Textures/Tile.png");
    _healtTile = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::ONEUP, Vector3T<float>{10, 10, 20},
        Vector3T<float>{0, 0, 0}, Vector3T<float>{5, 5, 5});
    _tiles.push_back(_healtTile);

    _timer.getCurrentTime().setTextPosition(Vector<float>(_windowManager->getWindowSize()._x /2, 30));
    _timer.startThread();
    _timer.getCurrentTime().setColor(RED);
    _timer.getCurrentTime().setTextSize(100);

    gameEngine::encapsulation::BText pauseText("PAUSE", Vector<float>(10, 10), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(50, 50), Vector<float>(10, 10), pauseText, BLUE);

    setupPause();
    _audio.setSoundVolume(15.0);
    _audio.playSound();
    _buttonManager.pushButton(button);
    _windowManager->setBackgroundColor({0, 170, 170, 255});
    _explosion = std::make_shared<game::managers::ExplosionManager>(_players, _tiles);
    _audio.setMusicVolume(1.0); //1.0 is max level
    _audio.playMusic();
}

void PlayGameScene::setupPause()
{
    Vector<float> size(300, 200);
    Vector<float> middle2(_windowManager->getWindowSize()._x/3 - size._x / 2 + size._x, _windowManager->getWindowSize()._y/3 - size._y / 2);

    gameEngine::encapsulation::BText resumeText("RESUME", Vector<float>(middle2._x + 110, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontPlay;
    fontPlay.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    resumeText.setFont(fontPlay);
    std::shared_ptr<gameEngine::encapsulation::Button> resume =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(310, 100), middle2, resumeText, DARKGRAY);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText quitText("QUIT", Vector<float>(middle2._x + 115, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontQuit;
    fontQuit.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    quitText.setFont(fontQuit);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, quitText, DARKGRAY);

    _pauseManager.pushButton(resume);
    _pauseManager.pushButton(buttonQuit);
}

void PlayGameScene::setupCamera() noexcept
{
    _cam.setPosition({-20, 180, 70});
    _cam.setTarget({70, 0, 70});
    _cam.setUp({0, 1, 0});
    _cam.setFovy(55);
    _cam.setProjection(CAMERA_PERSPECTIVE);
}

void PlayGameScene::collisionChecker(std::shared_ptr<game::objects::Character> &player, const Vector3T<float> &prev)
{
    for (auto tile = _tiles.begin(); tile != _tiles.end(); tile++) {
        if (player->getCollider().isColliding((*tile)->getCollider().getBoundingBox())) {
            player->setTransform().setPosition(prev);
            player->setIsMoving(false);
            player->onCollisionEnter(*(*tile));
            if ((*tile)->getTag() == ONEUP) {
                _tiles.erase(tile);
            } else
                tile++;
        }
    }
}

void PlayGameScene::updateExplosionManager()
{
    _explosion->setObjects(_players, _tiles);
    _explosion->update();
    _tiles = _explosion->getTiles();

    auto array = _explosion->getBombs();
    for (auto &bomb : array) {
        // std::cout << bomb->getTransform() << std::endl;
        _tiles.push_back(bomb);
    }
}

void PlayGameScene::updatePause()
{
    _pauseManager.updateButtons();
    if (_pauseManager.isButtonClicked("RESUME")) {
        _pause = false;
        _timer.setPause(false);
    }
    if (_pauseManager.isButtonClicked("QUIT")) {
        _timer.setPause(false);
        quit();
    }
}

void PlayGameScene::drawPause()
{
    _pauseManager.drawButtons();
}

void PlayGameScene::quit()
{
    _timer.setIsDone(true);
    _timer.wait();
    _info->setQuit(true);
}

void PlayGameScene::update()
{
    //updateExplosionManager();
    _healtTile->update();
    _buttonManager.updateButtons();
    _audio.updateMusicStream();
    if (!_windowManager->isRunning())
        quit();
    if (_buttonManager.isButtonClicked("PAUSE")) {
        _pause = true;
        _timer.setPause(true);
    }
    if (_pause) {
        updatePause();
        return;
    }
    std::vector<std::pair<int, game::Event>> events = _info->_inputManager->pollEvents();
    for (auto &[id, evt]: events)
    {
        if (id <= _players.size()) {
            _players[id - 1]->setCurrentEvent(evt);
        }
    }
    for (auto &player : _players) {
        Vector3T<float> prev(player->getTransform().getPosition());
        auto list = player->getBombQueue();
        player->update();
        collisionChecker(player, prev);
        if (player->hasDropped()) {
            for (auto &bomb : list) {
                if (bomb->getSwitch()) {
                    _explosion->pushBomb(bomb);
                }
                bomb->setSwitch(false);
            }
        }
        player->setDropped(false);
    }
    updateExplosionManager();
}

void PlayGameScene::draw()
{
    //_explosion->draw();
    _buttonManager.drawButtons();
    int idx_player = 0;
    for (auto it : _players) {
        _gui.draw((*it), (game::Gui::corner_e)idx_player);
        idx_player++;
    }
    this->_windowManager->set3DMode(_cam);
    for (auto &it : _players) {
        it->draw();
        _gui.draw((*it), (game::Gui::corner_e)idx_player);
        idx_player++;
    }
    for (auto &tile : _tiles)
        tile->draw();
    _cam.endMode();
    _timer.getCurrentTime().draw();
    if (_pause) {
        drawPause();
    } else {
        _buttonManager.drawButtons();
    }
}
