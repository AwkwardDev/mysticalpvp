#include "ScriptPCH.h"
#include "Group.h"

int32 GetWarriorShout(Player* player)
{
    QueryResult result = CharacterDatabase.PQuery("SELECT `battle_shout`, `commanding_shout` FROM `custom_buffs` WHERE  `guid`=%u", player->GetGUID());
    if (!result)
        return 47440; // Commanding Shout.

    if (result)
    {
        do
        {
            Field * field = result->Fetch();
            if (field[0].GetUInt32() == 1)
                return 47436; // Battle Shout.
            if (field[1].GetUInt32() == 1)
                return 47440; // Commanding Shout.
        } while (result->NextRow());
    }
    return 47440; // Commanding Shout.
}

int32 GetShamanWeaponImbue(Player* player)
{
    QueryResult result = CharacterDatabase.PQuery("SELECT `earthliving_weapon`, `flametongue_weapon`, `frostbrand_weapon`, `rockbiter_weapon`, `windfury_weapon` FROM `custom_buffs` WHERE  `guid`=%u", player->GetGUID());
    if (!result)
        return 1;

    if (result)
    {
        do
        {
            uint32 imbue = 0;
            Field * field = result->Fetch();
            // Earthliving Weapon.
            if (field[0].GetUInt32() == 1)
                imbue = imbue + 1; // Main-Hand.
            if (field[0].GetUInt32() == 2)
                imbue = imbue + 3; // Off-Hand.

            // Flametongue Weapon.
            if (field[1].GetUInt32() == 1)
                imbue = imbue + 7; // Main-Hand..
            if (field[1].GetUInt32() == 2)
                imbue = imbue + 15; // Off-Hand.

            // Frostbrand Weapon.
            if (field[2].GetUInt32() == 1)
                imbue = imbue + 31; // Main-Hand..
            if (field[2].GetUInt32() == 2)
                imbue = imbue + 63; // Off-Hand.

            // Rockbiter Weapon.
            if (field[3].GetUInt32() == 1)
                imbue = imbue + 127; // Main-Hand.
            if (field[3].GetUInt32() == 2)
                imbue = imbue + 255; // Off-Hand.

            // Windfury Weapon.
            if (field[4].GetUInt32() == 1)
                imbue = imbue + 511; // Main-Hand..
            if (field[4].GetUInt32() == 2)
                imbue = imbue + 1023; // Off-Hand.

            return imbue;
        } while (result->NextRow());
    }
    return false;
}

// Prayer of Fortitude, Prayer of Shadow Protection, Prayer of Spirit.
uint32 Priest_Buffs[] = { 48162, 48170, 48074 };
// Gift of the Wild, Thorns.
uint32 Druid_Buffs[] = { 48470, 53307 };
// Detect Invisibility, Unending Breath.
uint32 Warlock_Buffs[] = { 132, 5697 };
// Arcane Brilliance.
uint32 Mage_Buffs[] = { 43002 };
// Water Breathing, Water Walking.
uint32 Shaman_Buffs[] = { 131, 546 };
// Horn of Winter, Path of Frost.
uint32 Death_Knight_Buffs[] = { 57623, 3714 };


class OnUpdateZone_PlayerScript : public PlayerScript
{
public:
    OnUpdateZone_PlayerScript() : PlayerScript("OnUpdateZone_PlayerScript") {  }
	
