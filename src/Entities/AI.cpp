/*
** EPITECH PROJECT, 2021
** YEP
** File description:
** AI
*/

#include "AI.hpp"

IS::AIPath::AIPath()
{
}

IS::Bomberman *IS::AIPath::getNearestBomberman(Vector3 aiPositions)
{
    float bestDistance = -1.0f;
    IS::Bomberman *nearestBomber = nullptr;

    for (IS::Bomberman *bomberman : IS::GLOBAL::_bombermans) {
        Vector3 bombermanPositions = bomberman->getPosition();
        if (bomberman->IsAlive()) {
            if (aiPositions.x != bombermanPositions.x || aiPositions.z != bombermanPositions.z) {
                float distance = Vector3Distance(aiPositions, bombermanPositions);
                if (distance < bestDistance || bestDistance == -1.0f) {
                    bestDistance = distance;
                    nearestBomber = bomberman;
                }
            }
        }
    }
    return (nearestBomber);
}

int IS::AIPath::bombInRange(Vector3 ai)
{
    int distance = 9999;
    int nearestBomb = -1;

    if (IS::GLOBAL::_map->getElement((ai.x) / 10, (ai.z) / 10) == IS::MAP_TILES::BOMB) {
        return (0);
    } else if (IS::GLOBAL::_map->getElement((ai.x + 8) / 10, (ai.z) / 10) == IS::MAP_TILES::BOMB) {
        return (0);
    } else if (IS::GLOBAL::_map->getElement((ai.x) / 10, (ai.z + 8) / 10) == IS::MAP_TILES::BOMB) {
        return (0);
    } else if (IS::GLOBAL::_map->getElement((ai.x + 8) / 10, (ai.z + 8) / 10) == IS::MAP_TILES::BOMB) {
        return (0);
    }

    for (int x = (ai.x + 4) / 10; x < IS::GLOBAL::_map->getWidth(); x += 1) {
        if (!IS::GLOBAL::_map->IsEmpty(x, (ai.z + 4) / 10)) {
            if (IS::GLOBAL::_map->getElement(x, (ai.z + 4) / 10) == IS::MAP_TILES::BOMB) {
                if (x - ((ai.x + 4) / 10) < distance) {
                    distance = x - ((ai.x + 4) / 10);
                    nearestBomb = 0; // Bombe à droite
                }
                // return (0); // bombe à droite
            }
            break;
        }
    }
    for (int x = (ai.x + 4) / 10; x > 0; x -= 1) {
        if (!IS::GLOBAL::_map->IsEmpty(x, (ai.z + 4) / 10)) {
            if (IS::GLOBAL::_map->getElement(x, (ai.z + 4) / 10) == IS::MAP_TILES::BOMB) {
                if (((ai.x + 4) / 10) - x < distance) {
                    distance = ((ai.x + 4) / 10) - x;
                    nearestBomb = 1; // bombe à gauche
                }
                // return (1); // bombe à gauche
            }
            break;
        }
    }
    for (int z = (ai.z + 4) / 10; z < IS::GLOBAL::_map->getHeight(); z += 1) {
        if (!IS::GLOBAL::_map->IsEmpty((ai.x + 4) / 10, z)) {
            if (IS::GLOBAL::_map->getElement((ai.x + 4) / 10, z) == IS::MAP_TILES::BOMB) {
                if (z - ((ai.z + 4) / 10) < distance) {
                    distance = z - ((ai.z + 4) / 10);
                    nearestBomb = 2; // Bombe en bas
                }
                // return (2); // bombe en bas
            }
            break;
        }
    }
    for (int z = (ai.z + 4) / 10; z > 0; z -= 1) {
        if (!IS::GLOBAL::_map->IsEmpty((ai.x + 4) / 10, z)) {
            if (IS::GLOBAL::_map->getElement((ai.x + 4) / 10, z) == IS::MAP_TILES::BOMB) {
                if (((ai.z + 4) / 10) - z) {
                    distance = ((ai.z + 4) / 10) - z;
                    nearestBomb = 3; // Bombe en haut
                }
                // return (3); // bombe en haut
            }
            break;
        }
    }
    return nearestBomb;
}

