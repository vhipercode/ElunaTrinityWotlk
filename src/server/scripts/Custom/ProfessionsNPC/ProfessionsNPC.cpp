#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "Common.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "Battleground.h"
#include "Chat.h"
#include "Player.h"
#include "Pet.h"
#include "BattlegroundQueue.h"
#include "Log.h"
#include "CharacterDatabase.h"
#include "DatabaseWorker.h"
#include "MapManager.h"
#include "Player.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "DBCStores.h"
#include "ScriptedGossip.h"
#include "GossipDef.h"
#include "Player.h"
#include "WorldSession.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"


enum professionmenu
{
    OPTION_TAILORING,
    OPTION_JEWELCRAFTING,
    OPTION_ENGINEERING,
    OPTION_BLACKSMITHING,
    OPTION_ALCHEMY,
    OPTION_INSCRIPTION,
    OPTION_ENCHANTING,
    OPTION_LEATHERWORKING,
    OPTION_COOKING,
    OPTION_FIRST_AID,
    OPTION_MAIN_MENU,

    SORT_TAILORING = 0,
    SORT_JEWELCRAFTING,
    SORT_ENGINEERING,
    SORT_BLACKSMITHING,
    SORT_ALCHEMY,
    SORT_INSCRIPTION,
    SORT_ENCHANTING,
    SORT_LEATHERWORKING,
    SORT_COOKING,
    SORT_FIRST_AID,

    TEXT_PROFESSION_MAIN = 50020,
    ACTION_LEARN_PROFESSION,
    ACTION_PURCHASE_MATERIALS,
};

class npc_professions : public CreatureScript
{
public:
    npc_professions() : CreatureScript("npc_professions") { } // to alliance from horde
    class TrintyRetardsAI : public ScriptedAI
    {
    public:
        TrintyRetardsAI(Creature* creature) : ScriptedAI(creature) {}
        
        bool GossipHello(Player* player) override
        {
            return OnGossipHello(player, me);
        }
        
        bool GossipSelect(Player* player, uint32 /*menu_id*/, uint32 gossipListId) override
        {
            uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            return OnGossipSelect(player, me, sender, action);
        }
        
