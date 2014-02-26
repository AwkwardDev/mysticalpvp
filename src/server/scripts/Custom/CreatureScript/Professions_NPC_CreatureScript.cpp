#include "ScriptPCH.h"

class Professions_NPC_CreatureScript : public CreatureScript
{
public:
    Professions_NPC_CreatureScript () : CreatureScript("Professions_NPC_CreatureScript") {}
    
    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Alchemy:26|t Alchemy.", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_BlackSmithing:26|t Blacksmithing.", GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/INV_Misc_ArmorKit_17:26|t Leatherworking.", GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Tailoring:26|t Tailoring.", GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Engineering:26|t Engineering.", GOSSIP_SENDER_MAIN, 5);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Engraving:26|t Enchanting.", GOSSIP_SENDER_MAIN, 6);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/INV_Misc_Gem_02:26|t Jewelcrafting.", GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/INV_Inscription_Tradeskill01:26|t Inscription.", GOSSIP_SENDER_MAIN, 8);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Herbalism:26|t Herbalism.", GOSSIP_SENDER_MAIN, 9);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/INV_Misc_Pelt_Wolf_01:26|t Skinning.", GOSSIP_SENDER_MAIN, 10);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Mining:26|t Mining.", GOSSIP_SENDER_MAIN, 11);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Trade_Fishing:26|t Fishing.", GOSSIP_SENDER_MAIN, 12);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Spell_Holy_SealOfSacrifice:26|t First Aid.", GOSSIP_SENDER_MAIN, 13);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/INV_Misc_Food_15:26|t Cooking.", GOSSIP_SENDER_MAIN, 14);
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
            case 1: // Alchemy.
                if (player->HasSkill(SKILL_ALCHEMY))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->AddItem(47499, 1); // Flask of the North.

                player->learnSpell(2259, true); // Apprentice Alchemy.
                player->learnSpell(3101, true); // Journeyman Alchemy.
                player->learnSpell(3464, true); // Expert Alchemy.
                player->learnSpell(11611, true); // Artisan Alchemy.
                player->learnSpell(28596, true); // Master Alchemy.
                player->learnSpell(51304, true); // Grand Master Alchemy.
                player->SetSkill(171, player->GetSkillStep(171), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 2: // Blacksmithing.
                if (player->HasSkill(SKILL_BLACKSMITHING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                /*
                Possibly make the player cast the do sockets spells on himself (the items), or
                use a direct function to add the enchants, since they don't work if you don't know blacksmithing.
                Temporary way used below.
                */

                player->SummonGameObject(194488, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), 0, 0, std::sin(player->GetOrientation() / 2), std::cos(player->GetOrientation() / 2), 180); // Anvil.
                creature->MonsterWhisper("Anvil spawned temporarily at your location for three minutes.", player->GetGUID());
                player->AddItem(36913, 8); // Saronite Bar.
                player->AddItem(35627, 1); // Eternal Shadow.
                player->AddItem(35624, 1); // Eternal Earth.
                player->AddItem(5956, 1); // Blacksmithing Hammer.
                player->learnSpell(55628, true); // Socket Bracer.
                player->learnSpell(55641, true); // Socket Gloves.

                player->learnSpell(2018, true); // Apprentice Blacksmithing.
                player->learnSpell(3100, true); // Journeyman Blacksmithing.
                player->learnSpell(3538, true); // Expert Blacksmithing.
                player->learnSpell(9785, true); // Artisan Blacksmithing.
                player->learnSpell(20844, true); // Master Blacksmithing.
                player->learnSpell(51300, true); // Grand Master Blacksmithing.
                player->SetSkill(164, player->GetSkillStep(164), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 3: // Leatherworking.
                if (player->HasSkill(SKILL_LEATHERWORKING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(2108, true); // Apprentice Leatherworking.
                player->learnSpell(3104, true); // Journeyman Leatherworking.
                player->learnSpell(3811, true); // Expert Leatherworking.
                player->learnSpell(10662, true); // Artisan Leatherworking.
                player->learnSpell(32549, true); // Master Leatherworking.
                player->learnSpell(51302, true); // Grand Master Leatherworking.
                player->SetSkill(165, player->GetSkillStep(165), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 4: // Tailoring.
                if (player->HasSkill(SKILL_TAILORING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(3908, true); // Apprentice Tailoring.
                player->learnSpell(3909, true); // Journeyman Tailoring.
                player->learnSpell(3910, true); // Expert Tailoring.
                player->learnSpell(12180, true); // Artisan Tailoring.
                player->learnSpell(26790, true); // Master Tailoring.
                player->learnSpell(51309, true); // Grand Master Tailoring.
                player->SetSkill(197, player->GetSkillStep(197), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 5: // Engineering.
                if (player->HasSkill(SKILL_ENGINEERING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(4036, true); // Apprentice Engineering.
                player->learnSpell(4037, true); // Journeyman Engineering.
                player->learnSpell(4038, true); // Expert Engineering.
                player->learnSpell(12656, true); // Artisan Engineering.
                player->learnSpell(30350, true); // Master Engineering.
                player->learnSpell(51306, true); // Grand Master Engineering.
                player->SetSkill(202, player->GetSkillStep(202), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 6: // Enchanting.
                if (player->HasSkill(SKILL_ENCHANTING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(7411, true); // Apprentice Enchanting.
                player->learnSpell(7412, true); // Journeyman Enchanting.
                player->learnSpell(7413, true); // Expert Enchanting.
                player->learnSpell(13920, true); // Artisan Enchanting.
                player->learnSpell(28029, true); // Master Enchanting.
                player->learnSpell(51313, true); // Grand Master Enchanting.
                player->SetSkill(333, player->GetSkillStep(333), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 7: // Jewelcrafting.
                if (player->HasSkill(SKILL_JEWELCRAFTING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(25230, true); // Apprentice Jewelcrafting.
                player->learnSpell(28894, true); // Journeyman Jewelcrafting.
                player->learnSpell(28895, true); // Expert Jewelcrafting.
                player->learnSpell(28897, true); // Artisan Jewelcrafting.
                player->learnSpell(51311, true); // Master Jewelcrafting.
                player->learnSpell(31252, true); // Prospecting.
                player->SetSkill(755, player->GetSkillStep(755), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 8: // Incsription.
                if (player->HasSkill(SKILL_INSCRIPTION))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(45358, true); // Apprentice Incsription.
                player->learnSpell(45359, true); // Journeyman Incsription.
                player->learnSpell(45360, true); // Expert Incsription.
                player->learnSpell(45361, true); // Artisan Incsription.
                player->learnSpell(45363, true); // Master Incsription.
                player->learnSpell(51005, true); // Milling.
                player->SetSkill(773, player->GetSkillStep(773), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 9: // Herbalism.
                if (player->HasSkill(SKILL_HERBALISM))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(2383, true); // Find Herbs.
                player->learnSpell(2366, true); // Apprentice Herbalism.
                player->learnSpell(2368, true); // Journeyman Herbalism.
                player->learnSpell(3570, true); // Expert Skinning.
                player->learnSpell(11993, true); // Artisan Herbalism.
                player->learnSpell(28695, true); // Master Herbalism.
                player->learnSpell(50300, true); // Grand Master Herbalism.
                player->SetSkill(182, player->GetSkillStep(182), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 10: // Skinning.
                if (player->HasSkill(SKILL_SKINNING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(8613, true); // Apprentice Skinning.
                player->learnSpell(8617, true); // Journeyman Skinning.
                player->learnSpell(8618, true); // Expert Skinning.
                player->learnSpell(10768, true); // Artisan Skinning.
                player->learnSpell(50305, true); // Master Skinning.
                player->SetSkill(393, player->GetSkillStep(393), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 11: // Mining.
                if (player->HasSkill(SKILL_MINING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                if (HasTwoProfessionsAlready(player))
                {
                    creature->MonsterWhisper("You can only have two professions.", player->GetGUID());
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(2580, true); // Find Minerals.
                player->learnSpell(2656, true); // Smelting.
                player->learnSpell(2575, true); // Apprentice Mining.
                player->learnSpell(2576, true); // Journeyman Mining.
                player->learnSpell(3564, true); // Expert Mining.
                player->learnSpell(10248, true); // Artisan Mining.
                player->learnSpell(29354, true); // Master Mining.
                player->learnSpell(50310, true); // Grand Master Mining.
                player->SetSkill(186, player->GetSkillStep(186), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 12: // Fishing.
                if (player->HasSkill(SKILL_FISHING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(7620, true); // Apprentice Fishing.
                player->learnSpell(7731, true); // Journeyman Fishing.
                player->learnSpell(7732, true); // Expert Fishing.
                player->learnSpell(18248, true); // Artisan Fishing.
                player->learnSpell(33095, true); // Master Fishing.
                player->learnSpell(51294, true); // Grand Master Fishing.
                player->learnSpell(43308, true); // Find Fish.
                player->SetSkill(356, player->GetSkillStep(356), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            case 13: // First Aid.
                if (player->HasSkill(SKILL_FIRST_AID))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(3273, true); // Apprentice First Aid.
                player->learnSpell(3274, true); // Journeyman First Aid.
                player->learnSpell(7924, true); // Expert First Aid.
                player->learnSpell(10846, true); // Artisan First Aid.
                player->learnSpell(27028, true); // Master First Aid.
                player->learnSpell(45542, true); // Grand Master First Aid.
                player->SetSkill(129, player->GetSkillStep(129), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;
            case 14:
                if (player->HasSkill(SKILL_COOKING))
                {
                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                }

                player->learnSpell(2550, true); // Apprentice Cooking.
                player->learnSpell(3102, true); // Journeyman Cooking.
                player->learnSpell(3413, true); // Expert Cooking.
                player->learnSpell(18260, true); // Artisan Cooking.
                player->learnSpell(33359, true); // Master Cooking.
                player->learnSpell(51296, true); // Grand Master Cooking.
                player->SetSkill(185, player->GetSkillStep(185), 450, 450);
                player->PlayerTalkClass->SendCloseGossip();
                break;

            }
        }
        return true;
    }

    bool HasTwoProfessionsAlready(const Player *player) const
    {
        uint32 amount = 0;

        if (player->HasSkill(SKILL_ALCHEMY))
            amount++;

        if (player->HasSkill(SKILL_BLACKSMITHING))
            amount++;

        if (player->HasSkill(SKILL_LEATHERWORKING))
            amount++;

        if (player->HasSkill(SKILL_TAILORING))
            amount++;

        if (player->HasSkill(SKILL_ENGINEERING))
            amount++;

        if (player->HasSkill(SKILL_JEWELCRAFTING))
            amount++;

        if (player->HasSkill(SKILL_INSCRIPTION))
            amount++;

        if (player->HasSkill(SKILL_MINING))
            amount++;

        if (player->HasSkill(SKILL_SKINNING))
            amount++;

        if (player->HasSkill(SKILL_HERBALISM))
            amount++;

        if (amount >= 2)
            return true;
        else
            return false;
    }
};

void AddSC_Professions_NPC_CreatureScript()
{
    new Professions_NPC_CreatureScript();
}