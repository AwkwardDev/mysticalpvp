#include "ScriptPCH.h"

class Choose_Gear_NPC_CreatureScript : public CreatureScript
{
public:
    Choose_Gear_NPC_CreatureScript() : CreatureScript("Choose_Gear_NPC_CreatureScript") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/INV_Misc_Wrench_01:26|t I'd like to gear my character manually.", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/Trade_Engineering:26|t I'd like to use the premade character feature.", GOSSIP_SENDER_MAIN, 2);
        player->PlayerTalkClass->SendGossipMenu(creature->GetEntry(), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (sender == GOSSIP_SENDER_MAIN)
        {
            switch (action)
            {
            case 1:
                creature->MonsterWhisper("An error occurred while displaying the previous error.", player->GetGUID());
                player->PlayerTalkClass->SendCloseGossip();
                break;
            case 2:
                creature->MonsterWhisper("An error occurred while displaying the previous error.", player->GetGUID());
                player->PlayerTalkClass->SendCloseGossip();
                break;
            default:
                creature->MonsterWhisper("An error occurred while displaying the previous error.", player->GetGUID());
                player->PlayerTalkClass->SendCloseGossip();
                break;
            }
        }
        return true;
    }
};

void AddSC_Choose_Gear_NPC_CreatureScript()
{
    new Choose_Gear_NPC_CreatureScript();
}