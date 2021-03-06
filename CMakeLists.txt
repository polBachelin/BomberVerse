cmake_minimum_required(VERSION 3.17)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_COLOR_MAKEFILE ON)

project(project_bomberman
        LANGUAGES CXX
        DESCRIPTION "Bomberman like game"
        )

set(GAMEENGINE_SRC
        "${PROJECT_SOURCE_DIR}/src/gameEngine/Animation.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/ADrawable.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BColor.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BText.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BRectangle.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BImage.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BCamera.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BCamera2D.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BModel.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BTexture2D.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BModelAnimation.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/Keyboard.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/Gamepad.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/Button.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/CheckBox.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/AButton.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BFont.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BAudio.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BMusic.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BSound.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BBoundingBox.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BSdf.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/systems/Move.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/systems/Collision.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/ADrawable.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/AAudioObject.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BEvt.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/objects/AGameObject.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/objects/Moveable.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/objects/InputButton.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/Transform.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/collider/Collider.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/collider/BoxCollider.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/Clock.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/collider/BoxCollider.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/Selector.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/Clock.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/Timer.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/component/PopUp.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/managers/WindowManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/managers/AudioManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/managers/ButtonManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/managers/AFileManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/scenes/components/Parallax.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/scenes/AScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/gameEngine/exceptions/Exception.cpp"
        "${PROJECT_SOURCE_DIR}/src/Errors.cpp"
        "${PROJECT_SOURCE_DIR}/src/utils/File.cpp"
        "${PROJECT_SOURCE_DIR}/src/utils/Directory.cpp"
        )

set(GAME_SRC
        "${PROJECT_SOURCE_DIR}/src/game/scenes/MainMenuScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/SplashScreenScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/ChoosePlayersScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/ChooseProfileScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/LoadScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/EmptyScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/SettingsScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/CreditScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/TutorialScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Character.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Player.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Gui.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/GameObject.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Tile.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/PowerUpTile.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/ACollectible.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Map.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/EffectFactory.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/AEffect.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/HealthUp.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/BombUp.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/FireUp.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/SpeedUp.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Effects/OneUp.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/TimedObject.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/AExplosif.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Bomb.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/Bot.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/objects/ExplosionAnimation.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/managers/ExplosionManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/managers/GlobalManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/systems/SettingConf.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/systems/Brain.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/systems/LoadParser.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/managers/GameManager.cpp"
       # "${PROJECT_SOURCE_DIR}/src/game/objects/Collectible.cpp"
        )

set(UTILS_SRC
        "${PROJECT_SOURCE_DIR}/src/utils/Path.cpp"
        "${PROJECT_SOURCE_DIR}/src/utils/Utilitaries.cpp"
        "${PROJECT_SOURCE_DIR}/src/utils/TimestampUtil.cpp"
        "${PROJECT_SOURCE_DIR}/src/Errors.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/scenes/PlayGameScene.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/managers/SceneManager.cpp"
        "${PROJECT_SOURCE_DIR}/src/game/managers/UserManager.cpp"
        )

set(MY_INCLUDE
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/include/utils"
        "${PROJECT_SOURCE_DIR}/include/gameEngine"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/objects"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/encapsulation"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/systems"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/component"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/component/collider"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/interfaces"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/managers"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/scenes"
        "${PROJECT_SOURCE_DIR}/include/gameEngine/scenes/components"
        "{$PROJECT_SOURCE_DIR}/include/gameEngine/exceptions"
        "${PROJECT_SOURCE_DIR}/include/game"
        "${PROJECT_SOURCE_DIR}/include/game/scenes"
        "${PROJECT_SOURCE_DIR}/include/game/managers"
        "${PROJECT_SOURCE_DIR}/include/game/objects/"
        "${PROJECT_SOURCE_DIR}/include/game/objects/Effects"
        "${PROJECT_SOURCE_DIR}/include/WindowsEquivalent"
        "${PROJECT_SOURCE_DIR}/include/game/systems/"
        )

set(raylib_DIR ${PROJECT_SOURCE_DIR}/cmake_dep)
find_package(raylib REQUIRED)

set(MY_DEPENDENCIES
        raylib
        )


add_executable(bomberman
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${GAMEENGINE_SRC}
        ${GAME_SRC}
        ${UTILS_SRC}
        )

set_target_properties(bomberman
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )

target_compile_features(bomberman PRIVATE cxx_std_17)

target_link_libraries(bomberman ${MY_DEPENDENCIES})

target_include_directories(bomberman BEFORE PUBLIC ${MY_INCLUDE})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(bomberman PRIVATE -Wall -Wextra -Wno-missing-field-initializers)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Window")
    target_compile_options(bomberman PRIVATE -Wall -Wextra -Wno-missing-field-initializers)
endif ()
