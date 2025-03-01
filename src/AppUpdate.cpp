#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }


    if(Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x, m_Giraffe->GetPosition().y - 1});
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT)){
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x-1, m_Giraffe->GetPosition().y});
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::UP)){
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x, m_Giraffe->GetPosition().y+1});
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x+1, m_Giraffe->GetPosition().y});
    }
    if(m_Giraffe->IfCollides(m_Chest)) {
        m_Chest->SetVisible(false);
    }
    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    if(m_Phase == Phase::BEE_ANIMATION) {
        m_Bee->SetLooping(true);
        m_Bee->update();
    }
    for(int i = 0;i <= 2;i++) {
        if(m_Giraffe->IfCollides(m_Doors[i])) {
            m_Doors[i]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
    }
    if(m_Phase == Phase::COUNTDOWN) {
        m_Ball->SetLooping(true);
        m_Ball->update();
        m_Ball->
    }

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
