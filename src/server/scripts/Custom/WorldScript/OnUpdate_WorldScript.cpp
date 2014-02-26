#include "ScriptPCH.h"

class OnUpdate_WorldScript : public WorldScript
{
public:
    OnUpdate_WorldScript() : WorldScript("OnUpdate_PlayerScript") { }

    void OnUpdate(uint32 /*diff*/)
    {
    }
};

void AddSC_OnUpdate_WorldScript()
{
    new OnUpdate_WorldScript();
}
