#include "ScriptPCH.h"

class OnLogin_PlayerScript : public PlayerScript
{
public:
    OnLogin_PlayerScript() : PlayerScript("OnLogin_PlayerScript") { }

    void OnLogin(Player * player)
    {
    }
};

void AddSC_OnLogin_PlayerScript()
{
    new OnLogin_PlayerScript();
}
