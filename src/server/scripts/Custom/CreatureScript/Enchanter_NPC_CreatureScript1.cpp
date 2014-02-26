#include "ScriptPCH.h"

class Enchanter_NPC_CreatureScript1 : public CreatureScript
{
public:
	Enchanter_NPC_CreatureScript1() : CreatureScript("Enchanter_NPC_CreatureScript1") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->ADD_GOSSIP_ITEM(5, "Main-Hand Weapon.", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(5, "Off-Hand Weapon.", GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(5, "Two-Handed  Weapon.", GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(5, "Ranged  Weapon.", GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(5, "Shield.", GOSSIP_SENDER_MAIN, 5);
        player->ADD_GOSSIP_ITEM(5, "Head.", GOSSIP_SENDER_MAIN, 6);
        player->ADD_GOSSIP_ITEM(5, "Shoulders.", GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(5, "Cloak.", GOSSIP_SENDER_MAIN, 8);
        player->ADD_GOSSIP_ITEM(5, "Chest.", GOSSIP_SENDER_MAIN, 9);
        player->ADD_GOSSIP_ITEM(5, "Bracers.", GOSSIP_SENDER_MAIN, 10);
        player->ADD_GOSSIP_ITEM(5, "Gloves.", GOSSIP_SENDER_MAIN, 11);
        player->ADD_GOSSIP_ITEM(5, "Belt.", GOSSIP_SENDER_MAIN, 12);
        player->ADD_GOSSIP_ITEM(5, "Legs.", GOSSIP_SENDER_MAIN, 13);
        player->ADD_GOSSIP_ITEM(5, "Feet.", GOSSIP_SENDER_MAIN, 14);
        if (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) == 450)
            player->ADD_GOSSIP_ITEM(5, "Rings.", GOSSIP_SENDER_MAIN, 15);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
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
                if (!player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    return false;
                }

                player->ADD_GOSSIP_ITEM(5, "Titanium Weapon Chain.", GOSSIP_SENDER_MAIN, 1337);
                player->ADD_GOSSIP_ITEM(5, "Berserking.", GOSSIP_SENDER_MAIN, 104);
                player->ADD_GOSSIP_ITEM(5, "Black Magic.", GOSSIP_SENDER_MAIN, 106);
                player->ADD_GOSSIP_ITEM(5, "Mighty Spellpower.", GOSSIP_SENDER_MAIN, 112);
                player->ADD_GOSSIP_ITEM(5, "Superior Potency.", GOSSIP_SENDER_MAIN, 111);
                player->ADD_GOSSIP_ITEM(5, "Accuracy.", GOSSIP_SENDER_MAIN, 105);
                player->ADD_GOSSIP_ITEM(5, "Exceptional Agility.", GOSSIP_SENDER_MAIN, 100);
                player->ADD_GOSSIP_ITEM(5, "Exceptional Spirit.", GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(5, "Mongoose.", GOSSIP_SENDER_MAIN, 113);
                player->ADD_GOSSIP_ITEM(5, "Executioner.", GOSSIP_SENDER_MAIN, 114);
                player->ADD_GOSSIP_ITEM(5, "Blade Ward.", GOSSIP_SENDER_MAIN, 102);
                player->ADD_GOSSIP_ITEM(5, "Blood Draining.", GOSSIP_SENDER_MAIN, 103);
                player->ADD_GOSSIP_ITEM(5, "Battlemaster.", GOSSIP_SENDER_MAIN, 107);
                player->ADD_GOSSIP_ITEM(5, "Icebreaker.", GOSSIP_SENDER_MAIN, 108);
                player->ADD_GOSSIP_ITEM(5, "Lifeward.", GOSSIP_SENDER_MAIN, 109);
                player->ADD_GOSSIP_ITEM(7, "Back!", GOSSIP_SENDER_MAIN, 300);
                player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
                break;

            case 2:
                if (!player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND) && player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND)->GetTemplate()->InventoryType == INVTYPE_WEAPON)
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    return false;
                }

                player->ADD_GOSSIP_ITEM(5, "Titanium Weapon Chain.", GOSSIP_SENDER_MAIN, 1337);
                player->ADD_GOSSIP_ITEM(5, "Berserking.", GOSSIP_SENDER_MAIN, 104);
                player->ADD_GOSSIP_ITEM(5, "Black Magic.", GOSSIP_SENDER_MAIN, 106);
                player->ADD_GOSSIP_ITEM(5, "Mighty Spellpower.", GOSSIP_SENDER_MAIN, 112);
                player->ADD_GOSSIP_ITEM(5, "Superior Potency.", GOSSIP_SENDER_MAIN, 111);
                player->ADD_GOSSIP_ITEM(5, "Accuracy.", GOSSIP_SENDER_MAIN, 105);
                player->ADD_GOSSIP_ITEM(5, "Exceptional Agility.", GOSSIP_SENDER_MAIN, 100);
                player->ADD_GOSSIP_ITEM(5, "Exceptional Spirit.", GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(5, "Mongoose.", GOSSIP_SENDER_MAIN, 113);
                player->ADD_GOSSIP_ITEM(5, "Executioner.", GOSSIP_SENDER_MAIN, 114);
                player->ADD_GOSSIP_ITEM(5, "Blade Ward.", GOSSIP_SENDER_MAIN, 102);
                player->ADD_GOSSIP_ITEM(5, "Blood Draining.", GOSSIP_SENDER_MAIN, 103);
                player->ADD_GOSSIP_ITEM(5, "Battlemaster.", GOSSIP_SENDER_MAIN, 107);
                player->ADD_GOSSIP_ITEM(5, "Icebreaker.", GOSSIP_SENDER_MAIN, 108);
                player->ADD_GOSSIP_ITEM(5, "Lifeward.", GOSSIP_SENDER_MAIN, 109);
                player->ADD_GOSSIP_ITEM(7, "Back!", GOSSIP_SENDER_MAIN, 300);
                player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
                break;

            case 3:
                if (!player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND) && !player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND)->GetTemplate()->InventoryType == (INVTYPE_2HWEAPON))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    return false;
                }

