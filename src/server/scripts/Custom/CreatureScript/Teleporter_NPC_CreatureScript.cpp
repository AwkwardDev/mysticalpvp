#include "ScriptPCH.h"

class Teleporter_NPC_CreatureScript : public CreatureScript
{
public:
	Teleporter_NPC_CreatureScript() : CreatureScript("Teleporter_NPC_CreatureScript") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gurubashi Arena.", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Dueling Zone.", GOSSIP_SENDER_MAIN, 3);
        if (player->GetSession()->GetSecurity() == SEC_PREMIUM)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Premium Mall.", GOSSIP_SENDER_MAIN, 2);
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
			case 1: // Gurubashi Arena.
				switch (player->GetTeam())
				{
				case ALLIANCE:
					player->TeleportTo(0, -13249.253906f, -82.411629f, 19.811203f, 1.523279f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				case HORDE:
					player->TeleportTo(0, -13534.602539f, 85.299316f, 28.701979f, 6.278640f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				}
				break;
			case 2: // Premium Mall.
                player->TeleportTo(1, 1816.051392f, -1282.034302f, 139.040390f, 3.718611f);
				player->PlayerTalkClass->SendCloseGossip();
				break;

            case 3: // Dueling Zone.
                player->TeleportTo(1, 6457.238281f, -4244.459473f, 667.190369f, 1.446752f);
                player->PlayerTalkClass->SendCloseGossip();
                break;
			}
		}
		return true;
	}
};

void AddSC_Teleporter_NPC_CreatureScript()
{
	new Teleporter_NPC_CreatureScript();
}