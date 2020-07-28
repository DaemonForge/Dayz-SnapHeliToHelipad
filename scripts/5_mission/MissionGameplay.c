modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();
		GetRPCManager().AddRPC( "SHTHP", "RPCSnapHeliToHeliPadSettings", this, SingeplayerExecutionType.Both );
	}
	
	void RPCSnapHeliToHeliPadSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< SnapHeliSettings > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_SnapHeliSettings = data.param1;
	}
}