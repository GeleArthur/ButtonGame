#pragma once
#include "../GameEngine/GameEngine.h"

class ButtonGame : public GameEngine
{
private:
    
public:
    explicit ButtonGame();
    ~ButtonGame();

    void Update() override;
    void Render() override;
};
