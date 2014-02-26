#include "ScriptPCH.h"

class OnDuel_PlayerScript : public PlayerScript
{
public:
    OnDuel_PlayerScript() : PlayerScript("OnDuel_PlayerScript") { }

    void OnDuelRequest(Player * requester, Player * requested)
    {
        //smth
    }

    void OnDuelStart(Player * winner, Player * loser)
    {
        if (winner->getPowerType() == POWER_ENERGY)
            winner->SetPower(POWER_ENERGY, winner->GetMaxPower(POWER_ENERGY));
        if (winner->getPowerType() == POWER_RAGE)
            winner->SetPower(POWER_RAGE, 0);
    }

    void OnDuelEnd(Player * winner, Player * loser, DuelCompleteType /*type*/)
    {
        winner->AttackStop();
        winner->CastStop();
        winner->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
        winner->RemoveArenaSpellCooldowns();
        winner->SetHealth(winner->GetMaxHealth());
        if (winner->getPowerType() == POWER_MANA)
            winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
        loser->AttackStop();
        loser->CastStop();
        loser->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
        loser->RemoveArenaSpellCooldowns();
        loser->SetHealth(loser->GetMaxHealth());
        if (loser->getPowerType() == POWER_MANA)
            loser->SetPower(POWER_MANA, loser->GetMaxPower(POWER_MANA));
    }
};

void AddSC_OnDuel_PlayerScript()
{
    new OnDuel_PlayerScript();
}
