modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		GetSnapHeliSettings();
		if (GetSnapHeliSettings().VirtualHelipads){
			if (GetSnapHeliSettings().VirtualHelipads.Count() > 0){
				for(int i = 0; i < GetSnapHeliSettings().VirtualHelipads.Count(); ++i){
					ref VirtualHelipad temp = new VirtualHelipad(GetSnapHeliSettings().VirtualHelipads.Get(i));
					temp.Init();
				}
			}
		}
	}
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		if ( identity )
		{
			string playerID = identity.GetPlainId();
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLaterByName(this, "SendSnapHeliToHeliPadSettings", 1500, false, new Param1<PlayerBase >( player ));
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLaterByName(this, "SendSnapHeliToHeliPadSettings", 3500, false, new Param1<PlayerBase >( player ));
		}
	}
			
	void SendSnapHeliToHeliPadSettings( PlayerBase player ){
		if (player.IsPlayerDisconnected()) { return; }
		PlayerIdentity identity = player.GetIdentity();
		if (identity){
			GetRPCManager().SendRPC("SHTHP", "RPCSnapHeliToHeliPadSettings", new Param1< SnapHeliSettings >( GetSnapHeliSettings() ), true, identity);
		}
	}
	
};

