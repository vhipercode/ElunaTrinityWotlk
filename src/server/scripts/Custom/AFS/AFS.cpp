#include "ScriptPCH.h"
#include "ScriptedGossip.h"
#include "GameObjectAI.h"
#include "Battleground.h"
#include "Player.h"
#include "WorldSession.h"
#include <cstring>
#include <string.h>

class FastArenaCrystal : public GameObjectScript
{
    public:
        FastArenaCrystal() : GameObjectScript("FastArenaCrystal"){}

        class TrintyRetardsAI : public GameObjectAI
        {
        public:
            TrintyRetardsAI(GameObject* go) : GameObjectAI(go) {}
            
        
        bool GossipHello(Player* player) override
        {
            return OnGossipHello(player, me);
        }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Battleground *bg = player->GetBattleground())
                if (bg->isArena())
					player->GetSession()->SendNotification("Players clicked: %u", bg->ClickFastStart(player, go));
            return false;
        }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return  new TrintyRetardsAI(go);
        }
};

void AddSC_AFS()
{
    new FastArenaCrystal();
}
