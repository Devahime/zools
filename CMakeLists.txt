cmake_minimum_required(VERSION 3.24)
project(zools2023_xkaderk2)

set(CMAKE_CXX_STANDARD 17)

add_executable(zools2023_xkaderk2 main.cpp Player/Player.h Player/Player.cpp Entitites/Enemy.h Entitites/Enemy.cpp Entitites/Item.h Entitites/Item.cpp Entitites/Armor.h Entitites/Armor.cpp Entitites/Weapon.h Entitites/Weapon.cpp Entitites/Relic.h Entitites/Relic.cpp Entitites/Consumable.h Entitites/Consumable.cpp Player/Ability.h Player/Ability.cpp Player/Punch.h Player/Punch.cpp Player/Kick.h Player/Kick.cpp Player/Slash.h Player/Slash.h.cpp GameLogic/Combat.h GameLogic/Combat.cpp Map/Map.cpp Map/Map.h Map/Tile.cpp Map/Tile.h Map/Floor.cpp Map/Floor.h Map/Door.cpp Map/Door.h Map/Wall.cpp Map/Wall.h Map/EnemyTile.cpp Map/EnemyTile.h Map/ItemTile.cpp Map/ItemTile.h Map/PlayerTile.cpp Map/PlayerTile.h Map/Point.h GameLogic/Builder.h GameLogic/Game.h GameLogic/Builder.cpp GameLogic/Game.cpp)