    bool OnGossipHello(Player* player, Creature* creature)
    {
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Tailoring", GOSSIP_SENDER_MAIN, OPTION_TAILORING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Jewelcrafting", GOSSIP_SENDER_MAIN, OPTION_JEWELCRAFTING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Engineering", GOSSIP_SENDER_MAIN, OPTION_ENGINEERING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Blacksmithing", GOSSIP_SENDER_MAIN, OPTION_BLACKSMITHING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Alchemy", GOSSIP_SENDER_MAIN, OPTION_ALCHEMY);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Inscription", GOSSIP_SENDER_MAIN, OPTION_INSCRIPTION);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Enchanting", GOSSIP_SENDER_MAIN, OPTION_ENCHANTING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Leatherworking", GOSSIP_SENDER_MAIN, OPTION_LEATHERWORKING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Cooking", GOSSIP_SENDER_MAIN, OPTION_COOKING);
        AddGossipItemFor(player, GOSSIP_ICON_TABARD, "First Aid", GOSSIP_SENDER_MAIN, OPTION_FIRST_AID);
        SendGossipMenuFor(player, TEXT_PROFESSION_MAIN, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (sender)
        {
            case GOSSIP_SENDER_MAIN:
                switch (action)
                {
                    case OPTION_TAILORING:
                        //if (player->HasSkill(SKILL_TAILORING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_fabric_linen_01:40:40:-18:0|tLearn the skill Tailoring", ACTION_LEARN_PROFESSION, SKILL_TAILORING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_fabric_linen_01:40:40:-18:0|tTailoring Materials", ACTION_PURCHASE_MATERIALS, SORT_TAILORING);
                        break;
                    case OPTION_JEWELCRAFTING:
                        //if (player->HasSkill(SKILL_JEWELCRAFTING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_jewelcrafting_nightseye_02:40:40:-18:0|tLearn the skill Jewelcrafting", ACTION_LEARN_PROFESSION, SKILL_JEWELCRAFTING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_jewelcrafting_nightseye_02:40:40:-18:0|tJewelcrafting Materials", ACTION_PURCHASE_MATERIALS, SORT_JEWELCRAFTING);
                        break;
                    case OPTION_ENGINEERING:
                        //if (player->HasSkill(SKILL_ENGINEERING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_gear_06:40:40:-18:0|tLearn the skill Engineering", ACTION_LEARN_PROFESSION, SKILL_ENGINEERING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_gear_06:40:40:-18:0|tEngineering Materials", ACTION_PURCHASE_MATERIALS, SORT_ENGINEERING);
                        break;
                    case OPTION_BLACKSMITHING:
                        //if (player->HasSkill(SKILL_BLACKSMITHING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_ingot_02:40:40:-18:0|tLearn the skill Blacksmithing", ACTION_LEARN_PROFESSION, SKILL_BLACKSMITHING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_ingot_02:40:40:-18:0|tBlacksmithing Materials", ACTION_PURCHASE_MATERIALS, SORT_BLACKSMITHING);
                        break;
                    case OPTION_ALCHEMY:
                        //if (player->HasSkill(SKILL_ALCHEMY))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_flower_02:40:40:-18:0|tLearn the skill Alchemy", ACTION_LEARN_PROFESSION, SKILL_ALCHEMY);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_flower_02:40:40:-18:0|tAlchemy Materials", ACTION_PURCHASE_MATERIALS, SORT_ALCHEMY);
                        break;
                    case OPTION_INSCRIPTION:
                        //if (player->HasSkill(SKILL_INSCRIPTION))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_inscription_papyrus:40:40:-18:0|tLearn the skill Inscription", ACTION_LEARN_PROFESSION, SKILL_INSCRIPTION);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_inscription_papyrus:40:40:-18:0|tInscription Materials", ACTION_PURCHASE_MATERIALS, SORT_INSCRIPTION);
                        break;
                    case OPTION_ENCHANTING:
                        //if (player->HasSkill(SKILL_ENCHANTING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_dust_infinite:40:40:-18:0|tLearn the skill Enchanting", ACTION_LEARN_PROFESSION, SKILL_ENCHANTING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_dust_infinite:40:40:-18:0|tEnchanting Materials", ACTION_PURCHASE_MATERIALS, SORT_ENCHANTING);
                        break;
                    case OPTION_LEATHERWORKING:
                        //if (player->HasSkill(SKILL_LEATHERWORKING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_leatherscrap_03:40:40:-18:0|tLearn the skill Leatherworking", ACTION_LEARN_PROFESSION, SKILL_LEATHERWORKING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_leatherscrap_03:40:40:-18:0|tLeatherworking Materials", ACTION_PURCHASE_MATERIALS, SORT_LEATHERWORKING);
                        break;
                    case OPTION_COOKING:
                        //if (player->HasSkill(SKILL_COOKING))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_food_16:40:40:-18:0|tLearn the skill Cooking", ACTION_LEARN_PROFESSION, SKILL_COOKING);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_food_16:40:40:-18:0|tCooking Materials", ACTION_PURCHASE_MATERIALS, SORT_COOKING);
                        break;
                    case OPTION_FIRST_AID:
                        //if(player->HasSkill(SKILL_FIRST_AID))
                            AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_bandage_15:40:40:-18:0|tLearn the skill First Aid", ACTION_LEARN_PROFESSION, SKILL_FIRST_AID);
                        //AddGossipItemFor(player, GOSSIP_ICON_TABARD,"|TInterface/ICONS/inv_misc_bandage_15:40:40:-18:0|tFirst Aid Materials", ACTION_PURCHASE_MATERIALS, SORT_FIRST_AID);
                        break;
                    case OPTION_MAIN_MENU:
                        OnGossipHello(player, creature);
                        SendGossipMenuFor(player, TEXT_PROFESSION_MAIN, creature->GetGUID());
                        return true;
                }
                AddGossipItemFor(player, GOSSIP_ICON_TABARD,"Back", GOSSIP_SENDER_MAIN, OPTION_MAIN_MENU);
                SendGossipMenuFor(player, TEXT_PROFESSION_MAIN, creature->GetGUID());
                break;
            case ACTION_LEARN_PROFESSION:
                if (!CheckSkill(player, action))
                {
                    player->GetSession()->SendNotification("You already have two professions or already know this skill");
                    OnGossipHello(player, creature);
                    break;
                }
                HandleLearnSkillRecipesHelper(player, action);
                player->SetSkill(action, player->GetSkillStep(action), 450, 450);
                break;

        }
        return true;
    }

    bool CheckSkill(Player* player, uint16 skill)
    {
        uint8 skillCount = 0;

        if (IsSecondary(skill))
            return true;

        if (player->HasSkill(SKILL_ALCHEMY))
            skillCount++;

        if (player->HasSkill(SKILL_BLACKSMITHING))
            skillCount++;

        if (player->HasSkill(SKILL_ENCHANTING))
            skillCount++;

        if (player->HasSkill(SKILL_ENGINEERING))
            skillCount++;

        if (player->HasSkill(SKILL_HERBALISM))
            skillCount++;

        if (player->HasSkill(SKILL_INSCRIPTION))
            skillCount++;

        if (player->HasSkill(SKILL_JEWELCRAFTING))
            skillCount++;

        if (player->HasSkill(SKILL_LEATHERWORKING))
            skillCount++;

        if (player->HasSkill(SKILL_TAILORING))
            skillCount++;

        if (skillCount > 1)
            return false;

        return true;
    }

    bool IsSecondary(uint16 skill)
    {
        switch (skill)
        {
            case SKILL_COOKING:
            case SKILL_FIRST_AID:
            case SKILL_FISHING:
                return true;
            default:
                return false;
        }
    }

    void HandleLearnSkillRecipesHelper(Player* player, uint32 skillId)
    {
        uint32 classmask = player->getClassMask();

        for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
        {
            SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(j);
            if (!skillLine)
                continue;

            // wrong skill
            if (skillLine->skillId != skillId)
                continue;

            // not high rank
            if (skillLine->forward_spellid)
                continue;

            // skip racial skills
            if (skillLine->racemask != 0)
                continue;

            // skip wrong class skills
            if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->spellId);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo))
                continue;

            player->LearnSpell(skillLine->spellId, false);
        }
    }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return  new TrintyRetardsAI(creature);
        }
};

void AddSC_ProfessionsNPC()
{
    new npc_professions();
}