    void OnUpdateZone(Player* player, uint32 zone, uint32 area)
    {
        switch (zone)
        {
        case 3698: // Nagrand Arena.
        case 3702: // Blade's Edge Arena.
        case 4378: // Dalaran Arena.
        case 3968: // Ruins of Lordaeron.
        case 4406: // Ring of Valor.
        default:
            if (player->GetGroup())
            {
                Group* grp = player->GetGroup();
                for (GroupReference const* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    if (zone == itr->getSource()->GetZoneId())
                    {
                        if (itr->getSource()->getClass() == CLASS_WARRIOR)
                            for (int i = 0; i < 2; i++)
                            {
                                player->CastSpell(player, GetWarriorShout(player), true);
                                itr->getSource()->CastSpell(itr->getSource(), GetWarriorShout(player), true);
                            }

                        if (itr->getSource()->getClass() == CLASS_PALADIN)
                            for (int i = 0; i < 3; i++)
                            {
                                if (player->HasSpell(53595)) // Hammer of the Righteous.
                                {
                                    if (player->GetTeam() == ALLIANCE)
                                        player->CastSpell(player, 31801, true); // Seal of Vengeance.
                                    if (player->GetTeam() == HORDE)
                                        player->CastSpell(player, 53736, true); // Seal of Corruption.
                                    player->CastSpell(player, 15473, true); // Greater Blessing of Sanctuary.
                                }
                                if (player->HasSpell(53385)) // Divine Storm.
                                {
                                    player->CastSpell(player, 25898, true); // Greater Blessing of Kings.
                                    player->CastSpell(player, 20154, true); // Seal of Righteousness.
                                }
                                if (player->HasSpell(53563)) // Beacon of Light.
                                {
                                    player->CastSpell(player, 25898, true); // Greater Blessing of Kings.
                                    player->CastSpell(player, 20166, true); // Seal of Wisdom.
                                }
                                player->CastSpell(player, 25780, true); // Righteous Fury.
                                itr->getSource()->CastSpell(itr->getSource(), 25898, true); // Greater Blessing of Kings.
                            }
                        if (itr->getSource()->getClass() == CLASS_PRIEST)
                            for (int i = 0; i < 3; i++)
                            {
                                if (player->HasSpell(47585)) // Dispersion.
                                {
                                    player->CastSpell(player, 15473, true); // Shadowform.
                                    player->CastSpell(player, 15286, true); // Vampiric Embrace.
                                }
                                player->CastSpell(player, 48168, true); // Inner Fire.
                                player->CastSpell(player, Priest_Buffs[i], true);
                                itr->getSource()->CastSpell(itr->getSource(), Priest_Buffs[i], true);
                            }
                        if (itr->getSource()->getClass() == CLASS_DRUID)
                            for (int i = 0; i < 2; i++)
                            {
                                player->CastSpell(player, Druid_Buffs[i], true);
                                itr->getSource()->CastSpell(itr->getSource(), Druid_Buffs[i], true);
                            }
                        if (itr->getSource()->getClass() == CLASS_WARLOCK)
                            for (int i = 0; i < 2; i++)
                            {
                                player->CastSpell(player, Warlock_Buffs[i], true);
                                itr->getSource()->CastSpell(itr->getSource(), Warlock_Buffs[i], true);
                                switch (zone)
                                {
                                case 3698: // Nagrand Arena.
                                case 3702: // Blade's Edge Arena.
                                case 4378: // Dalaran Arena.
                                case 3968: // Ruins of Lordaeron.
                                case 4406: // Ring of Valor.
                                    // player->SummonGameObject(193061, x, y, z, ang, 0, 0, rot2, rot3, 30);
                                    break;
                                }
                            }
                        if (itr->getSource()->getClass() == CLASS_MAGE)
                            for (int i = 0; i < 1; i++)
                            {
                                player->CastSpell(player, Mage_Buffs[i], true);
                                itr->getSource()->CastSpell(itr->getSource(), Mage_Buffs[i], true);
                                switch (zone)
                                {
                                case 3698: // Nagrand Arena.
                                case 3702: // Blade's Edge Arena.
                                case 4378: // Dalaran Arena.
                                case 3968: // Ruins of Lordaeron.
                                case 4406: // Ring of Valor.
                                    // player->SummonGameObject(193061, x, y, z, ang, 0, 0, rot2, rot3, 30);
                                    break;
                                }
                            }
                        if (itr->getSource()->getClass() == CLASS_SHAMAN)
                            for (int i = 0; i < 2; i++)
                            {
                                /*if (GetShamanWeaponImbue(player))
                                {
                                    switch (GetShamanWeaponImbue(player))
                                    {
                                        /* Ids:
                                        * 3350 - Earthliving Weapon.
                                        * 3781 - Flametongue Weapon.
                                        * 3784 - Frostbrand Weapon.
                                        * 3021 - Rockbiter Weapon.
                                        * 3787 - Windfury Weapon.
                                                                            case 1: // Main-Hand Earthliving Weapon.
                                    case 3: // Off-Hand Earthliving Weapon.
                                    case 4: // Double Earthliving Weapon.
                                    case 7: // Main-Hand Flametongue Weapon.
                                    case 15: // Off-Hand Flametongue Weapon.
                                    case 16: // Main-Hand Earthliving Weapon & Off-Hand Flametongue Weapon.
                                    case 30: // Double Flametongue
                                    case 31: // Main-Hand Frostbrand Weapon.
                                    case 34: // Main-Hand Frostbrand Weapon & Off-Hand Earthliving Weapon.
                                    case 46: // mh fbw / oh flametong
                                    case 62: // double fbw
                                    case 63: // fbw oh
                                        break;

                                    }
                                }*/
                                if (player->HasSpell(61301)) // Riptide.
                                        player->CastSpell(player, 51994, true); // Water Shield.
                                    if (player->HasSpell(59159)) // Thunderstorm.
                                        player->CastSpell(player, 51994, true); // Water Shield.
                                    if (player->HasSpell(51533)) // Feral Spirit.
                                        player->CastSpell(player, 49281, true); // Lightning Shield.

                                    player->CastSpell(player, Shaman_Buffs[i], true);
                                    itr->getSource()->CastSpell(itr->getSource(), Shaman_Buffs[i], true);

                            }
                        if (itr->getSource()->getClass() == CLASS_DEATH_KNIGHT)
                            for (int i = 0; i < 2; i++)
                            {
                                player->CastSpell(player, 49222, true); // Bone Shield.
                                player->CastSpell(player, Death_Knight_Buffs[i], true);
                                itr->getSource()->CastSpell(itr->getSource(), Death_Knight_Buffs[i], true);
                            }
                    }
                }
            }
            break;
        }
    }
};