                player->ADD_GOSSIP_ITEM(5, "Greater Spellpower", GOSSIP_SENDER_MAIN, 115);
                player->ADD_GOSSIP_ITEM(5, "Major Agility", GOSSIP_SENDER_MAIN, 116);
                player->ADD_GOSSIP_ITEM(5, "Massacre", GOSSIP_SENDER_MAIN, 117);
                player->ADD_GOSSIP_ITEM(7, "Back!", GOSSIP_SENDER_MAIN, 300);
                player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;

            case 11:
                break;

            case 12:
                break;

            case 13:
                break;

            case 14:
                break;

            case 15:
                break;

            default:
                break;










                /*

			case 4: // Ranged Weapon.
                if (player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED) && player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED)->GetTemplate()->InventoryType == INVTYPE_RANGED)
                {
                    player->ADD_GOSSIP_ITEM(5, "Sun Scope", GOSSIP_SENDER_MAIN, 307);
                    player->ADD_GOSSIP_ITEM(7, "Back!", GOSSIP_SENDER_MAIN, 300);
                    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                    return true;
                }
				break;

			case 307: // Sun Scope.
                if (player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED) && player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED)->GetTemplate()->InventoryType == INVTYPE_RANGED)
                {
                    player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED)->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
                    player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED)->SetEnchantment(PERM_ENCHANTMENT_SLOT, 3607, 0, 0);
                    player->GetSession()->SendNotification("Succesfully enchanted!");
                }
                player->PlayerTalkClass->SendCloseGossip();
                break;

			case 300: //<-Back menu
                player->ADD_GOSSIP_ITEM(5, "Main-Hand Weapon.", GOSSIP_SENDER_MAIN, 1);
                player->ADD_GOSSIP_ITEM(5, "Off-Hand Weapon.", GOSSIP_SENDER_MAIN, 2);
                player->ADD_GOSSIP_ITEM(5, "Two-Handed  Weapon.", GOSSIP_SENDER_MAIN, 3);
                player->ADD_GOSSIP_ITEM(5, "Ranged  Weapon.", GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM(5, "Shield.", GOSSIP_SENDER_MAIN, 5);
                player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
				break;
                */
			}

		}
		return true;
	}
};

void AddSC_Enchanter_NPC_CreatureScript1()
{
    new Enchanter_NPC_CreatureScript1();
};