bool IS::AIPath::hasCrate(int x, int y)
{
    if (!IS::GLOBAL::_map->IsEmpty(x, y) &&
    IS::GLOBAL::_map->getElement(x, y) == IS::MAP_TILES::CRATE) {
        return true;
    }
    return false;
}

Vector3 IS::AIPath::moveBombDown(Vector3 ai, Vector3 oldVelocity)
{
    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;

    int xLeft = (ai.x) / 10;
    int xRight = (ai.x + 8) / 10;
    int yTop = (ai.z) / 10;
    int yBot = (ai.z + 8) / 10;

    Vector3 oldPos = Vector3Subtract(ai, oldVelocity);
    int b = bombInRange(oldPos);

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(x - 1, yTop);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(x - 1, yBot);

    bool isEmptyC = IS::GLOBAL::_map->IsEmpty(x + 1, yTop);
    bool isEmptyD = IS::GLOBAL::_map->IsEmpty(x + 1, yBot);

    bool isEmptyE = IS::GLOBAL::_map->IsEmpty(xLeft, y - 1);
    bool isEmptyF = IS::GLOBAL::_map->IsEmpty(xRight, y - 1);

    bool isEmptyG = IS::GLOBAL::_map->IsEmpty(xLeft, y + 1);
    bool isEmptyH = IS::GLOBAL::_map->IsEmpty(xRight, y + 1);

    if (b != 2 && b != -1) {
        return oldVelocity;
    }

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {0, 0, -1};
        } else if (!isEmptyA && isEmptyB) {
            return {0, 0, 1};
        } else {
            return {-1, 0, 0};
        }
    } else if (isEmptyC || isEmptyD) {
        if (isEmptyC && !isEmptyD) {
            return {0, 0, -1};
        } else if (!isEmptyC && isEmptyD) {
            return {0, 0, 1};
        } else {
            return {1, 0, 0};
        }
    } else if (isEmptyE || isEmptyF) {
        if (isEmptyE && !isEmptyF) {
            return {-1, 0, 0};
        } else if (!isEmptyE && isEmptyF) {
            return {1, 0, 0};
        } else {
            return {0, 0, -1};
        }
    } else if (isEmptyG || isEmptyH) {
        if (isEmptyG && !isEmptyH) {
            return {-1, 0, 0};
        } else if (!isEmptyG && isEmptyH) {
            return {1, 0, 0};
        } else {
            return {0, 0, 1};
        }
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveBombUp(Vector3 ai, Vector3 oldVelocity)
{
    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;

    int xLeft = (ai.x) / 10;
    int xRight = (ai.x + 8) / 10;
    int yTop = (ai.z) / 10;
    int yBot = (ai.z + 8) / 10;

    Vector3 oldPos = Vector3Subtract(ai, oldVelocity);
    int b = bombInRange(oldPos);

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(x - 1, yTop);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(x - 1, yBot);

    bool isEmptyC = IS::GLOBAL::_map->IsEmpty(x + 1, yTop);
    bool isEmptyD = IS::GLOBAL::_map->IsEmpty(x + 1, yBot);

    bool isEmptyE = IS::GLOBAL::_map->IsEmpty(xLeft, y + 1);
    bool isEmptyF = IS::GLOBAL::_map->IsEmpty(xRight, y + 1);

    bool isEmptyG = IS::GLOBAL::_map->IsEmpty(xLeft, y - 1);
    bool isEmptyH = IS::GLOBAL::_map->IsEmpty(xRight, y - 1);

    if (b != 3 && b != -1) {
        return oldVelocity;
    }

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {0, 0, -1};
        } else if (!isEmptyA && isEmptyB) {
            return {0, 0, 1};
        } else {
            return {-1, 0, 0};
        }
    } else if (isEmptyC || isEmptyD) {
        if (isEmptyC && !isEmptyD) {
            return {0, 0, -1};
        } else if (!isEmptyC && isEmptyD) {
            return {0, 0, 1};
        } else {
            return {1, 0, 0};
        }
    } else if (isEmptyE || isEmptyF) {
        if (isEmptyE && !isEmptyF) {
            return {-1, 0, 0};
        } else if (!isEmptyE && isEmptyF) {
            return {1, 0, 0};
        } else {
            return {0, 0, 1};
        }
    } else if (isEmptyG || isEmptyH) {
        if (isEmptyG && !isEmptyH) {
            return {-1, 0, 0};
        } else if (!isEmptyG && isEmptyH) {
            return {1, 0, 0};
        } else {
            return {0, 0, -1};
        }
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveBombLeft(Vector3 ai, Vector3 oldVelocity)
{
    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;

    int xLeft = (ai.x) / 10;
    int xRight = (ai.x + 8) / 10;
    int yTop = (ai.z) / 10;
    int yBot = (ai.z + 8) / 10;

    Vector3 oldPos = Vector3Subtract(ai, oldVelocity);
    int b = bombInRange(oldPos);

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(xLeft, y - 1);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(xRight, y - 1);

    bool isEmptyC = IS::GLOBAL::_map->IsEmpty(xLeft, y + 1);
    bool isEmptyD = IS::GLOBAL::_map->IsEmpty(xRight, y + 1);

    bool isEmptyE = IS::GLOBAL::_map->IsEmpty(x + 1, yTop);
    bool isEmptyF = IS::GLOBAL::_map->IsEmpty(x + 1, yBot);

    bool isEmptyG = IS::GLOBAL::_map->IsEmpty(x - 1, yTop);
    bool isEmptyH = IS::GLOBAL::_map->IsEmpty(x - 1, yBot);

    if (b != 1 && b != -1) {
        return oldVelocity;
    }

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {-1, 0, 0};
        } else if (!isEmptyA && isEmptyB) {
            return {1, 0, 0};
        } else {
            return {0, 0, -1};
        }
    } else if (isEmptyC || isEmptyD) {
        if (isEmptyC && !isEmptyD) {
            return {-1, 0, 0};
        } else if (!isEmptyC && isEmptyD) {
            return {1, 0, 0};
        } else {
            return {0, 0, 1};
        }
    } else if (isEmptyE || isEmptyF) {
        if (isEmptyE && !isEmptyF) {
            return {0, 0, -1};
        } else if (!isEmptyE && isEmptyF) {
            return {0, 0, 1};
        } else {
            return {1, 0, 0};
        }
    } else if (isEmptyG || isEmptyH) {
        if (isEmptyG && !isEmptyH) {
            return {0, 0, -1};
        } else if (!isEmptyG && isEmptyH) {
            return {0, 0, 1};
        } else {
            return {-1, 0, 0};
        }
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveBombRight(Vector3 ai, Vector3 oldVelocity)
{
    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;

    int xLeft = (ai.x) / 10;
    int xRight = (ai.x + 8) / 10;
    int yTop = (ai.z) / 10;
    int yBot = (ai.z + 8) / 10;

    Vector3 oldPos = Vector3Subtract(ai, oldVelocity);
    int b = bombInRange(oldPos);

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(xLeft, y - 1);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(xRight, y - 1);

    bool isEmptyC = IS::GLOBAL::_map->IsEmpty(xLeft, y + 1);
    bool isEmptyD = IS::GLOBAL::_map->IsEmpty(xRight, y + 1);

    bool isEmptyE = IS::GLOBAL::_map->IsEmpty(x - 1, yTop);
    bool isEmptyF = IS::GLOBAL::_map->IsEmpty(x - 1, yBot);

    bool isEmptyG = IS::GLOBAL::_map->IsEmpty(x + 1, yTop);
    bool isEmptyH = IS::GLOBAL::_map->IsEmpty(x + 1, yBot);

    if (b != 0 && b != -1) {
        return oldVelocity;
    }

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {-1, 0, 0};
        } else if (!isEmptyA && isEmptyB) {
            return {1, 0, 0};
        } else {
            return {0, 0, -1};
        }
    } else if (isEmptyC || isEmptyD) {
        if (isEmptyC && !isEmptyD && b == 0) {
            return {-1, 0, 0};
        } else if (!isEmptyC && isEmptyD && b == 0) {
            return {1, 0, 0};
        } else {
            return {0, 0, 1};
        }
    } else if (isEmptyE || isEmptyF) {
        if (isEmptyE && !isEmptyF) {
            return {0, 0, -1};
        } else if (!isEmptyE && isEmptyF) {
            return {0, 0, 1};
        } else {
            return {-1, 0, 0};
        }
    } else if (isEmptyG || isEmptyH) {
        if (isEmptyG && !isEmptyH) {
            return {0, 0, -1};
        } else if (!isEmptyG && isEmptyH) {
            return {0, 0, 1};
        } else {
            return {1, 0, 0};
        }
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveLeft(Vector3 ai)
{
    int x = (ai.x + 4) / 10;

    int yTop = (ai.z) / 10;
    int yBot = (ai.z + 8) / 10;

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(x - 1, yTop);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(x - 1, yBot);

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {0, 0, -1};
        } else if (!isEmptyA && isEmptyB) {
            return {0, 0, 1};
        }
        return {-1, 0, 0};
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveRight(Vector3 ai)
{
    int x = (ai.x + 4) / 10;

    int yTop = (ai.z) / 10;
    int yBot = (ai.z + 8) / 10;

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(x + 1, yTop);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(x + 1, yBot);

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {0, 0, -1};
        } else if (!isEmptyA && isEmptyB) {
            return {0, 0, 1};
        }
        return {1, 0, 0};
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveDown(Vector3 ai)
{
    int y = (ai.z + 4) / 10;

    int xLeft = (ai.x) / 10;
    int xRight = (ai.x + 8) / 10;

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(xLeft, y + 1);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(xRight, y + 1);

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {-1, 0, 0};
        } else if (!isEmptyA && isEmptyB) {
            return {1, 0, 0};
        }
        return {0, 0, 1};
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveUp(Vector3 ai)
{
    int y = (ai.z + 4) / 10;

    int xLeft = (ai.x) / 10;
    int xRight = (ai.x + 8) / 10;

    bool isEmptyA = IS::GLOBAL::_map->IsEmpty(xLeft, y - 1);
    bool isEmptyB = IS::GLOBAL::_map->IsEmpty(xRight, y - 1);

    if (isEmptyA || isEmptyB) {
        if (isEmptyA && !isEmptyB) {
            return {-1, 0, 0};
        } else if (!isEmptyA && isEmptyB) {
            return {1, 0, 0};
        }
        return {0, 0, -1};
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::checkNearestPlace(Vector3 ai)
{
    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;

    bool wall = false;
    Vector3 aiClear;
    Vector3 nearest;
    Vector3 nearestWall;
    Vector3 test;
    IS::Bomberman *bomber = getNearestBomberman(ai);

    aiClear.x = x;
    aiClear.y = -1;
    aiClear.z = y;
    nearestWall.x = -1;
    nearestWall.y = -1;
    nearestWall.z = -1;
    nearest.x = -1;
    nearest.y = -1;
    nearest.z = -1;
    test.x = -1;
    test.y = -1;
    test.z = -1;

    for (int x1 = x; x1 < IS::GLOBAL::_map->getWidth(); x1 += 1) {
        if (IS::GLOBAL::_map->getElement(x1, y) == IS::MAP_TILES::BLOCK) {
            wall = true;
        }
        if (IS::GLOBAL::_map->getElement(x1, y) == IS::MAP_TILES::CRATE) {
            if (wall) {
                nearestWall.x = x1;
                nearestWall.z = y;
            } else {
                nearest.x = x1;
                nearest.z = y;
            }
            break;
        }
    }

    wall = false;
    for (int x1 = x; x1 > 0; x1 -= 1) {
        if (IS::GLOBAL::_map->getElement(x1, y) == IS::MAP_TILES::BLOCK) {
            wall = true;
        }
        if (IS::GLOBAL::_map->getElement(x1, y) == IS::MAP_TILES::CRATE) {
            test.x = x1;
            test.z = y;
            if (!wall) {
                if (Vector3Distance(test, aiClear) < Vector3Distance(nearest, aiClear)
                || (nearest.x == -1 && nearest.z == -1)) {
                    nearest.x = x1;
                    nearest.z = y;
                }
            } else {
                if (Vector3Distance(test, aiClear) < Vector3Distance(nearestWall, aiClear)
                || (nearestWall.x == -1 && nearest.z == -1)) {
                    nearestWall.x = x1;
                    nearestWall.z = y;
                }
            }
            break;
        }
    }

    wall = false;
    for (int y1 = y; y1 < IS::GLOBAL::_map->getHeight(); y1 += 1) {
        if (IS::GLOBAL::_map->getElement(x, y1) == IS::MAP_TILES::BLOCK) {
            wall = true;
        }
        if (IS::GLOBAL::_map->getElement(x, y1) == IS::MAP_TILES::CRATE) {
            test.x = x;
            test.z = y1;
            if (!wall) {
                if (Vector3Distance(test, aiClear) < Vector3Distance(nearest, aiClear) ||
                (nearest.x == -1 && nearest.z == -1)) {
                    nearest.x = x;
                    nearest.z = y1;
                }
            } else {
                if (Vector3Distance(test, aiClear) < Vector3Distance(nearestWall, aiClear) ||
                (nearestWall.x == -1 && nearestWall.z == -1)) {
                    nearestWall.x = x;
                    nearestWall.z = y1;
                }
            }
            break;
        }
    }

    wall = false;
    for (int y1 = y; y1 > 0; y1 -= 1) {
        if (IS::GLOBAL::_map->getElement(x, y1) == IS::MAP_TILES::BLOCK) {
            wall = true;
        }
        if (IS::GLOBAL::_map->getElement(x, y1) == IS::MAP_TILES::CRATE) {
            test.x = x;
            test.z = y1;
            if (!wall) {
                if (Vector3Distance(test, aiClear) < Vector3Distance(nearest, aiClear) ||
                (nearest.x == -1 && nearest.z == -1)) {
                    nearest.x = x;
                    nearest.z = y1;
                }
            } else {
                if (Vector3Distance(test, aiClear) < Vector3Distance(nearestWall, aiClear) ||
                (nearestWall.x == -1 && nearestWall.z == -1)) {
                    nearestWall.x = x;
                    nearestWall.z = y1;
                }
            }
            break;
        }
    }

    if (nearest.x == -1 && nearest.z == -1) {
        nearest = nearestWall;
    }

    test.x = (int) (bomber->getPosition().x + 4) / 10;
    test.z = (int) (bomber->getPosition().z + 4) / 10;
    if (Vector3Distance(test, aiClear) < Vector3Distance(nearest, aiClear)
    || (nearest.x == -1 && nearest.z == -1)) {
        nearest.x = test.x;
        nearest.z = test.z;
    }

    // std::cout << "Nearest: " << nearest.x << " " << nearest.z << std::endl;
    // std::cout << "AI: " << x << " " << y << std::endl;
    if (nearest.x == -1 && nearest.z == -1) {
        return moveRight(ai);
    } else if (nearest.x > x) {
        return moveRight(ai);
    } else if (nearest.x < x) {
        return moveLeft(ai);
    } else if (nearest.y > y) {
        return moveDown(ai);
    } else if (nearest.y < y) {
        return moveUp(ai);
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::move(Vector3 ai, Vector3 oldVelocity)
{
    // Check 4 places
    int b = bombInRange(ai);
    IS::Bomberman *bomber = getNearestBomberman(ai);

    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;

    switch (b) {
        case 0:
            return moveBombRight(ai, oldVelocity);
        case 1:
            return moveBombLeft(ai, oldVelocity);
        case 2:
            return moveBombDown(ai, oldVelocity);
        case 3:
            return moveBombUp(ai, oldVelocity);
        default:
            break;
    }

    if (Vector3Distance(ai, bomber->getPosition()) <= 1) {
        return {-1, -1, -1};
    }

    if (this->hasCrate(x + 1, y) || this->hasCrate(x - 1, y) ||
    this->hasCrate(x, y + 1) || this->hasCrate(x, y - 1)) {
        if (ai.x >= x && ai.z >= y) {
            return {-1, -1, -1};
        } else {
            return moveToAnotherPlace(ai, oldVelocity);
        }
    } else {
        return moveToAnotherPlace(ai, oldVelocity);
    }
    return {-1, -1, -1};
}

Vector3 IS::AIPath::moveToAnotherPlace(Vector3 ai, Vector3 oldVelocity)
{
    Vector3 expectedMove = checkNearestPlace(ai);

    if (expectedMove.x == -1 && expectedMove.z == -1) {
        return {-1, -1, -1};
    }
    Vector3 nextPos = Vector3Add(ai, expectedMove);
    if (bombInRange(nextPos) != -1) {
        return {-1, -1, -1};
    }

    return expectedMove;
}

bool IS::AIPath::canPlaceBomb(Vector3 ai)
{
    int x = (ai.x + 4) / 10;
    int y = (ai.z + 4) / 10;
    IS::Bomberman *b = getNearestBomberman(ai);

    if (Vector3Distance(b->getPosition(), ai) <= 10.0) {
        return true;
    } else if (IS::GLOBAL::_map->getElement(x + 1, y) == IS::MAP_TILES::CRATE) {
        return true;
    } else if (IS::GLOBAL::_map->getElement(x - 1, y) == IS::MAP_TILES::CRATE) {
        return true;
    } else if (IS::GLOBAL::_map->getElement(x, y + 1) == IS::MAP_TILES::CRATE) {
        return true;
    } else if (IS::GLOBAL::_map->getElement(x, y - 1) == IS::MAP_TILES::CRATE) {
        return true;
    }
    return false;
}

IS::actionPlayer_t IS::AIPath::getAIMove(IS::Bomberman *ai, int maxBomb, int nbBomb)
{
    IS::AIPath instance;
    Vector3 v = ai->getVelocity();
    v.x *= 5;
    v.y *= 5;
    v.z *= 5;
    Vector3 velocity = instance.move(ai->getPosition(), v);
    IS::actionPlayer_t action;

    action.dropBomb = false;
    action.moveDown = false;
    action.moveLeft = false;
    action.moveRight = false;
    action.moveUp = false;

    if (velocity.x == -1 && velocity.y == -1 && velocity.z == -1) {
        if (instance.canPlaceBomb(ai->getPosition()) && nbBomb == maxBomb) {
            action.dropBomb = true;
        }
    } else {
        if (velocity.x == 1) {
            action.moveRight = true;
        } else if (velocity.x == -1) {
            action.moveLeft = true;
        } else if (velocity.z == 1) {
            action.moveDown = true;
        } else if (velocity.z == -1) {
            action.moveUp = true;
        }
    }
    return action;
}

IS::AIPath::~AIPath()
{
}