class OnUpdateZone_CommandScript : public CommandScript
{
public:
    OnUpdateZone_CommandScript() : CommandScript("OnUpdateZone_CommandScript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand HandleBuffWarriorForwardNextCommand[] =
        {
            { "battle",         SEC_PLAYER,   false,   &HandleBuffWarriorShoutBattleCommand,     "", NULL },
            { "commanding",     SEC_PLAYER,   false,   &HandleBuffWarriorShoutCommandingCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand HandleBuffWarriorForwardCommand[] =
        {
            { "shout",         SEC_PLAYER,    false,   NULL,      "", HandleBuffWarriorForwardNextCommand },
            { NULL,            0,             false,   NULL,                                     "", NULL }
        };

        static ChatCommand OnUpdateZone_CommandScriptTable[] =
        {
            { "warrior", SEC_PLAYER, false, NULL, "", HandleBuffWarriorForwardCommand },
        //    { "paladin", SEC_PLAYER, false, NULL, "", HandleBuffPaladinForwardCommand },
        //    { "mage", SEC_PLAYER, false, NULL, "", HandleBuffMageForwardCommand },
        //    { "warlock", SEC_PLAYER, false, NULL, "", HandleBuffWarlockForwardCommand },
        //    { "shaman", SEC_PLAYER, false, NULL, "", HandleBuffShamanForwardCommand },
            { NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand Table[] =
        {
            { "buffs", SEC_PLAYER, false, NULL, "", OnUpdateZone_CommandScriptTable },
            { NULL, 0, false, NULL, "", NULL }
        };
        return Table;  
    }
    
    static bool HandleBuffWarriorShoutBattleCommand(ChatHandler* handler, const char* args)
    {
        CharacterDatabase.PQuery("REPLACE INTO `custom_buffs` (`guid`, `battle_shout`) VALUES (%u, 1)", handler->GetSession()->GetPlayer()->GetGUID());
        handler->PSendSysMessage("Set Battle Shout to be cast on you when you enter arena or battleground.");
        return true;
    }

    static bool HandleBuffWarriorShoutCommandingCommand(ChatHandler* handler, const char* args)
    {
        CharacterDatabase.PQuery("REPLACE INTO `custom_buffs` (`guid`, `commanding_shout`) VALUES (%u, 1)", handler->GetSession()->GetPlayer()->GetGUID());
        handler->PSendSysMessage("Set Commanding Shout to be cast on you when you enter arena or battleground.");
        return true;
    }
};

void AddSC_OnUpdateZone_CommandScript()
{
    new OnUpdateZone_CommandScript;
}

void AddSC_OnUpdateZone_PlayerScript()
{
    new OnUpdateZone_PlayerScript;
}