#pragma once
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Sprite.h"

class ButtonGame : public GameEngine
{
private:
    Sprite* testImage{};
    
public:
    explicit ButtonGame();
    ~ButtonGame();

    void Init() override;
    void Update() override;
    void Render() override;

};
